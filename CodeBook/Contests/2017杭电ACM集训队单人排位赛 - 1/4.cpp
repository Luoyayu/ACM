// 由只能向右或向下走 联想到一种经典的计数DP，即从(x,y) --> (n,m)有多少条路 （只能向右或向下走）
//故我们可以令 dp[x][y][k] : 当在(x,y)处，装备值为k时能拥有的最大价值
// 类似经典dp问题，每一个点(x,y)的状态，只能由 (x-1,y) 或 (x,y-1)转移而来
// 对于第一行和第一列应单独考虑，因为只有一种转移方式

#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;

const int A = 100 + 10;
int V[A][A],C[A][A];
int dp[A][A][A];
int n,m,T;

int main(){
    while(~scanf("%d%d%d",&n,&m,&T)){
        memset(dp,-1,sizeof(dp));
        for(int i=1 ;i<=n ;i++){
            for(int j=1 ;j<=m ;j++){
                scanf("%d",&V[i][j]);  //保存价值
            }
        }
        for(int i=1 ;i<=n ;i++){
            for(int j=1 ;j<=m ;j++){
                scanf("%d",&C[i][j]);   //保存陷阱
            }
        }
        if(n<=0 || m<=0 || T-C[1][1] <= 0){  //特判
            puts("-1");
            continue;
        }

        dp[1][1][T-C[1][1]] = V[1][1];
        for(int j=2 ;j<=m ;j++){                   //预处理第一排
            for(int k=1 ;k<=T ;k++){               //枚举可能的装备值
                if(dp[1][j-1][k] != -1){
                    if(k-C[1][j] <= 0) continue;
                    dp[1][j][k-C[1][j]] = dp[1][j-1][k] + V[1][j];
                }
            }
        }
        for(int i=2 ;i<=n ;i++){
            for(int j=1 ;j<=m ;j++){
                if(j == 1){                       //对于第一列 只能从上面转移
                    for(int k=1 ;k<=T ;k++)
                    if(dp[i-1][j][k] != -1){
                        if(k - C[i][j] <= 0) continue;
                        dp[i][j][k-C[i][j]] = dp[i-1][j][k] + V[i][j];
                    }
                }
                else{
                    for(int k=1 ;k<=T ;k++){
                        if(k - C[i][j] <= 0) continue;
                        if(dp[i-1][j][k] != -1){        //从上一行转移
                            dp[i][j][k-C[i][j]] = max(dp[i][j][k-C[i][j]],dp[i-1][j][k] + V[i][j]);
                        }
                        if(dp[i][j-1][k] != -1){        //从上一列转移
                            dp[i][j][k-C[i][j]] = max(dp[i][j][k-C[i][j]],dp[i][j-1][k] + V[i][j]);
                        }
                    }
                }
            }
        }
        int Max = -1,add = 0;
        for(int i=1 ;i<=T ;i++){
            if(dp[n][m][i] > Max){
                Max = dp[n][m][i];
                add = i;
            }
        }
        if(Max == -1) puts("-1");
        else          printf("%d %d\n",add,Max);
    }
    return 0;
}