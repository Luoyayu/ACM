//强连通分量缩点，求出入度为0的分量个数、
//taskA：给定一个有向图，问至少需要多少顶点，能使该图强连通；
//taskB:给定一个有向图，为你至少需要加多少条边，能使该图强连通
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxV=105;
const int maxE =100500;
struct edge
{
    int to,next;
}Edge[maxE];
int head[maxV],e,n;
int indeg[maxV],outdeg[maxV];//点的入度和出度数
int belong[maxV],low[maxV],dfn[maxV],sccc,cnt;
int Stack[maxV],top;
bool inStack[maxV];
void addedge(int u,int v)
{
    Edge[e].to=v;
    Edge[e].next=head[u];
    head[u]=e++;
}
void tarjan(int u)
{
    int v;
    dfn[u]=low[u]=++cnt;
    Stack[top++]=u; //r入栈
    inStack[u]=1;
    for(int i=head[u];i!=-1;i=Edge[i].next)
    {
        v=Edge[i].to;
        if(!dfn[v])//如果与u相连的点还未被
        {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(inStack[v] && low[v]<low[u])
            low[u]=low[v];
    }
    if(dfn[u]==low[u])
    {
        sccc++;
        do
        {
            v=Stack[--top];//栈中所有到u的点都属于该强连通分量，出栈
            inStack[v]=0;
            belong[v]=sccc;
        }while(u!=v);
    }
}
int solve()
{
    sccc=cnt=top=0;
    memset(dfn,0,sizeof dfn);
    memset(inStack,0,sizeof(inStack));
    for(int u=1;u<=n;u++)
        if(dfn[u]==0)
            tarjan(u);
    return sccc;
}
void count_deg()
{
    memset(indeg,0,sizeof indeg);
    memset(outdeg,0,sizeof outdeg);
    for(int u=1;u<=n;u++)
        for(int i=head[u];i!=-1;i=Edge[i].next)
    {
        int v=Edge[i].to;
        if(belong[u]!=belong[v])
        {
            indeg[belong[v]]++;
            outdeg[belong[u]]++;
        }
    }
}
int main()
{
    int u,v,i;
    while(scanf("%d",&n)!=EOF)
    {
        e=0;
        memset(head,-1,sizeof head);
        for(int u=1;u<=n;u++)
        while(scanf("%d",&v)&&v!=0)
            addedge(u,v);
        solve();
        if(sccc==1)
            printf("1\n0\n");
        else
        {
            count_deg();
            int inc=0,outc=0;
            for(int i=1;i<=sccc;i++)
            {
                if(indeg[i]==0)inc++;
                if(outdeg[i]==0) outc++;
            }
            printf("%d\n%d\n",inc,max(inc,outc));
        }
        return 0;
    }
}
