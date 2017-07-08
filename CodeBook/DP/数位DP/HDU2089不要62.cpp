#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define clr(a,b) memset(a,b,sizeof (a))
int dp[20][2],a[20];//dp[pos][sta]表示当前第pos位,前一位是否位6的状态
int dfs(int pos, int pre, int statue, bool limit)
{
    if(pos == -1) return 1;//递归边界
    if(!limit && dp[pos][statue]!=-1) return dp[pos][statue];
    int up = limit?a[pos]:9 ;//定枚举上界
    int ans = 0;
    for(int i=0;i<=up;i++)
    {
        if(pre==6&&i==2) continue;
        if(i==4) continue;
        ans += dfs(pos-1,i,i==6,limit && i==a[pos]);
    }
    if(!limit) dp[pos][statue]=ans;
    return ans;
}
int solve(int n)
{
    int pos=0;
    while(n)
    {
        a[pos++]=n%10;
        n/=10;
    }
    return dfs(pos-1,-1,0,true);
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF && n+m)
    {
        memset(dp,-1,sizeof dp);
        printf("%d\n",solve(m)-solve(n-1));
    }
    return 0;
}
