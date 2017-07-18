// perfect man dazhongfeng
//历史遗留补题
//题意:ith plan ^ [ai in A,bi in B, ci in C]
//try to find the num of plans can  ^ at lease [x in A, y in B, z in C]

#include<bits/stdc++.h>
typedef long long ll;
const int maxn = 55;
const int mod = 1e9+7;
int n,X,Y,Z;//n<=20 O(n^4)
int dp[maxn][maxn][maxn];
using namespace std;
int main()
{
    //dp[i][j][k] 表示满足至少[x,y,z]时的方案数
    //dp[0][0][0]=1表示都不选的方案数只有1
    //那么对于每个计划(x_i,y_i,z_i) 
    int t;scanf("%d", &t);
    while(t--)
    {
        memset(dp, 0, sizeof dp);
        scanf("%d %d %d %d",&n, &X, &Y, &Z);
        dp[0][0][0] = 1;
        for(int i = 1; i <= n; i++)
        {
            int x,y,z;scanf("%d %d %d",&x, &y, &z);
            for(int j = X; j >= 0; j--)//更新所有的情况
            for(int k = Y; k >= 0; k--)
            for(int u = Z; u >= 0; u--)//add后超过了某项指标按照指标来算
            dp[min(j+x,X)][min(k+y,Y)][min(u+z,Z)] = (dp[j][k][u]%mod+dp[min(j+x,X)][min(k+y,Y)][min(u+z,Z)%mod])%mod;
        }
        printf("%d\n", dp[X][Y][Z]);
    }
    return 0;
}
/*
1
5 1 1 1
1 2 3
2 4 8
1 6 8
4 5 2
0 1 1
*/