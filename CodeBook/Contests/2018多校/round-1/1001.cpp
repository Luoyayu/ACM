#include <bits/stdtr1c++.h>

using namespace std;
// 题意: 给出n,让你找三个数能整除n,且x+y+z=n,且x*y*z最大
// 思路: 显然对于2n,
// 找n*n最大，奇数的话只有n%3==0才能构成x*y*z=(n/3)^3当然这其中也包含一些偶数能构成
// 乘积最大； 对于偶数的话，本身满足能被2整除，但是像14, 22,
// 这种特殊的偶数他们的因子都得是2的倍数，所以2*2=4，另外两个数是n/4,才能基本满足三个数整除n，这样构造的话其实也是最大化的x*y*z
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        if (n % 3 == 0) {  // 是3的倍数
            printf("%lld\n", n / 3LL * (n / 3LL) * (n / 3LL));
        } else if (n % 4 == 0) {  // 是2且4的倍数
            printf("%lld\n", n / 2LL * (n / 4LL) * (n / 4LL));
        } else
            printf("-1\n");
    }
}