//HDU 4815 Little Tiger vs Deep Monkey.cpp
//基础概率DP
//dp[i][j]表示前i场得分为j的概率
#include<bits/stdc++.h>
using namespace std;
const int maxn = 41;
const int inf = 0x3f3f3f3f;
const double eps = 1e-8;
int a[maxn];
double dp[44][1001*44];
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n;double p;
        scanf("%d %lf", &n, &p);
        int sum = 0;//总分
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]), sum+=a[i];
        memset(dp,0, sizeof(dp));
        dp[0][0] = 1.0;

        for(int i=1;i<=n;i++)
            for(int j=0;j<=sum;j++)
            {
                if(j >= a[i]) dp[i][j] = dp[i-1][j-a[i]]/2; 
                dp[i][j] += dp[i-1][j] / 2;
            }

        double tmp=0.0;
        for(int i=0;i<=sum;i++)
            if ((tmp+=dp[n][i]) > p || fabs(tmp - p) < eps)
            {
                printf("%d\n", i);
                break;
        }
    }
    return 0;
}