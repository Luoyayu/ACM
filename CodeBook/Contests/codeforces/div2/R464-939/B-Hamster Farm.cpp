#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;
const int maxn = 1e5 + 7;

int main() {
    ll n, k;
    scanf("%lld %lld", &n, &k);
    ll ans = 1e18, ANS = 1e18;
    int idx = -1;
    for (int i = 1; i <= k; i++) {
        ll x; scanf("%lld", &x);
        if (n % x < ans) ans = n % x, ANS = x, idx = i;
    }
    return !printf("%d %lld\n", idx, n / ANS);
}