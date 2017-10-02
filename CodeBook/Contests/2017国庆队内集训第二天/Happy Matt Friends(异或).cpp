#include<bits/stdc++.h>
//题意：给出n,M; n个朋友对应m个数(<=1e6) 求组合任意数异或和大于等于M的方案数
//思路：DP + 滚动数组
//因为异或值不可能大于1e6故可以枚举答案(1e6==2^20) 对于每个值来源是上一个阶段不取或者取a[i],
//有转移方程 dp[i][j] = dp[i][j] + dp[i][j^a[i]];
using namespace std;
const int maxn = 42;
typedef long long ll;
ll a[maxn];
ll n,M,ans;
ll dp[2][1<<20];
int main()
{
    int t;scanf("%d",&t);
    for(int kase=1; kase<=t; kase++)
    {
        ans = 0;
        scanf("%lld %lld",&n, &M);
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;
        for(int i=1; i<=n; i++)
            for(int j=0;j<(1<<20);j++)
                dp[i%2][j]=dp[(i-1)%2][j] + dp[(i-1)%2][j^a[i]];
        for(ll i=M; i<(1<<20); i++)
            ans+=dp[n%2][i];
        printf("Case #%d: %lld\n",kase,ans);
    }
    return 0;
}