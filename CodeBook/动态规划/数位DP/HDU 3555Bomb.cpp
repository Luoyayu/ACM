#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[20];
ll dp[20][2];//设计状态 dp[pos][当前pos位是否含有4]
ll dfs(int pos, bool inc, bool limit)//state记录当情况pos是否含有4
{
    if(pos==-1) return 1;
    if(!limit&&~dp[pos][inc]) return dp[pos][inc];
    int up =limit?a[pos]:9;
    ll ans=0;
    for(int i =0;i<=up;i++)
    {
        if(inc&&i==9) continue;//如果当前pos位时4continue i==9的情况
        ans+=dfs(pos-1,i==4,limit&&i==up);
    }
    if(!limit) dp[pos][inc] = ans;
    return ans;
}
ll solve(ll n)
{
    int pos = 0;
    while(n)
    {
        a[pos++] = n % 10;
        n /= 10;
    }
    return dfs(pos-1,0,1);
}
int main()
{
    int t;scanf("%d",&t);
    memset(dp,-1,sizeof dp);
    while(t--)
    {
        ll n;scanf("%lld",&n);
        printf("%lld\n",n-solve(n)+1);
    }
    return 0;
}