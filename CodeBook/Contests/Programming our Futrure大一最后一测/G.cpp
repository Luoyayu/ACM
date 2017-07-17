// perfect man dazhongfeng
//历史遗留补题
//题意:ith plan ^ [ai in A,bi in B, ci in C]
//try to find the num of plans can  ^ at lease [x in A, y in B, z in C]

#include<bits/stdc++.h>
typedef long long ll;
const int maxn = 55;
const int mod = 1e9+7;
int n,X,Y,Z;
int dp[maxn][maxn][maxn];
using namespace std;
int main()
{
    int t;scanf("%d", &t);
    while(t--)
    {
        memset(dp, 0, sizeof dp);
        scanf("%d %d %d %d",&n, &X, &Y, &Z);
        dp[0][0][0] = 1;
        for(int i = 1; i <= n; i++)
        {
            int x,y,z;scanf("%d %d %d",&x, &y, &z);
            for(int j = X; j >= 0; j--)
            for(int k = Y; k >= 0; k--)
            for(int u = Z; u >= 0; u--)
            dp[min(j+x,X)][min(k+y,Y)][min(u+z,Z)] = (dp[j][k][u]%mod+dp[min(j+x,X)][min(k+y,Y)][min(u+z,Z)%mod])%mod;
        }
        printf("%d\n", dp[X][Y][Z]);
    }
    return 0;
}
