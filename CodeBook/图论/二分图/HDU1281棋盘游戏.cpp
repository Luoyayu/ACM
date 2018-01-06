#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=105;
int g[maxn][maxn];
int used[maxn];
int linker[maxn];
int un,vn,k;
int dfs(int u)
{
    for(int v=1;v<=vn;v++)
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
    memset(linker,-1,sizeof linker);
    for(int u=1;u<=un;u++)
    {
        memset(used,0,sizeof used);
        ans+=dfs(u);
    }
    return ans;
}
int main()
{
    int t=1;
    while(scanf("%d%d%d",&un,&vn,&k)!=EOF)
    {
        int cnt=0;
        int a,b;
        memset(g,0,sizeof g);
        for(int i=1;i<=k;i++)
            scanf("%d%d",&a,&b),g[a][b]=1;
        int temp=match();
        for(int i=1;i<=un;i++)
            for(int j=1;j<=vn;j++)
            {
                if(g[i][j]==1)
                {
                    g[i][j]=0;
                    if(match()<temp)
                        cnt++;
                    g[i][j]=1;
                }

            }
    printf("Board %d have %d important blanks for %d chessmen.\n",t++,cnt,temp);
    }
    return 0;
}
