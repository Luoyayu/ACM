///k-bit系统 有趣
///mod == 2^k
///=> C=(B-A+2^k)%2^k/C;
///=> Cx==(B-A)(mod 2^k)
///另C=a; b=B-A n=2^k
///=> ax==b(mod n);
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
typedef long long ll;
ll ex_gcd(ll a,ll b,ll &x,ll &y)
{
    if(!b)
    {
        x=1;y=0;
        return a;
    }
    ll ans=ex_gcd(b,a%b,y,x);
    y-=a/b*x;
    return ans;
}
int main()
{
    ll A,B,C,k;
    while(scanf("%lld%lld%lld%lld",&A,&B,&C,&k)!=EOF)
    {
        if(!A&&!B&&!C&!k)
            break;
        ll a=C,b=B-A,n=(ll)1<<k;
        ll x,y;
        ll gcd=ex_gcd(a,n,x,y);
        ll tmp=n/gcd;
        if(b%gcd)
            printf("FOREVER\n");
        else
        {
            x=(b/gcd*x)%n;
            x=(x%tmp+tmp)%tmp;
            printf("%lld\n",x);
        }
    }
    return 0;
}
