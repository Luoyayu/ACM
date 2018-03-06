//tarjan强连通分量+SPFA最短路
//属于一个强连通分量的点，耗费时间为0，否则按原边权处理
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
#define N 510
#define M 250010
#define INF 0x3f3f3f3f
#define stack STACK
#define next NEXT
int n,m,K;
int head[N];
struct Edge
{
    int to,next,w;
}edge[M];
int dfn[N] , low[N] , belong[N] , index , scc;
int stack[N] , top,tot;
bool instack[N],solve[N];
int d[N][N];

void add(int u ,int v ,int w )
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
        low[i]=dfn[i]=instack[i]=stack[i]=solve[i]=0;
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
            low[u] = min(low[u] , low[v]);
        }
        else if(instack[v])
            low[u] = min(low[u] , dfn[v]);
    }
    if(dfn[u] == low[u])
    {
        ++scc;
        do
        {
            v = stack[top--];
            instack[v] = false;
            belong[v] = scc;
        }while(v!=u);
    }
}
void SPFA(int s)
{
    bool vis[N];
    queue<int>q;
    for(int i=0; i<=n; i++)
        d[s][i] = INF,vis[i] = 0;
    while(!q.empty()) q.pop();
    d[s][s] = 0;
    vis[s] = true;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for(int i=head[u]; i+1; i=edge[i].next)
        {
            int v = edge[i].to;
            int w = edge[i].w;
            if(belong[u] == belong[v])
                w = 0;//同一个连通分量，权为0
            if(d[s][u] + w < d[s][v])
            {
                d[s][v] = d[s][u] + w;
                if(!vis[v])
                    vis[v] = 1,q.push(v);
            }
        }
    }
}

int main()
{
    while(scanf("%d%d",&n,&m)!=EOF, n)
    {
        init();
        while(m--)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            add(u,v,w);
        }
        for(int i=1; i<=n; i++)
            if(!dfn[i])
                tarjan(i);
        scanf("%d",&K);
        while(K--)
        {
            int s,t;
            scanf("%d%d",&s,&t);
            if(!solve[s])
                solve[s] = 1,SPFA(s);
            if(d[s][t] == INF)
                printf("Nao e possivel entregar a carta\n");
            else
                printf("%d\n",d[s][t]);
        }
        printf("\n");
    }
    return 0;
}
