//二维背包 最小消耗的耐力值+最大杀怪经验+有限的杀怪数
//背包存放价值：经验值， dp[][]容量是耐力值+杀怪数
#include<bits/stdc++.h>
const int maxn=105;
int dp[maxn][maxn];//dp[i][j]表示消耗i的耐久度杀了j个怪物得到的经验值
struct node
{
    int e;
    int r;//耐力值
}a[maxn];
using namespace std;
int main()
{
    int n,m,k,s;//需经验值，耐久度，种类，杀怪数
    while(scanf("%d%d%d%d",&n,&m,&k,&s)!=EOF)
    {
        for(int i=1;i<=k;i++)
            scanf("%d%d",&a[i].e,&a[i].r);
        memset(dp,0,sizeof dp);
        for(int i=1;i<=k;i++)//对不同种类的怪物遍历一遍
            for(int j=a[i].r;j<=m;j++)//耐力值
                for(int t=1;t<=s;t++)//杀怪数
                    dp[j][t]=max(dp[j][t],dp[j-a[i].r][t-1]+a[i].e);
        if(dp[m][s]>=n)
        {
            for(int i=0;i<=m;i++)
                if(dp[i][s]>=n)
                {
                    printf("%d\n",m-i);
                    break;
                }
        }
        else
            printf("-1\n");
    }
    return 0;
}
