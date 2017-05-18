#include <cstdio>
#include<cstring>
using namespace std;
double p[1005][1005][3], dp[1005][1005];
int main()
{
    int r, c;
    while(~scanf("%d%d", &r, &c))
    {
        memset(dp,0,sizeof dp);
        for(int i=1; i<=r; ++i)
            for(int j=1; j<=c; ++j)
                for(int k=1; k<=3; ++k)
                    scanf("%lf",&p[i][j][k]);
        dp[r][c] = 0;
        for(int i=r; i>0; --i)
            for(int j=c; j>0; --j)
            {
                if(p[i][j][1]==1|| i==r&&j==c)
                    continue;
                dp[i][j] = p[i][j][1]*dp[i][j] + p[i][j][2]*dp[i][j+1] + p[i][j][3]*dp[i+1][j] + 2;
                dp[i][j] /= (1.0-p[i][j][1]);
            }
        printf("%.3f\n", dp[1][1]);
    }
    return 0;
}
