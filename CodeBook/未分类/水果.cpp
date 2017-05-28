//完全背包
#include<bits/stdc++.h>
using namespace std;
int dp[1000];
int c[3],w[3];
int main()
{
    int V;
    ios::sync_with_stdio(false);
    while(cin>>V)
    {
        cin>>c[1]>>w[1]>>c[2]>>w[2];
        memset(dp,-1,sizeof dp);
        dp[0]=0;
        for(int i=1;i<=2;i++)
            for(int v=c[i];v<=V;v++)
                dp[v]=max(dp[v],dp[v-c[i]]+w[i]);
        printf("%d\n",dp[V]);

    }
    return 0;
}
