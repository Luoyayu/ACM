//好题深入理解欧拉本质
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define scd(x) scanf("%d",&x)
#define scl(x) scanf("%lld",&x)
#define scll(x,y) scanf("%lld %lld",&x,&y)
#define ptd(x) printf("%d\n",x)
/*题意:求gcd(X,N)>=M 且1<=X<=N;
* 发现X只能是N的因子,似乎可以枚举瞎N的因子,那么问题就转换为
* 于是 gcd(X,N) = X;
* 在1~N内有多少N的因子满足gcd(X,N)=P>=M
* 1) 观察一满足条件的X,因为gcd(X,N)=P>=M 所以有X/P 与 N/P 互质(不互质的话显然P不是gcd)
* 2) 又由X<=N 有 X/P<=N/P
* 由此可得求X 的个数就是求不大于N/P的且与其互质的数的个数<=>求 N/p的欧拉函数值
*/
ll n,m;
ll euler(ll x)
{
    ll res = x;
    for(int i=2; i*i<=x; i++) if(x%i==0)
    {
        res = res / i * (i-1);
        while(x%i==0) x /= i;
    }
    if(x>1) res = res / x * (x-1);
    return res;
}
int main()
{
    int t;scd(t);
    while(t--)
    {
        scll(n,m);
        ll ans = 0;
        int nn = int(sqrt(n));
        for(int p=1; p<=nn; p++) if(n%p==0)
        {//枚举N的约数P
            if(p>=m)
                ans += euler(n/p);

            if((n/p)>=m && (n/p)!=p)//判断是否为平方数??????
                ans += euler(p);
        }
        ptd(ans);
    }
    return 0;
}
