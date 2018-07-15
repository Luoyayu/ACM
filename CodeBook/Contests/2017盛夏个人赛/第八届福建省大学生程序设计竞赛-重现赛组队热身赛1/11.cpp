#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 10000+7;
typedef long long ll;
ll d[maxn]={1,1,2};
ll p[maxn]={1,0,1};
const int mod = 1e9+7;
void init()
{
    for(int i=3;i<=maxn;i++)
        d[i]=((d[i-1]*i)%mod),p[i]=((i-1)*(p[i-1]+p[i-2]))%mod;
}
ll ex_gcd(ll a,ll b,ll &x,ll &y)
{
    if(!b)
    {
        x=1;y=0;return a;
    }
    ll ret=ex_gcd(b,a%b,y,x);
    y-=a/b*x;
}
ll C(ll n,ll m)
{
    ll x,y;
    ll pp=d[n]*d[m-n];
    ex_gcd(pp,mod,x,y);
    x=(x>0?x:(x%mod+mod)%mod);
    return (d[m]*x)%mod;
}

int main()
{
    init();
    int t;scanf("%d",&t);
    while(t--)
    {
        ll n,k;
        scanf("%I64d%I64d",&n,&k);
        ll ans = 0;
        for(ll i=k;i<=n;i++)
            ans = (ans + ((C(i,n)%mod)*(p[n-i]%mod))%mod)%mod;
        printf("%I64d\n",(ans)%mod);
    }
    return 0;
}
