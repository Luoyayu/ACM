//最长公共不连续子序列 LCS DP
//思想母串
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
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        printf("%d\n",dp[lenX][lenY]);
    }
    return 0;
}
