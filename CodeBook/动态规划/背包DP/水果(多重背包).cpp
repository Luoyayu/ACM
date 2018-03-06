#include<bits/stdc++.h>
//多重背包
using namespace std;
int dp[1000009];
int c[3],w[3];
int main()
{
    int V;
    while(scanf("%d",&V)!=EOF)
    {
        scanf("%d %d %d %d",&c[1],&w[1],&c[2],&w[2]);
        memset(dp,0,sizeof dp);
        for(int i=1;i<=2;i++)
            for(int v=c[i];v<=V;v++)
                dp[v]=max(dp[v],dp[v-c[i]]+w[i]);
        printf("%d\n",dp[V]);
    }
    return 0;
}
