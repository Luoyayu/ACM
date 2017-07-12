#include<bits/stdc++.h>
using namespace std;
const int maxn=106;
int g[maxn][maxn],dp[maxn],stk[maxn][maxn],best;
//int path[maxn],res[maxn];//记录最大团的点
void dfs(int n,int ns,int dep)//
{
	if(ns == 0)
	{
		if(dep > best)
		{
			//swap(path,res);
			best = dep;
		}
		return;
	}
	for(int i=0; i<ns; i++)
	{
		int k = stk[dep][i],cnt = 0;
		if(dep + n - k <= best) return;//剪枝1,若当前顶点数量cnt加上还能够增加的最大数量仍小于best则退出并返回
		if(dep + dp[k] <= best) return;//剪枝2,若当前顶点数量cnt加上包含adj[i]的最大团顶点数仍小于best则退出并返回
		for(int j=i+1; j<ns; j++)
		{
			int p = stk[dep][j];
			if(g[k][p]) stk[dep+1][cnt++] = p;
		}
		//path[cnt+1] = k;
		dfs(n,cnt,dep+1);
	}
	return;
}
int clique(int n)
{
	int i,j,ns;
	for(best=0, i=n-1; i>=0; i--)
	{
		//path[1] = i;
		for(ns=0, j=i+1; j<n; j++)// 遍历[i+1,n]间顶点
			if(g[i][j]) stk[1][ns++] = j;
		dfs(n,ns,1);
		dp[i] = best;// 得出顶点i,出发构成最大团中顶点数量
	}
	return best;
}
int main()
{
	int n;
	while(scanf("%d",&n)&&n!=0)
	{
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				scanf("%d",&g[i][j]);
		int ans = clique(n);
		printf("%d\n",ans);
		/*for(int i=1; i<=ans; i++)
		{
			printf("%d",res[i]+1);
			if(i == ans) printf("\n");
			else printf(" ");
		}*/
	}
	return 0;
}
