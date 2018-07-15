#include <bits/stdc++.h>
//快速乘+组合数学+快速幂
//题意：定义完美序列a1~ai严格递增/递减 ai~an严格递增/递减
//存在一个ai即是完美序列,1~n
//答案显然 C(0,n)+...C(n,n)=2^n-2
typedef long long ll;
const int maxn = 1e6 + 7;
using namespace std;
ll qmul(ll a, ll b, ll mod)  // O(1) 快速乘法
{
    ll ret = 0, k = a, sig = 1;
    if (k < 0) sig = -1, k = -k;
    if (b < 0) sig *= -1, b = -b;
    while (b) {
        if (b & 1) ret = (ret + k) % mod;
        k = (k + k) % mod, b >>= 1;
    }
    return ret * sig;
}

inline ll mul(ll x, ll y, ll mod)  //普通乘法爆long long
{
    return 1ll * x * y % mod;
}

ll power_mod(ll x, ll y, ll p) {
    ll ret = 1;
    while (y) {
        if (y & 1) ret = qmul(ret, x, p);
        x = qmul(x, x, p);
        y >>= 1;
    }
    return ret;
}
int main() {
    ll n, p;
    while (scanf("%lld%lld", &n, &p) != EOF) {
        printf("%lld\n",
               (power_mod(2, n, p) - 2 + p) % p);  //虽然只是减2还是要细心点
    }
    return 0;
}