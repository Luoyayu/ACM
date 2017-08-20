#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define clr(a,b) memset(a,b,sizeof (a))
int dp[20][2],a[20];//dp[pos][inc]表示当前第pos位,前一位是否位6的状态
int dfs(int pos, bool inc, bool lim, bool lead)//inc记录当前位置是否有6
{
    if(pos == -1) return 1;//递归边界
    if(!lim && ~dp[pos][inc]) return dp[pos][inc];
    int up = lim ? a[pos] : 9 ;//定枚举上界
    int ans = 0;
    for(int i=0;i<=up;i++)
    {
        if(i!=4)
        {
            if(inc && i==2) continue;
            ans += dfs(pos-1,i==6,lim && i==up);
        }
    }
    if(!lim) dp[pos][inc]=ans;
    return ans;
}
int solve(int n)
{
    int pos=0;
    while(n)
    {
        a[pos++] = n % 10;
        n /= 10;
    }
    return dfs(pos-1,false,true,false);//最高位限制+前导0限制
}
int main()
{
    int n,m;clr(dp,-1);
    while(scanf("%d %d",&n,&m)!=EOF && n+m)
        printf("%d\n",solve(m)-solve(n-1));
    return 0;
}
