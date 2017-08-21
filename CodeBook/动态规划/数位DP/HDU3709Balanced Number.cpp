//继续数位DP
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//求给定区间的平衡数个数 例如4139 1*1+4*2=9*1故是平衡数
//如何判断平衡数,中心点怎么找? 通过枚举平衡位置o
int a[20];
ll dp[20][20][5000];//设计状态dp[pos][i][k]
ll dfs(int pos, int o, int num, bool limit)
{
    if(pos==-1) return num==0;
    if(dp[pos][o][num]!=-1&&!limit) return dp[pos][o][num];
    int up = limit?a[pos]:9;
    ll ans = 0;
    for(int i=0;i<=up;i++)
        ans += dfs(pos-1,o,(pos-o)*i+num,limit&&i==up);
    if(!limit)  dp[pos][o][num]=ans;
    return ans;
}
ll solve(ll n)
{
    int pos = 0;
    while(n) a[pos++] = n % 10, n /= 10;
    ll ans = 0;
    for(int i=0;i<=pos-1;i++)
        ans+=dfs(pos-1,i,0,true);
    return ans-pos+1;
}
int main()
{
    int T;cin>>T;
    memset(dp,-1,sizeof dp);
    while(T--)
    {
        ll x,y;cin>>x>>y;
        cout<<solve(y)-solve(x-1)<<endl;
    }
    return 0;
}
