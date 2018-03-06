// 题意: 有一个长度为n的数组a,和整数c
// 我们定义 array a with c value= \sum_{i=1}^{len(a)} a_i (expect for floor(k/c) smallest)
// like [1,2,3,5,6] with c is 3+5+6=14
// 现在要找到一种对于数组a的划分,使得他们的value sum最小
// trick: 我们可知从c位置开始的划分是有意义的,否则我们可以对元素一一划分,
// 所以考虑长度为c的一块, 设dp[i]为,到i位置的最优划分,
// 有转移方程dp[i]=min(dp[i-1], dp[i-c]-min_{i-c<=j<=i}a_i+\sum_{j=c}^{i}a_j)
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = int(1e5 + 7);
ll a[maxn], dp[maxn];
int n, c;

int main() {
    while (scanf("%d %d", &n, &c) != EOF) {
        multiset<ll> ms;
        ll sum = 0;
        for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            ms.insert(a[i]);
            dp[i] = dp[i - 1] + a[i];
            sum += a[i];
            if (i > c) {
                ms.erase(ms.find(a[i - c]));
                sum -= a[i - c];
            }
            if (i >= c)
                dp[i] = min(dp[i], dp[i - c] + sum - *ms.begin());
        }
        printf("%lld\n", dp[n]);
    }
}