#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 19940417;
const ll inv = 3323403;
inline ll sum(ll a,ll b)
{
    return (a+b)*(b-a+1)/2%mod;
}
ll cal(ll n)
{
    ll tmp=0;
    ll left, right;
    for(ll i=1;i<=n;i=right+1)
    {
        left = i;
        right=n/(n/i);
        tmp=(tmp+ n*(right-left+1)%mod - (n/i)*sum(left,right))%mod;
    }
    return (tmp+mod)%mod;
}
ll sum2(ll x)
{
    return x*(x+1)%mod*(2*x+1)%mod*inv%mod;// sigma (i~n) = n*(n+1)*(2*n+1)/6 在数论中不能瞎除要乘以逆元
    ///使用扩欧算的 6对于mod的逆元是3323403
}
int main()
{
    ll n,m,ans=0;
    scanf("%lld %lld",&n,&m);
    ans = cal(n)*cal(m)%mod;
    if(n>m) swap(n,m);
    ll s1,s2,s3;
    ll right,left;
    for(ll i=1;i<=n;i=right+1)
    {
        left = i;
        right = min(n/(n/i),m/(m/i));

        s1 = n*m%mod * (right - left +1)%mod;
        s2 = (n/i)*(m/i)%mod * (sum2(right)-sum2(left-1)+mod)%mod;
        s3 = (n/i*m + m/i*n)%mod *sum(left,right)%mod;
        ans=(ans-(s1+s2-s3)%mod+mod)%mod;
    }
    printf("%lld\n",ans);
    return 0;
}
