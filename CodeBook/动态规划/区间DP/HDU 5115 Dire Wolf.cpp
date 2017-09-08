#include<bits/stdc++.h>
//题意: 有n只狼每只狼有基础攻击和增益攻击(ai,bi)增益攻击给相邻的狼以攻击力
// 求出消灭所有狼的最小承受伤害
// 区间DP第3弹
// 设dp[i][j]为取光(i,j)之间的元素所取的最小值, 如果区间长度为1则dp[i][j]=0
// 设k为区间最后取出的元素
using namespace std;
typedef long long ll;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
const int maxn = 200 + 22;
const int inf= 0x3f3f3f3f;
ll dp[maxn][maxn];
int a[maxn], b[maxn];
ll DP(int l, int r)
{
    if(~dp[l][r]) return dp[l][r];
    if(r-l==1) return dp[l][r] = 0;
    dp[l][r] = inf;
    for(int k=l+1;k<=r-1;k++)
        dp[l][r] = min(dp[l][r], DP(l,k)+DP(k,r)+a[k]+b[l]+b[r]);
    return dp[l][r];
}
int main()
{
    int t =read();
    for(int kase = 1; kase <= t; kase++)
    {
        int n = read();
        for(int i=1;i<=n;i++) a[i] = read();
        for(int i=1;i<=n;i++) b[i] = read();
        memset(dp,-1,sizeof(dp));
        a[0]=a[n+1]=b[0]=b[n+1]=0;
        printf("Case #%d: %lld\n",kase, DP(0,n+1));//统一
    }
    return 0;
}