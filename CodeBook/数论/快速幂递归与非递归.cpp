//cal a^b%mod
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

ll power_mod(ll a,ll b,ll mod)
{
    ll ans=1,tmp=a%mod;
    while(b)
    {
        if(b&1)
            ans=ans*tmp%mod;

        tmp=tmp*tmp%mod;
        b>>=1;
    }
    return ans;
}
int main()
{
    ll a,b,mod;
    scanf("%lld%lld%lld",&a,&b,&mod);
    printf("%lld\n",power_mod(a,b,mod));
}
