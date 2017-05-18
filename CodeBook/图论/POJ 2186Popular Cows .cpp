//tarjan缩点
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn= 10000+100;
const int maxm= 50000+100;
#define mt(name,value) memset(name,value,sizeof(name))
int head[maxn],low[maxn],dfn[maxn],Stack[maxn];
int belong[maxn],outdeg[maxn];
int top,sccc,cnt;
int n,m;
bool instack[maxn];
struct edge
{
    int to,next;
}Edge[maxm];
void init()
{
    sccc=top=cnt=0;
    mt(head,-1),mt(Edge,-1);
    mt(low,0),mt(dfn,0);
    mt(instack,0),mt(belong,0);
    mt(outdeg,0);

}
void addedge(int u,int v,int tot)
{
    Edge[tot].to=v;
    Edge[tot].next=head[u];
    head[u]=tot;
}
void tarjan(int i)
{
    int e;
    dfn[i]=low[i]=++cnt;
    instack[i]=1;
    Stack[++top]=i;
    for(e=head[i];e+1;e=Edge[e].next)
    {
        int v=Edge[e].to;
        if(!dfn[v])
        {
            tarjan(v);
            low[i]=min(low[i],low[v]);
        }
        else if(instack[v])
            low[i]=min(low[i],low[v]);
    }

    if(dfn[i]==low[i])
    {
        sccc++;
        do
        {
            e=Stack[top--];
            instack[e]=0;
            belong[e]=sccc;
        }while(e!=i);
    }
}
int main()
{
    init();
    int u,v;
    scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++)
            scanf("%d %d",&u,&v),addedge(u,v,i);

        for(int i=1;i<=n;i++)
            if(!dfn[i])
                tarjan(i);

        for(int i=1;i<=n;i++)
            for(int e=head[i];e+1;e=Edge[e].next)
                if(belong[i]!=belong[Edge[e].to])
                    outdeg[belong[i]]++;
        int OUT_num=0,import;
        for(int i=1;i<=sccc;i++)
            if(!outdeg[i])//如果缩点的出度为0的个数大于1，则图不联通
                OUT_num++,import=i;//重要点就是这个出度为0的点集的强连通序号

        int SUM=0;
        if(OUT_num==1)
        {
            for(int i=1;i<=n;i++)
                if(belong[i]==import)
                    SUM++;
            printf("%d\n",SUM);
        }
        else
            printf("0\n");
    return 0;
}
