// 题意: 给出n,k,A,B
// 有两种操作:
// 1. --n, 每次操作cost A
// 2. n /= k, if(n%k==0) ,每次cost B
// cal MINcost making n to 1
// trick: 如果k==1 只能输出(n-1LL)*A
// 要么n每次变成k的倍数,比较自减cost和
#include <bits/stdc++.h>

using namespace std;
const int inf = 0x3f3f3f3f;
typedef long long ll;
int n, k, A, B;
ll ans;
int main() {
    while (scanf("%d %d %d %d", &n, &k, &A, &B) != EOF) {
        ll ans = (n - 1LL) * A; // all use --n cost
        ll pre_need = 0;
        if (k == 1) {
            printf("%lld\n", ans);
            continue;
        }
        while (n > 1) { // to n->1, need n->w*k+(n-w*k)
            ll tmp = n / k;
            if (tmp < 0) break;
            pre_need += (n - tmp * k) * A + B;
            n /= k;
            ans = min(ans, pre_need + (n - 1LL) * A); //notice: 1LL
        }
        printf("%lld\n", ans);
    }
}