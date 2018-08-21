#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll prime[] = {2, 3, 5, 7};
int cnt = 4;
long long bit_op(ll m) {
    ll ret = 0;
    for (int i = 1; i < (1 << cnt); i++) {
        int mulSum = 1, tot = 0;
        for (int j = 0; j < cnt; j++) {
            if (i & (1 << j)) {
                tot++;
                mulSum *= prime[j];
            }
        }
        if (tot & 1)
            ret += m / mulSum;
        else
            ret -= m / mulSum;
    }
    return ret;
}
int main() {
    int t;
    scanf("%d", &t);
    for (int kase = 1; kase <= t; kase++) {
        scanf("%lld", &n);
        printf("%lld\n", bit_op(n));
    }
    return 0;
}
