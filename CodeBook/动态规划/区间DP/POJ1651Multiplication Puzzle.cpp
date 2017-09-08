//#include<bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
// 题意: 给出序列a,求出最小得分—— 取出的数*左边的数*右边的数 (不能取两边)
// 区间DP入门题 循环写法/记忆化写法
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
const int maxn = 100 + 5;
const int inf = 0x3f3f3f3f;
int dp[maxn][maxn];
int a[maxn];
int DP(int l, int r)
{
    if(~dp[l][r])return dp[l][r];
    if(r-l==1) return dp[l][r] = 0;
    dp[l][r] = inf;
    for(int i=l+1; i<=r-1; ++i)//枚举取出的点
        dp[l][r] = min(dp[l][r], DP(l,i)+DP(i,r)+a[i]*a[l]*a[r]);
    return dp[l][r];
}
int main()
{
    int n = read();
    for(int i=1;i<=n;i++) a[i] = read();
    memset(dp,-1,sizeof dp);
    printf("%d\n",DP(1,n));
    return 0;
}