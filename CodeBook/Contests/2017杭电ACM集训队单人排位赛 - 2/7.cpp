#include<bits/stdc++.h>
#define Debug(dp) cout<<#dp<<"="<<dp<<endl;
using namespace std;
const int maxn=1e5+7;
int dp[maxn];
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&dp[i]);
        int ans,st;
        ans=st=dp[1];

        for(int i=2;i<n;i+=2)
            st+=(dp[i]+dp[i+1]), st=max(st,dp[i+1]), ans=max(ans,st);
        //
        st=dp[2];
        for(int i=3;i<n;i+=2)
            st+=(dp[i]+dp[i+1]), st=max(st,dp[i+1]), ans=max(ans,st);
        printf("%d\n",ans);
    }
    return 0;
}
