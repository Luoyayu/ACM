//2-sat 入门
//设帮派(a0,a1) (b0,b1) 有矛盾a0——b0 建立有向边(a0,b1) (b0,a1)
//有向边(a,b) 表示选择a必须选b
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int N = 100000;
#define stack STACK
#define next NEXT
int n,m;
int head[N];
struct Edge
{
    int to,next,w;
}edge[N];
int dfn[N], low[N], belong[N], index, scc;
int stack[N] ,top, tot,dis[N];
bool instack[N];
void add(int u ,int v )
{
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}
void init()
{
    tot= index = scc = top = 0;
    for(int i=0;i<N;i++)
    {
        head[i]= -1;
        low[i]=dfn[i]=instack[i]=stack[i]=0;
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

int work()
{
    int MM=n<<1;
    for(int i=0;i<MM;i+=2)
        if(belong[i]==belong[i+1])
            return 1;
    return 0;
}
int main()
{
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        init();
        for(int i=0; i<m; i++)
        {
            int a,b,c,d;
            scanf("%d%d%d%d",&a,&b,&c,&d);
            a=(a<<1)+c;
            b=(b<<1)+d;
            add(a,b^1);
            add(b,a^1);
        }
        int MM=n<<1;
        for(int i=0;i<MM;i++)
            if(!dfn[i])
                tarjan(i);
        if(work())
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
