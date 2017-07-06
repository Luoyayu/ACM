
//DAG 的最小路径覆盖
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=121;
int g[maxn][maxn];
int used[maxn];
int linker[maxn];
int n,m;
int DFS(int u)
{
    for(int v=1;v<=n;v++)
    {
        if(g[u][v]&&!used[v])
        {
            used[v]=true;
            if(linker[v]==-1||DFS(linker[v]))
            {
                linker[v]=u;
                return 1;
            }
        }
    }
    return 0;
}
int match()
{
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        memset(used,0,sizeof used);
        ans+=DFS(i);
    }
    return ans;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b;
        memset(g,0,sizeof g);
        scanf("%d%d",&n,&m);
        memset(linker,-1,sizeof linker);
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&a,&b);
            g[a][b]=1;
        }
        printf("%d\n",n-match()) ;

    }
    return 0;
}
