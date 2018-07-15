//排序前缀和
#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;
typedef long long LL;
int n, m, C;
LL a[maxn];
int main() {
    while (scanf("%d%d%d", &n, &m, &C) != EOF) {
        memset(a, 0, sizeof a);
        for (int i = 1; i <= n; i++) scanf("%lld", &a[i]), a[i] += a[i - 1];
        sort(a, a + n + 1);  // a+n+1
        LL sum = 0;
        for (int i = 0; i < m; i++) {
            if (abs(a[n - i] - a[i]) > C)
                sum += abs(a[n - i] - a[i]) - C;
            else
                break;
        }
        printf("%lld\n", sum);
    }
    return 0;
}
