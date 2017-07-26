#include <bits/stdc++.h>
//找规律
using namespace std;
typedef  long long ll;
int main()
{
    ll n,k;int kase=1;
    //1~n 1~n-1 [1~n-2,n] 1~n-1 [1~n-2,n]
    while(scanf("%lld%lld",&n,&k)!=EOF)
    {
        ll ans = 0;
        if(k <=n)
            ans = k;
        else
        {
            k-=n;
            ll a = k%(2*n-2);
            if(a==0) a=2*n-2;
            if(a<n-1) ans = a;
            else if(a==n-1) ans= n-1;
            else if(a==2*n-2) ans = n;
            else ans=a-(n-1);
        }
        printf("Case #%d: %lld\n",kase++,ans);
    }
    return 0;
}