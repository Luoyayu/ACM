//题意：给出每个项目需要完成的时间，以及每一秒增加的人数。求所有项目完成的最少的时间
//贪心排序 对于 a1,b1 ,a2,b2; 如果先选1 则耗时为a1 + b2 * a1 + a2 ;如果选2则 耗时a1 + a2 * b1+ a2  观察可知对于b2*a1 和 b1*a2排序即可
/*
5
1 2
2 3
3 4
4 5
5 6
0
*/

#include<bits/stdc++.h>
using namespace std;
const int maxn = 100005;
typedef long long ll;
const ll mod = 365*24*60*60;
struct node
{
    ll a,b;
    bool operator <(const node &y)
    {
        return a * y.b < b * y.a;
    }
}p[maxn];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF,n)
    {
        for(int i=1;i<=n;i++)
            scanf("%lld%lld",&p[i].a,&p[i].b);
        sort(p+1, p+n+1);
        ll ans = 0;
        for(int i=1;i<=n;i++)
            ans += (p[i].a+p[i].b*ans%mod)%mod;
        printf("%lld\n",ans%mod);
    }
    return 0;
}