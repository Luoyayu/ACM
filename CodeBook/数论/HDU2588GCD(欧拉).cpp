//好题,深入理解欧拉本质
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define scd(x) scanf("%d",&x)
#define scll(x,y) scanf("%lld %lld",&x,&y)
#define ptd(x) printf("%d\n",x)
/*题意:求gcd(X,N)>=M 且1<=X<=N;
* 发现X只能是N的因子,似乎可以枚举瞎N的因子,那么问题就转换为
* 在1~N内有多少N的因子X满足 gcd(X,N)=X>=M 
* 因为gcd(X,N)=X>=M 设y=N/X 记与y互质的数为p1,p2,p3...pn, 可得gcd(X*pn,N)>=M 则即求小于等于N/X且与其互质的数的个数
* 由此可得求x个数<=>求 N/X的欧拉函数值之和
*/
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
        ll n, m, ans = 0; scll(n, m);
        for(int x=1; x*x<=n; x++) if(n%x==0)//枚举N的约数P
        {
            if(x>=m) //加速枚举,比如n=12 (1,2,3,4,6,12) 当 x=1 时同时搞 1 和 12 x=2时搞 2和 6
                ans += euler(n/x);

            if( (n/x)>=m && (n/x)!=x)//判断是否为平方数
                ans += euler(x);
        }
        ptd(ans);
    }
    return 0;
}
