#include <bits/stdtr1c++.h>

using namespace std;
const int maxn = 1e6 + 7;
typedef long long ll;
ll a[maxn];
ll csum[maxn];

int main() {
    int t;
    scanf("%d", &t);
    for (int kase = 1; kase <= t; kase++) {
        ll n, v;
        scanf("%lld %lld", &n, &v);
        ll sum = 0, ans = -1;
        csum[0] = 0;
        for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; i++) csum[i] = csum[i - 1] + a[i];

        if (csum[n] < v) goto L;

        for (ll i = 1; i <= n; i++) {
            ll len = min(i - 1, n - i); // i-len-1 ~ i    n-len-1 ~n || n-len ~ len(if n-i!=len)
            ll suml = csum[i] - csum[i - len - 1];
            // 特判
            ll sumr = n - i != len ? csum[n] - csum[n - len - 1] : csum[n] - csum[n - len];
            if (suml + sumr >= v) {
                ans = a[i];
                goto L;
            }
        }
        L:
        printf("Case #%d: %lld\n", kase, ans);

    }
}