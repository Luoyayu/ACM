#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5+10;
ll a[maxn],b[maxn];
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        ll n;scanf("%lld",&n);
        for(int i = 1;i<=n;i++)
            scanf("%lld", &a[i]);
        ll ans = 0;
        for(ll i = 1;i<=n;i++)
        {
            b[a[i]] = i;
            ans += (n-i+1)*(i-1);
        }
        for(ll i = 1;i<n;i++)
        {
            ll first = b[i],last = b[i+1];
            if(first > last)
                swap(first, last);
            ans -= first*(n-last+1);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
