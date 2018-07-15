#include <bits/stdc++.h>
//分块 518ms 其实是 前缀异或 XOR[r] ^ XOR[l-1]
// XOR 的性质 a ^ a = 0 ; a ^ 0 = a;
// q*sqrt(n) + O(n)
using namespace std;
const int maxn = 1e5 + 7;
int a[maxn];
int belong[maxn];
int block, num;
int l[maxn], r[maxn];
int XOR[maxn];
int n, q;
inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
// sqrt(1e5) = 316
void build() {
    memset(XOR, 0, sizeof(XOR));
    block = sqrt(n + 0.5);
    num = n / block;
    if (n % block) num++;

    for (int i = 1; i <= num; i++) l[i] = (i - 1) * block + 1, r[i] = i * block;
    r[num] = n;

    for (int i = 1; i <= n; i++) belong[i] = (i - 1) / block + 1;

    for (int i = 1; i <= num; i++) {
        for (int j = l[i]; j <= r[i]; j++) XOR[i] ^= a[j];
    }
}

int ask(int x, int y) {
    int ans = 0;
    if (belong[x] == belong[y]) {
        for (int i = x; i <= y; i++) ans ^= a[i];
        return ans;
    }

    for (int i = x; i <= r[belong[x]]; i++) ans ^= a[i];

    for (int i = belong[x] + 1; i <= belong[y] - 1; i++) ans ^= XOR[i];

    for (int i = l[belong[y]]; i <= y; i++) ans ^= a[i];

    return ans;
}

void update(int x, int d)  //修改某位置的异或值
{
    int tmp = a[x];
    a[x] = d;
    XOR[belong[x]] ^= (tmp ^ d);
}

int main() {
    int t = read();
    while (t--) {
        n = read();
        for (int i = 1; i <= n; i++) a[i] = read();
        build();
        q = read();
        while (q--) {
            int l = read(), r = read();
            if (l == r)
                printf("%d\n", a[l]);
            else
                printf("%d\n", ask(l, r));
        }
    }
    return 0;
}