#include<bits/stdc++.h>
//数位DP再学
//数位DP是一种控制上界的枚举,dp[pos][state]保存枚举到pos位置状态为state的个数
typedef long long ll;
using namespace sdt;
const int maxn = 10000+7;
ll dp[maxn][maxn];
ll a[maxn];

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
}
int main()
{
    int le,ri;
    while(scanf("%d%d",&le,&ri)!=EOF
        printf("lld\n",aolve(ri)-solve(le-1));
    return 0;
}