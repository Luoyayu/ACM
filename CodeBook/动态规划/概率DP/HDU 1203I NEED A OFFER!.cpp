//01背包 +概率
//转换为求解拿不到offer的概率 转移方程：背包容量n,放入m个概率,dp[j]=min(dp[j],dp[j-a[i]]*(1-b[i])])
#include<bits/stdc++.h>
const int maxn=10005;
double b[maxn],dp[maxn];
int a[maxn];
using namespace std;
int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF&&(n||m))
    {
        for(int i=0;i<m;i++)
            scanf("%d %lf",&a[i],&b[i]);
        fill(dp,dp+maxn,1);
        for(int i=0;i<m;i++)
            for(int j=n;j>=a[i];j--)
                dp[j]=min(dp[j],dp[j-a[i]]*(1-b[i]));
        printf("%.1lf%%\n",(1-dp[n])*100);
    }
    return 0;
}
