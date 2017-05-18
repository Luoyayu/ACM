//飞行棋 0-N grids|at i and dice is x, move to i+x
//fly from Xi to Yi
//when i+x>=N finish, solve expected times to finish the game
//状态：dp[i]表示 i点跳到目标状态所需步数的期望
//转移方程：{    if:(有直达路径)dp[i]=dp[fight[i]] 期望相等
//               else:
//                   dp[i]=(dp[i+1]+dp[i+2]+dp[i+3]+dp[i+4]+dp[i+5]+dp[i+6])/6.0+1[;;
//边界：dp[n-1]=0
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=100000+100;
int fight[maxn];
double dp[maxn];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF&&(n||m))
    {
        int a,b;
        memset(fight,0,sizeof fight);
        memset(dp,0,sizeof dp);
        for(int i=1;i<=m;i++)
            scanf("%d %d",&a,&b),fight[a]=b;
        for(int i=n-1;i>=0;i--)
        {
            if(fight[i])
            {
                dp[i]=dp[fight[i]];
                continue;
            }
            dp[i]=(dp[i+1]+dp[i+2]+dp[i+3]+dp[i+4]+dp[i+5]+dp[i+6])/6.0+1;
        }
        printf("%.4lf\n",dp[0]);
    }
    return 0;
}
