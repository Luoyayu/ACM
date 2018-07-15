#include <bits/stdc++.h>
//返回单个数的质因子
using namespace std;
typedef long long ll;
const int maxn = 1000;
ll a[maxn];  //储存n的第i个质因子
int main() {
    ll n;
    while (scanf("%I64d", &n) != EOF) {
        ll num = 0;
        for (ll i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                a[num++] = i;
                while (!(n % i)) n /= i;
            }
        }
        if (n > 1) a[num++] = n;
        for (ll i = 0; i < num; i++) printf("%lld ", a[i]);
        printf("\n");
    }
    return 0;
}
