// HDU最短代码 442B 2017年9月14日
//题意：判断序列是否是长度大于n-1的非严格单调子序列
#include <bits/stdc++.h>
const int maxn = 100100, inf = 0x3f3f3f3f;
int a[maxn], b[maxn], n, p[maxn], t;
int L(int *v) {
    memset(p, inf, sizeof(p));
    for (int i = 0; i < n; i++)
        *std::upper_bound(p, p + n, v[i]) = v[i];  //严格单调递增子序列此处是lower_bound()，非严格是upper_bound()
    return (std::lower_bound(p, p + n, inf) - p >= n - 1);
}
int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%d", a + i), b[n - i - 1] = a[i];
        if (L(a) + L(b))puts("YES");
        else puts("NO");
    }
}