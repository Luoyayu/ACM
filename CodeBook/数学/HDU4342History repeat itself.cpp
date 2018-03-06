//题意求第n个非完全平方数m以及Σ(m,i=1) |_sqrt(i)_|
//在1~m中设有x个完全平方数,则有m=x+n x^2<m (x+1)^2>=m
//等价于求m-sqrt(m)<n的最大m,
//预处理sqrt(i)的前缀和
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 1ll<<16;
ll n,x,ans,a[maxn];
int main()
{
    for(int i=1;i<=maxn;i++)
        a[i]=a[i-1]+ll(i*2+1)*i;//预处理|_sqrt(i)_|前缀和

    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);

        ll l=1,r=1ll<<32;
        while(l<r)
        {
            ll m = l+r>>1;
            if(m-ll(sqrt(m))<n)
                l= m + 1;
            else
                r = m;
        }
        x = l;

        ll g = floor(sqrt(x));
        ans = a[g-1]+(x-g*g+1)*g;
        printf("%lld %lld\n",x,ans);

        ll ANS = floor((2+sqrt(1+4*n))/2.0)-1;
        printf("ANS: %lld\n",ANS);
    }
    return 0;
}
