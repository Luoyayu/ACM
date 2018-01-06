#include<cstdio>
#include<cstring>
const int maxn=  1005;
int uN,vN,k;
int g[maxn][maxn];
int used[maxn];
int linker[maxn];
using namespace std;
int dfs(int u)
{
    for(int v=1;v<=vN;v++)
    {
        if(g[u][v]&&!used[v])
        {
            used[v]=true;
            if(linker[v]==-1||dfs(linker[v]))
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
    for(int i=1;i<=uN;i++)
    {
        memset(used,0,sizeof used);
         ans+=dfs(i);
    }
    return ans;
}
int main()
{
    while(scanf("%d",&k)!=EOF,k)
    {
        int a,b;
        memset(g,0,sizeof g);
        memset(linker,-1,sizeof linker);
        scanf("%d%d",&uN,&vN);
        for(int i=1;i<=k;i++)
            scanf("%d%d",&a,&b),g[a][b]=1;
        printf("%d\n",match());
    }
    return 0;
}
