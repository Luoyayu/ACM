1) 对维数为序列<5, 10, 3, 12, 5, 50, 6>的各矩阵，找出其矩阵链乘积的一个最优加全部括号。
2) 确定<1, 0, 0, 1, 0, 1, 0, 1>和<0, 1, 0, 1, 1, 0, 1, 1, 0>的一个最长公共子序列LCS。

solution：
1) 5*10

2) LCS(X, Y) = 6 (0 1 0 1 0 1)

``` cpp
//最长公共(不连续)子序列 LCS (DP)
//思想: 动态规划O(n^2)
//dp[i][j] 表示字符串X前i位与字符串Y前j位的LCS
//if i==0 && j==0 dp[i][j]=0; 边界条件
//if(x[i]==y[j]) dp[i][j] = dp[i-1][j-1] + 1; 
//if(x[i]!=y[j]) dp[i][j] = max(dp[i][j-1], dp[i-1][j])

#include <bits/stdc++.h>
using namespace std;
const int maxn=10005;
char X[maxn],Y[maxn];
int dp[maxn][maxn];
int main() {
    while(scanf("%s %s",X, Y)!=EOF) {
        int lenX = strlen(X);
        int lenY = strlen(Y);
        memset(dp, 0, sizeof dp);

        for(int i=1; i<=lenX; i++)
            for(int j=1; j<=lenY; j++)
                if(X[i-1] == Y[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
        printf("%d\n", dp[lenX][lenY]);
    }
    return 0;
}
```
