///sum(n)=n*phi(n)/2;
#include<cstdio>
#include<cmath>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const ll INF = 1LL << 66;
ll euler_phi(ll n)
{
    ll m = (ll)sqrt(n+0.5);
    ll ans = n;
    for(ll i=2;i<=m;i++)
        if(n%i==0)
        {
            ans=ans/i*(i-1);
            do n/=i;
            while(n%i==0);
        }
    if(n>1) ans=ans/n*(n-1);
    return ans;
}
int main()
{
    ll n;
    /*
    while(scanf("%lld",&n)&&n)
    {
        ll sum=n*(n-1)/2;
        ll corSum=n*euler_phi(n)/2;
        printf("%lld\n",(sum-corSum)%mod);
    }
    */printf("%lld\n",INF);
    return 0;
}
