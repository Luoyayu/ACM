//题意：判断序列是否是长度大于n-1的非严格单调子序列
#include <bits/stdc++.h>
const int maxn = 100100, inf = 0x3f3f3f3f;
int a[maxn], b[maxn], dp[maxn];
int L(int *v, int n) {
    memset(dp, inf, sizeof(dp));
    for (int i = 0; i < n; i++)
        *std::upper_bound(dp, dp + n, v[i]) = v[i];  //严格单调递增子序列此处是lower_bound()，非严格是upper_bound()
    return (std::lower_bound(dp, dp + n, inf) - dp >= n - 1);
}
int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%d", a + i), b[n - i - 1] = a[i];
        if (L(a, n) + L(b, n))puts("YES");
        else puts("NO");
    }
}