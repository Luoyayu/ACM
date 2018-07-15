#include <bits/stdtr1c++.h>

using namespace std;
const int mod = static_cast<const int>(1e9 + 7);
const int maxn = 2222;
typedef long long ll;

int a[maxn];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        ll k, m, t;  // k, m to dead
        scanf("%lld %lld %lld", &k, &m, &t);
        memset(a, 0, sizeof(a));
        a[0] = 1;
        for (int i = 1; i <= t; i++) {
            ll st = i - m + 1;
            for (ll j = max(st, 0LL); j <= i - k; j++)
                a[i] = (a[i] % mod + a[j] % mod) % mod;
        }
        ll ans = 0;
        ll st = t - m + 1;
        for (ll i = max(st, 0LL); i <= t; i++)
            ans = (ans % mod + a[i] % mod) % mod;
        printf("%lld\n", ans);
    }
}