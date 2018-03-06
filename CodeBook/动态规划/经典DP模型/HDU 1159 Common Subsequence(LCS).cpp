//最长公共(不连续)子序列 LCS (DP)
//思想:动态规划O(n^2)
//dp[i][j] 表示字符串X 前i位 与 字符串Y 前j位的LCS
//if i==0&& j==0 dp[i][j]=0;
//if(x[i]==y[j]) dp[i][j]=dp[i-1][j-1]=1;
//if(x[i]!=y[j]) max(dp[i][j-1],dp[i-1][j])
#include<bits/stdc++.h>
using namespace std;
const int maxn=10005;
char X[maxn],Y[maxn];
int dp[maxn][maxn];
int main()
{
    while(scanf("%s %s",X,Y)!=EOF)
    {
        int lenX=strlen(X);
        int lenY=strlen(Y);
        memset(dp,0,sizeof dp);

        for(int i=1;i<=lenX;i++)
            for(int j=1;j<=lenY;j++)
                if(X[i-1]==Y[j-1])
                    dp[i][j]=dp[i-1][j-1] + 1;
                else
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        printf("%d\n",dp[lenX][lenY]);
    }
    return 0;
}

//滚动数组优化
