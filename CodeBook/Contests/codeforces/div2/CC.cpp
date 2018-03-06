
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int maxn=1e5+7;
ll  it[maxn];
ll ans[maxn];
int n,s;
ll res(ll k)
{
    for(int i=1;i<=n;i++)
        ans[i]=it[i]+i*(ll)k;
    sort(ans+1,ans+n+1);
    ll ret=0;
    for(int i=1;i<=k;i++)
        ret += ans[i];
    return ret;
}
int main()
{
    scanf("%d %d",&n,&s);
    for(int i=1;i<=n;i++)
        cin>>it[i];
    ll l=0,r=n+1,mid;
    while(l<r-1)
    {
        mid=(l+r)/2;
        if(res(mid)<=s)
            l = mid;
        else
            r = mid;
    }
    cout<<l<<' '<<res(l)<<endl;
    return 0;
}
