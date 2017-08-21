#include<bits/stdc++.h>
//定义美丽的数为:递减数且 前一位%后一位==0
//注意前导零
using namespace std;
const int maxn = 20 ;
typedef long long ll;
int a[20];
int dp[20][10];
int dfs(int pos, int pre, int lead, bool limit)
{
    if(pos ==-1) return 1;
    if(!limit&&~dp[pos][pre]) return dp[pos][pre];
    int up = limit?a[pos]:9;
    int ans=0;
    for(int i=0;i<=up;i++)
    {
        if(lead==0||(i<=pre && i && pre%i==0))
            ans+= dfs(pos-1,i,lead||i,limit && i==up);
    }
    return !limit? dp[pos][pre]=ans:ans;
}
int solve(int n)
{
    int pos = 0;
    while(n)
    {
        a[pos++]= n%10;
        n/=10;
    }
    return dfs(pos-1,0,0,1);//注意此处前导0无限制
}
int main()
{
    int t;scanf("%d",&t);
    memset(dp,-1,sizeof dp);
    while(t--)
    {
        int L,R;scanf("%d%d",&L,&R);
        printf("%d\n",solve(R)-solve(L-1));
    }
    return 0;
}
