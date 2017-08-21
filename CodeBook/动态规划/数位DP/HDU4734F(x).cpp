#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define clr(a,b) memset(a,b,sizeof a)
//定义F(x)为x各位数乘以二进制基数
//求在[0,B] 中F(x) 小于F(A) 的数的个数
const int maxn = 10000+55;//dp[i][j]表示i+1位的数x中F(x)中小于j的数的个数//使用F()的值作为状态
int a[12], dp[10][maxn],all;
int f(int x)
{
    int cnt=0,sum=0;
    x*=10;
    while(x/=10)
        sum+= x%10*(1<<cnt++);
    return sum;
}
ll dfs(int pos, int sum, bool limit)
{
    if(pos==-1) return sum<=all;
    if(all-sum<=) return 0;
    if(!limit&& ~dp[pos][all-sum]) return dp[pos][all-sum];
    int up =limit?a[pos]:9;
    int ans = 0;
    for(int i=0;i<=up;i++)
        ans+=dfs(pos-1,sum+i*(1<<pos),limit&&i==a[pos]);
    if(!limit) dp[pos][all-sum]=ans;
    return ans;
}
int solve(int n)
{
    int pos = 0;
    while(n)
    {
        a[pos++]= n%10;
        n /= 10;
    }
    return dfs(pos-1,0,true);
}
int main()
{
    int T,A,B;scanf("%d",&T);
    clr(dp,-1);
    for(int kase=1;kase<=T;kase++)
    {
        scanf("%d %d",&A,&B);
        all = f(A);
        printf("Case #%d: %d\n",kase,solve(B));
    }
    return 0;
}
