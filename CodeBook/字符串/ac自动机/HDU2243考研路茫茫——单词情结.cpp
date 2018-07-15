#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;  //自动取模
//题意:给出词根求不超过L的所有满足字符串的数量%mod
char buf[6][6];
#define Size 26
struct matrix {
    ll mat[44][44];
    int n;
    matrix() {}
    matrix(int _n) : n(_n) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) mat[i][j] = 0;
    }

    matrix operator*(const matrix &b) const {
        matrix ret = matrix(n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++)
                    ret.mat[i][j] += (mat[i][k] * b.mat[k][j]);
        return ret;
    }
};
struct Trie {
    int son[44][Size], fail[44];
    bool end[44];
    int root, L;
    int newnode() {
        for (int i = 0; i < Size; i++) son[L][i] = -1;
        end[L++] = 0;
        return L - 1;
    }
    void init() {
        L = 0;
        root = newnode();
    }
    void insert(char *buf, int idx) {
        int now = root, i = 0, w;
        for (; *buf; buf++) {
            if (son[now][w = *buf - 'a'] == -1) son[now][w] = newnode();
            now = son[now][w];
        }
        end[now] = 1;
    }
    void build() {
        queue<int> Q;
        fail[root] = root;
        for (int i = 0; i < Size; i++)
            if (son[root][i] == -1)
                son[root][i] = root;
            else {
                fail[son[root][i]] = root;
                Q.push(son[root][i]);
            }
        while (!Q.empty()) {
            int now = Q.front();
            Q.pop();
            for (int i = 0; i < Size; i++)
                if (son[now][i] == -1)
                    son[now][i] = son[fail[now]][i];
                else {
                    fail[son[now][i]] = son[fail[now]][i];
                    Q.push(son[now][i]);
                }
        }
    }
    matrix getM() {
        matrix ret = matrix(L + 1);
        for (int i = 0; i < L; i++)
            for (int j = 0; j < 26; j++)
                if (!end[son[i][j]]) ret.mat[i][son[i][j]]++;
        for (int i = 0; i < L + 1; i++) ret.mat[i][L] = 1;
        return ret;
    }
} ac;
matrix pow_mod(matrix &a, int n) {
    matrix ret = matrix(a.n), tmp;
    for (int i = 0; i < a.n; i++) ret.mat[i][i] = 1;
    tmp = a;
    while (n) {
        if (n & 1) ret = ret * tmp;
        tmp = tmp * tmp;
        n >>= 1;
    }
    return ret;
}
int main() {
    ll n;
    int l;
    while (scanf("%lld%d", &n, &l) != EOF) {
        ac.init();
        for (int i = 1; i <= n; i++) scanf("%s", buf[i]), ac.insert(buf[i], i);
        ac.build();
        matrix a = ac.getM();
        a = pow_mod(a, l);
        ll res = 0;
        for (int i = 0; i < a.n; i++) res += a.mat[0][i];
        res--;
        a = matrix(2);
        a.mat[0][0] = 26;
        a.mat[1][0] = a.mat[1][1] = 1;
        a = pow_mod(a, l);
        ll ans = a.mat[1][0] + a.mat[0][0];
        ans--;
        ans -= res;
        cout << ans << endl;
    }
    return 0;
}