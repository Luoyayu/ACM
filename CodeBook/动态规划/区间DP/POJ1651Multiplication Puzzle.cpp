//#include<bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
//题意: 给出序列a,求出最小得分—— 取出的数左边的数右边的数 (不能取两边)，
//实质为矩阵链乘变形，设dp[i][j]为取光(i,j)之间的元素所得的最小值, 
//k为区间(i,j)最后取出的元素，
//这样转移就可以维持状态方程的一致性
//dp[i][j]=min(dp[i][j], DP(l,k)+DP(k,r)+a[k]*a[l]*a[r])，
//因为如果k为第一次取出的元素的话不好确定k左右的临近元素
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
    for(int k=l+1; k<=r-1; ++k)//枚举取出的点
        dp[l][r] = min(dp[l][r], DP(l,k)+DP(k,r)+a[k]*a[l]*a[r]);
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