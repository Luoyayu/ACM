#include <bits/stdc++.h>
using namespace std;
typedef long long  LL;
const int maxn=1e5+10;
const int INF=0x3f3f3f3f;
const int MAXN=100010;
int a[MAXN],dp[MAXN];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k;
        int ans1,ans2;
        scanf("%d %d",&n,&k);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        memset(dp,INF,sizeof(dp));

        for(int i=1;i<=n;i++)
            *lower_bound(dp+1,dp+n+1,a[i])=a[i];
        ans1=lower_bound(dp+1,dp+n+1,INF)-(dp+1);
        for(int i=1;i<=n;i++)
            a[i]=-a[i];
        
        memset(dp,INF,sizeof(dp));
        for(int i=1;i<=n;i++)
            *lower_bound(dp+1,dp+n+1,a[i])=a[i];
        ans2=lower_bound(dp+1,dp+n+1,INF)-(dp+1);
        //cout<<ans1<<" "<<ans2<<endl;
        if(ans1+k>=n||ans2+k>=n) printf("A is a magic array.\n");
        else printf("A is not a magic array.\n");

    }

    return 0;
}