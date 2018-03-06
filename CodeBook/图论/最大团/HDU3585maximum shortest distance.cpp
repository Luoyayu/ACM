//N个点，选出K个点形成若干点集，输出在这些点集中最小距离的最大值
//看不出算法系列++
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn=55;
int g[maxn][maxn],dp[maxn],stk[maxn][maxn],best;
int x[maxn],y[maxn],n,k;
void dfs(int n,int ns,int dep)
{
	if(!ns)
	{
		if(dep > best)
            best = dep;
        return ;
	}
	for(int i=0; i<ns; i++)
	{
		int k = stk[dep][i];
		int cnt = 0;
		if(dep + n - k <= best) return;
		if(dep + dp[k] <= best) return;
		for(int j=i+1; j<ns; j++)
		{
			int p = stk[dep][j];
			if(g[k][p])
                stk[dep+1][cnt++] = p;
		}
		dfs(n,cnt,dep+1);
	}
	return ;
}
int clique(int n)
{
	int i,j,ns;
	for(best=0, i=n-1; i>=0; i--)
	{
		for(ns=0, j=i+1; j<n; j++)
			if(g[i][j])
                stk[1][ns++] = j;
		dfs(n,ns,1);
		dp[i] = best;
	}
	return best;
}
double arc[maxn][maxn],dis[maxn*maxn];
bool check(double lim)
{
    memset(g,0,sizeof(g));
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(arc[i][j]>=lim)
                g[i][j] = g[j][i]=1;
    if(clique(n)>=k)
        return true;
    else
        return false;
}
int main()
{
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		for(int i=0;i<n;i++)
            scanf("%d%d",&x[i],&y[i]);
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            arc[i][i]= -1;
            for(int j=i+1;j<n;j++)
                arc[i][j]=sqrt( double((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j]) * (y[i]-y[j]) ) ),
                dis[cnt++]=arc[j][i]=arc[i][j];
        }
        sort(dis,dis+cnt);
        int l=0,r=cnt-1,mid,ans;
        while(l<=r)
        {
            mid=(l+r)>>1;
            if(check(dis[mid]))
                ans=mid,l=mid+1;
            else
                r=mid-1;
        }
        printf("%.2lf\n",dis[ans]);
	}
	return 0;
}

