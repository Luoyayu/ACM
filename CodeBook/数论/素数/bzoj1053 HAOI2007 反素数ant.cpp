///求不超过N的最大反素数
///正整数x,约数的个数g(x),满足对任意0<i<x,g(i)<g(x),x为反质数。
///反质数性质:肯定有2这个质因子，而且质分解后小质数的幂次最大，然后依次类推;
///对于1~n内的数的因子个数不规律，所求就是在某区间约数最大的那个数
///思路:取小质数暴搜,显然前20个质数相乘乘积超过20亿，
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
ll ans, n;
const ll INF = 0x3f3f3f3f;
int best;
void dfs(int dep, ll tmp, int num)  /// num记录因子个数
{
    if (dep == 16) return;
    if (num > best)  /// update best
    {
        best = num;
        ans = tmp;
    }
    if (num == best) ans = min(tmp, ans);  ///因子数相同时取最小的
    for (int i = 1; i <= 62; i++)          //递归层数
    {
        if (n / prime[dep] < tmp) break;  //剪枝
        dfs(dep + 1, tmp *= prime[dep], num * (i + 1));
    }
}
int main() {
    while (scanf("%lld", &n) != EOF) {
        ans = INF;
        best = 0;
        dfs(0, 1, 1);
        printf("%lld\n", ans);
    }
    return 0;
}
