/*长度为n的花环,有k种花,相邻的花不同,第l和第r朵花颜色相同,求方案数mod 1e9+7 l,r重要的是长度 i
* dp 固定一端考虑另一端增长的情况,设dp[i][1]为长度为i,第i朵花与固定端相同的方案数,
* dp[i][0]表示长度为i,第i朵花与固定段不同的方案数
*/
#include<bits/stdc++.h>
#define Debug(x) cout<<#x<<"= "<<x<<endl;
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
typedef long long LL;
int n,m,k,l,r;
LL dp[maxn][2];
int main()
{
    while(scanf("%d%d%d",&n, &m, &k)!=EOF)
    {
        dp[1][0]=0,dp[1][1]=k-1;
        for(int i=2;i<=n;i++)
        {
            dp[i][1]=(dp[i-1][1]*(k-2)%mod+dp[i-1][0]*(k-1)%mod)%mod;
            dp[i][0]=dp[i-1][1];//长度为i的且与固定端颜色相同的个数由长度为i-1与固定端不同递推来
        }
        while(m--)
        {
            scanf("%d%d",&l,&r);
            if(l>r) swap(l,r);
            int t1 = r-l-1;
            int t2 = n-t1-2;
            LL ans = (k*dp[t1][1]%mod*(dp[t2][1]%mod))%mod;
            printf("%I64d\n",ans);
        }
    }
    return 0;
}
