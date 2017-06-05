//容斥解决重复计算，求重叠的最小公倍数
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,num;
ll a[55];
ll ans;
/*
ll op()
{
    ll sum=0;
    for(ll i = 1;i<(1<<num);i++)
    {
        ll mul=1,cnt=0;
        for(ll j=0;j<num;j++)
        {
            if(i&(1<<j))
            {
                mul = a [j]/__gcd(a[j],mul)*mul;
                cnt ++;
            }
        }
        if(cnt&1) sum += n/mul;
        else sum -= n/mul;
    }
    return sum;
}
*/
void dfs(int th,ll now,int step)//265MS
{
    if(step>num) return;
    ll lcm = now/__gcd(now,a[th])*a[th];
    if(step&1) ans+=n/lcm;
    else ans-=n/lcm;
    for(int p=th+1;p<num;p++)
        dfs(p,lcm,step+1);
}
/* //位运算的容斥 998MS
int main()
{
    while(scanf("%lld%lld",&n,&m)!=EOF)
    {
        n--;ll x;
        num=0;
        for(ll i=0;i<m;i++)
        {
            scanf("%lld",&x);
            if(x)
                a[num++] = x;
        }
        printf("%lld\n",op());
    }
    return 0;
}*/
//dfs的容斥
int main()
{
    while(scanf("%lld%lld",&n,&m)!=EOF)
    {
        n--;num=ans=0;
        for(ll i=0;i<m;i++)
        {
            ll x;
            scanf("%lld",&x);
            if(x)
                a[num++]=x;
        }
        for(int i=0;i<num;i++)
            dfs(i,a[i],1);
        printf("%lld\n",ans);
    }
    return 0;
}
