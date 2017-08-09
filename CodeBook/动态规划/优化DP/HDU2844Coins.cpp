//DP 优化——单调队列优化
//未经优化的多重背包
//题意:给出n,m硬币种类,手表价格上限,A&C 求出能支付的手表价格种类数
//思想:问题转换成多重背包
#include<bits/stdc++.h>
using namespace std;
const int maxn = 111;
#define clr(a,b) memset(a,b,sizeof(a));
int A[maxn],C[maxn],w[maxn];;
bool dp[maxn];//dp[i]==1表示可由这些数量有限制的硬币组成价格i;
//转移方程：dp[i]=dp[i] | dp[i-A[i]] | dp[i-A[i]*2] |···| dp[i-A[i]*C[i]] 使用或运算来判断
//单纯的这样处理每个硬币总复杂度取决于每种硬币的数量O(m*Ci)虽然n只有100但是数量上限为1000
//对每种硬币分组
//TODO:使用单调队列优化

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF&&(n||m))
    {
        for(int i=0;i<n;i++) scanf("%d",&A[i]);
        for(int i=0;i<n;i++) scanf("%d",&C[i]);

        int cnt = 0;
        for(int i=0;i<n;i++)//分组
            for(int j=1;C[i]>0;j*=2)
            {
                int x = min(j,C[i]);
                C[i]-=x;
                w[cnt++]=A[i] * x;
            }
        
        clr(dp,0);dp[0]=1;
        for(int i=0;i<cnt;i++)
            for(int j=m;j>=w[i];j--)
                if(dp[j-w[i]]) dp[j] = 1;
    
        int ans = 0;
        for(int i=1;i<=m;i++)
            if(dp[i]) ans++;
        printf("%d\n",ans);
    }
    return 0;
}

//