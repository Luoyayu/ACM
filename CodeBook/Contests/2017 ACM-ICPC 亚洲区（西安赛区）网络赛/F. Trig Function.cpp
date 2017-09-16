#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
typedef long long ll;
ll pow_mod(ll a, ll b, ll p) //a^(p-2)%p
{
    ll ret = 1;
    while(b)
    {
        if(b&1) ret=(ret*a)%p;
        a=(a*a)%p;
        b>>=1;
    }
    return ret;
}

inline ll Fermat(ll a,ll p)//求a关于p的逆元
{
    return pow_mod(a,p-2,p);
}
int main()
{
    ll n,m;
    while(scanf("%lld%lld",&n,&m)!=EOF)
    {
        ll ans=n,js=1, flag = 1;
        if(m==0)
        {
            if(n&1) ans=0;
            else ans=(n%4==0?1:-1);
            printf("%lld\n",(ans+mod)%mod);
            continue;
        }
        else
        {
            if(n%2==0&&m%2==1||n%2==1&&m%2==0||m>n) printf("0\n");
            else
            {
                for(ll i=n+m-2;i>n-m;i-=2) ans=ans*i%mod;
                for(ll i=1;i<=m;i++) js=js*i%mod;
                ll x = Fermat(js,mod);
                ans = ans * x % mod;
                flag=((abs(n-m)>>1)%2==1?-1:1);
                printf("%lld\n",(ans*flag+mod)%mod);
            }
        }

    }
    return 0;
}