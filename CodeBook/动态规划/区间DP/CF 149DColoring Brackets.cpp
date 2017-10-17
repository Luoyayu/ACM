#include <bits/stdc++.h>
using namespace std;
//题意:给出括号序列染色要求
/*1.括号要么不被染色要么染成红或蓝色
 *2.相邻的括号要染色保持不同
 *3.相匹配的括号有且只有一个被染色
 */
//dp[l][r][x][y]为[l,r]表示给[l,r]染色且端点l染x色，右端点r染y色 <0,1,2>分别为<plain, red, blue>
//if <l,r> is matched ,那么由去掉这个嵌套的dp[l+1][r-1][x][y]转移出dp[l][r][x][y]枚举l+1,r-1的颜色
/*i->l+1; j->r-1;
 * if(i!=1) dp[l][r][1][0]=(dp[l][r][1][0] + dp[l+1][r-1][i][j])%mod;
 * if(i!=2) dp[l][r][2][0]=(dp[l][r][2][0] + dp[l+1][r-1][i][j])%mod;
 * if(j!=1) dp[l][r][0][1]=(dp[l][r][0][1] + dp[l+1][r-1][i][j])%mod;
 * if(j!=2) dp[l][r][0][2]=(dp[l][r][0][2] + dp[l+1][r-1][i][j])%mod;
 */
//if <l,r> isn't matched,那么可以找到和l匹配的括号位置mid,求出dp[l][mid][][]和dp[mid+1][r][][]枚举l,mid,mid+1,r这四个位置的颜色i,j,x,y 有转移方程
//if(j*x==0||j!=x) dp[l][r][i][y]=(dp[l][r][i][y] + dp[l][mid][i][j] * dp[mid+1][r][x][y]%mod)%mod;
typedef long long ll;
const int maxn = 700 + 7;
const int mod = int(1e9 + 7);
int belong[maxn];
ll dp[maxn][maxn][3][3];
char ss[maxn];
void dfs(int l, int r)
{
    if(r-l==1)
    {
        dp[l][r][0][1] = dp[l][r][0][2]=dp[l][r][1][0]=dp[l][r][2][0] = 1;
        return ;
    }
    if(belong[l]==r)
    {
        dfs(l+1,r-1);//一直递归到小区间处理
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
            {
                if(i!=1) dp[l][r][1][0]=(dp[l][r][1][0] + dp[l+1][r-1][i][j])%mod;
                if(i!=2) dp[l][r][2][0]=(dp[l][r][2][0] + dp[l+1][r-1][i][j])%mod;
                if(j!=1) dp[l][r][0][1]=(dp[l][r][0][1] + dp[l+1][r-1][i][j])%mod;
                if(j!=2) dp[l][r][0][2]=(dp[l][r][0][2] + dp[l+1][r-1][i][j])%mod;
            }
    }
    else
    {
        int mid = belong[l];
        dfs(l,mid);dfs(mid+1,r);
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                for(int x=0;x<3;x++)
                    for(int y=0;y<3;y++)//<i,j>, <x,y>
                    {
                        if(j*x!=0 && j==x) continue;
                        dp[l][r][i][y]=(dp[l][r][i][y] + dp[l][mid][i][j] * dp[mid+1][r][x][y]%mod)%mod;
                    }
    }
}
int main()
{
    while(scanf("%s",ss)!=EOF)
    {
        int len = strlen(ss);
        for(int i=0;i<len;i++)//处理匹配
            if(ss[i]=='(') {
                int cnt = 0;
                for(int j=i;j<len;j++){
                    if(ss[j] =='(') cnt++;
                    else cnt--;
                    if(cnt==0) {
                        belong[i] = j;
                        break;
                    }
                }
            }

        memset(dp,0, sizeof(dp));
        dfs(0,len-1);
        ll ans = 0;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                ans = (ans + dp[0][len-1][i][j])%mod;
        printf("%lld\n",ans);
    }
    return 0;
}