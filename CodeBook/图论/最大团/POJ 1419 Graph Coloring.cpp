//POJ 1419 Graph Coloring
//undirected black-white color,optimal graph means a maximum of nodes is black;
//i<->adj[i] not all black;
//求解二分图的最大独立集=补图的最大团
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int maxn=110;
int n,m;
int g[maxn][maxn],dp[maxn],stk[maxn][maxn],best;
int path[maxn],res[maxn];//记录最大团的点
int dfs(int n,int ns,int dep)
{
    if(ns == 0)
    {
        if(dep > best)
        {
            swap(path,res);
            best = dep;
            return 1;
        }
        return 0;
    }
    for(int i=0; i<ns; i++)
    {
        int k = stk[dep][i],cnt = 0;
        if(dep + n - k <= best) return 0;
        if(dep + dp[k] <= best) return 0;
        for(int j=i+1; j<ns; j++)
        {
            int p = stk[dep][j];
            if(g[k][p]) stk[dep+1][cnt++] = p;
        }
        path[dep+1] = k;
        if(dfs(n,cnt,dep+1))
            return 1;
    }
    return 0;
}
int MaxClique(int n)
{
    int i,j,ns;
    for(best=0, i=n-1; i>=0; i--)
    {
        path[1] = i;
        for(ns=0, j=i+1; j<n; j++)// 遍历[i+1,n]间顶点
            if(g[i][j]) stk[1][ns++] = j;
        dfs(n,ns,1);
        dp[i] = best;// 得出顶点i,出发构成最大团中顶点数量
    }
    return best;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(g,1, sizeof(g));
        scanf("%d %d",&n,&m);
        while(m--)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            u--;v--;
            g[u][v] = g[v][u] = 0;
        }
        int ans=MaxClique(n);
        printf("%d\n",ans);
        for(int i=1; i<=ans; i++)
        {
            printf("%d",res[i]+1);
            if(i == ans) printf("\n");
            else printf(" ");
        }
    }
    return 0;
}
