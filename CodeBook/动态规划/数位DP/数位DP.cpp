#include<bits/stdc++.h>
//数位DP是一种控制上界的枚举,dp[pos][inc]保存枚举到pos位置状态为inc的个数 inc缩写
typedef long long ll;
using namespace sdt;
const int maxn = 10000+7;
ll dp[maxn][maxn];
ll dig[maxn];
int dfs(int pos, int inc, bool lim) //inc指出题目所要求的合适的状态
{
    if (pos==-1) return inc==target_s;
    if (!lim && ~dp[i][inc]) return dp[i][inc];
    int res = 0;
    int up = lim?dig[i]:9;
    for (int i = first?1:0; i <= up; ++i)
        res += dfs(i-1, new_s(inc, i), lim&&i==up);
    return lim?res:dp[pos][inc]=res;
}


ll solve(int n)
{
    int pos = 0;
    while(n)
    {
        dig[pos++]=n%10;
        n/=10;
    }
    return dfs(pos-1,1,1);//依题目给出合适的初始情况,注意123 经过处理为321,开始传的是最高位故起始时有限制的
}
ll solve(char *x)
{
    int len = strlen(x);
    for(int i=0;x[1];i++)
        dig[len-i-1] = x[i]- '0';
    return dfs(lne-1,false,true);
    
}
int main()
{
    int le,ri;
    while(scanf("%d%d",&le,&ri)!=EOF
        printf("lld\n",aolve(ri)-solve(le-1));
    return 0;
}