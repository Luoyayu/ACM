//求把所有强连通分量连起来的最小花费值
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int N = 50000+55;
const int M = 100000+55;
const int INF = 0x3f3f3f3f;
#define stack STACK
#define next NEXT
int n,m;
int head[N];
struct Edge
{
    int to,next,w;
}edge[M];
int dfn[N], low[N], belong[N], index, scc;
int stack[N] ,top, tot,dis[N];
bool instack[N];
void add(int u ,int v ,int w)
{
    edge[tot].to = v;
    edge[tot].w = w;
    edge[tot].next = head[u];
    head[u] = tot++;
}
void init()
{
    tot= index = scc = top = 0;
    for(int i=0;i<N;i++)
    {
        head[i]=-1;
        low[i]=dfn[i]=instack[i]=stack[i]=0;
        dis[i]=INF;
    }
}
void tarjan(int u)
{
    int v;
    stack[++top] = u;
    instack[u] = true;
    dfn[u] = low[u] = ++index;
    for(int i=head[u]; i+1; i=edge[i].next)
    {
        v = edge[i].to;
        if(!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if(instack[v])
            low[u] = min(low[u], dfn[v]);
    }
    if(dfn[u] == low[u])
    {
        ++scc;
        do
        {
            v = stack[top--];
            instack[v] = 0;
            belong[v] = scc;
        }while(v!=u);
    }
}
void work()
{
    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=head[i];j+1;j=edge[j].next)
        {
            int v=edge[j].to;
            if(belong[i]!=belong[v])
                dis[belong[v]]=min(dis[belong[v]],edge[j].w);
        }
    for(int i=1;i<=scc;i++)
        if(dis[i]!=INF)
            ans+=dis[i];
    printf("%d\n",ans);
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        init();
        int u,v,w;
        while(m--)
            scanf("%d%d%d",&u,&v,&w),u++,v++,add(u,v,w);
        for(int i=1;i<=n;i++)
            if(!dfn[i])
                tarjan(i);
        work();
    }
    return 0;
}









