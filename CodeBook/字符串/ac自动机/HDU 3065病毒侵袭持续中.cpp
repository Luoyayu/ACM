#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010 * 50;
const int Size = 128;
char vir[1010][51];
char txt[2000002];
int cnt[1010];
struct Trie {
    int son[maxn][Size];
    int fail[maxn], end[maxn];
    int root, TOT;
    int newnode() {
        for (int i = 0; i < Size; i++) son[TOT][i] = -1;
        end[TOT++] = 0;
        return TOT - 1;
    }
    void init() {
        TOT = 0;
        root = newnode();
    }
    void insert(char *buf, int idx) {
        int x = root, i = 0, w;
        for (; *buf; buf++) {
            if (son[x][w = *buf] == -1) son[x][w] = newnode();
            x = son[x][w];
        }
        end[x] = idx;
    }
    void build() {
        queue<int> Q;
        fail[0] = 0;
        for (int i = 0; i < Size; i++) {
            int &v = son[0][i];
            if (v == -1)
                v = 0;
            else
                fail[v] = 0, Q.push(v);
        }
        while (!Q.empty()) {
            int x = Q.front();
            Q.pop();
            for (int i = 0; i < Size; i++) {
                int &v = son[x][i];
                if (v == -1)
                    v = son[fail[x]][i];
                else
                    fail[v] = son[fail[x]][i], Q.push(v);
            }
        }
    }
    void find(char *buf) {
        for (int x = 0; *buf; buf++) {
            x = son[x][*buf];
            for (int last = x; last; last = fail[last])
                if (end[last] != -1) cnt[end[last]]++;
        }
    }
} ac;
int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        ac.init();
        for (int i = 1; i <= n; i++) scanf("%s", vir[i]), ac.insert(vir[i], i);
        ac.build();
        for (int i = 1; i <= n; i++) cnt[i] = 0;
        scanf("%s", txt);
        ac.find(txt);
        for (int i = 1; i <= n; i++)
            if (cnt[i]) printf("%s: %d\n", vir[i], cnt[i]);
    }
    return 0;
}