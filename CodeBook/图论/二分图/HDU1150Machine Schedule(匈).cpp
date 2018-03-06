
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=105;
int g[maxn][maxn];
int used[maxn];
int linker[maxn];
int vN,uN,k;
int dfs(int u)
{
    for(int v=0;v<vN;v++)
    {
        if(g[u][v]&&!used[v])
        {
            used[v]=true;
            if(linker[v]==-1 || dfs(linker[v]))
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
    for(int u=0;u<uN;u++)
    {
        memset(used,0,sizeof used);
        ans+=dfs(u);
    }
    return ans;
}
int main()
{
    while(scanf("%d",&uN),uN)
    {
        memset(g,0,sizeof g);
        memset(linker ,-1,sizeof linker);
        scanf("%d%d",&vN,&k);

        for(int i=0;i<k;i++)
        {
            int a,b;
            scanf("%d%d%d",&i,&a,&b);
            if(a>0&&b>0)
                g[a][b]=1;
        }
        printf("%d\n",match());


    }
    return 0;
}
