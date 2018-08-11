#include <bits/stdtr1c++.h>

using namespace std;
// 题意: 给出n,让你找三个数都能整除n,且x+y+z=n,且x*y*z最大
// 思路: 对于偶数能满足三个数都能整除n, 一定是n/2+n/4+n/4=n;
//       对于奇数一定是n/3+n/3+n/3=n;

int main() {
    int t; scanf("%d", &t);
	while (t--) {
        int n; scanf("%d", &n);
        if (n % 3 == 0) {  // 是3的倍数
            printf("%lld\n", n / 3LL * (n / 3LL) * (n / 3LL));
        } else if (n % 4 == 0) {  // 是4的倍数
            printf("%lld\n", n / 2LL * (n / 4LL) * (n / 4LL));
        } else puts("-1");
    }
}
