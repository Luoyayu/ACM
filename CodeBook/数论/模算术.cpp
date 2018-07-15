#include <cstdio>
typedef unsigned long long ull;
/// a ^p % n
ull pow_mod(ull a, ull p, ull n) {
    if (!p) return 1;
    ull ans = pow_mod(a, p >> 1, n);
    ans = (ans % n) * (ans % n) % n;
    if (p & 1) ans = (ans % n) * (a % n) % n;
    return ans;
}
ull power_mod(ull a, ull b, ull mod) {
    ull ans = 1, base = a % mod;
    while (b) {
        if (b & 1) ans = ans * base % mod;
        base = base * base % mod;
        b >>= 1;
    }
    return ans;
}
int main() {
    ull a, p, n;
    scanf("%lld%lld%lld", &a, &p, &n);
    printf("%lld\n", pow_mod(a, p, n));
    printf("%llu\n", power_mod(a, p, n));
    return 0;
}
