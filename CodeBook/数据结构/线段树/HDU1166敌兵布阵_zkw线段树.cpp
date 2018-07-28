// zwk???
#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
int T[N << 2], M;
void pushup(int i) { T[i] = T[i << 1] + T[i << 1 | 1]; }
void build(int n) {
    for (M = 1; M <= n + 1; M <<= 1)
        ;
    for (int i = M + 1; i <= M + n; i++) scanf("%d", &T[i]);
    for (int i = M - 1; i > 0; i--) pushup(i);
}
void add(int n, int v) {
    for (T[n += M] += v, n >>= 1; n; n >>= 1) pushup(n);
}
int query(int s, int t) {
    int ans = 0;
    for (s = s + M - 1, t = t + M + 1; s ^ t ^ 1; s >>= 1, t >>= 1) {
        if (~s & 1) ans += T[s ^ 1];
        if (t & 1) ans += T[t ^ 1];
    }
    return ans;
}

int main() {
    char str[15];
    int t, n;
    scanf("%d", &t);
    for (int kase = 1; kase <= t; kase++) {
        printf("Case %d:\n", kase);
        memset(T, 0, sizeof T);
        scanf("%d", &n);
        build(n);
        while (1) {
            scanf("%s", str);
            if (str[0] == 'E') break;
            int a, b;
            scanf("%d %d", &a, &b);
            if (str[0] == 'A')
                add(a, b);
            else if (str[0] == 'Q')
                printf("%d\n", query(a, b));
            else if (str[0] == 'S')
                add(a, -b);
        }
    }
    return 0;
}
