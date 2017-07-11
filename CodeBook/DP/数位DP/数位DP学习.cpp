#include<bits/stdc++.h>
//数位DP再学
//数位DP是一种控制上界的枚举,dp[pos][state]保存枚举到pos位置状态为state的个数
typedef long long ll;
using namespace sdt;
const int maxn = 10000+7;
ll dp[maxn][maxn];
ll a[maxn];
ll dfs(int pos, int pre, bool limit)
{
    if(pos==-1)//枚举到边界,既pos=0(最低位)-1==-1
        return 1;
    if(!limit && ~dp[pos][state])
        return dp[pos][state];
    int up = limit ? a[pos] : 9;//根据limit判断上界1
    ll ans = 0;
    for(int i=0;i<=limit;i++)
    {
        if()....
        else if()....
        ans+=dfs(pos-1,lead && i=,limit && i==up)//pos-1记录最高位,pos==0为最低位
    }
    if(!limit )
        dp[pos][state]=ans;
    return ans;

}

//模板二
int dfs(int pos, int s, bool limit) 
{
    if (pos==-1) return s==target_s;
    if (!limit && ~dp[i][s]) return dp[i][s];
    int res = 0;
    int up = limit?num[i]:9;
    for (int i = first?1:0; i <= up; ++i)
        res += dfs(i-1, new_s(s, i), limit&&i==up);
    return limit?res:dp[pos][s]=res;
}


ll solve(int n)
{
    int pos = 0;
    while(n)
    {
        a[pos++]=n%10;
        n/=10;
    }
    return dfs(pos-1,1,1);
    return dfs() 
}
int main()
{
    int le,ri;
    while(scanf("%d%d",&le,&ri)!=EOF
    {
        printf("lld\n",aolve(ri)-solve(le-1));
    }
    return 0;
}