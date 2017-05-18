//强连通缩点+最小路径覆盖
//将互通的点缩点染色，最小覆盖数=点数(强连通数)-二分匹配数
#include<cstdio>
#include<cstring>
#include<algorithm>
#define next NEXT
using namespace std;
const int maxn=5000+55;
const int maxm=100000+55;
struct Egde
{
	int next,to;
}edge[maxn],edge2[maxn];
int low[maxn],dfn[maxn],num[maxn],belong[maxn],Stack[maxn];
bool instack[maxn],used[maxn];
//int indeg[maxn],outdeg[maxn];
int scc,index,top;
int head[maxn],head2[maxn],tot,tot2;
int n,m;
int linker[maxn];
void init()
{
    tot=tot2=top=scc=index=0;
	for(int i=0;i<maxn;i++)
    {
        head[i]=head2[i]=linker[i]=-1;
        low[i]=dfn[i]=num[i]=belong[i]=Stack[i]=instack[i]=0;
        //indeg[i]=outdeg[i]=0;
    }
}
void add(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}
void add2(int u,int v)
{
    edge2[tot2].to=v;
    edge2[tot2].next=head2[u];
    head2[u]=tot2++;
}
void Tarjan(int u)
{
    int v;
    low[u]=dfn[u]=++index;
    instack[u]=1;
    Stack[top++]=u;
    for(int i=head[u];i+1;i=edge[i].next)
    {
        v=edge[i].to;
        if(!dfn[v])
        {
            Tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(instack[v]&&low[u]>low[v])
            low[u]=dfn[v];
    }
    if(low[u]==dfn[u])
    {
        scc++;
        do
        {
            v=Stack[--top];
            instack[v]=0;
            belong[v]=scc;
            num[scc]++;
        }while(v!=u);
    }
}

bool dfs(int u)
{
    for(int i=head2[u];i+1;i=edge2[i].next)
    {
        int v=edge2[i].to;
        if(!used[v])
        {
            used[v]=1;
            if(linker[v]==-1||dfs(linker[v]))
            {
                linker[v]=u;
                return 1;
            }
        }
    }
    return 0;
}
int hungary(int uN)
{
    int ans=0;
    for(int u=1;u<=uN;u++)
        memset(used,0,sizeof used),ans+=dfs(u);
    return ans;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
    {
        scanf("%d %d",&n,&m);
        int U,V;
        while(m--)
            scanf("%d %d",&U,&V),add(U,V);
        init();
        for(int i=1;i<=n;i++)
            if(!dfn[i])
                Tarjan(i);
        for(int i=1;i<=n;i++)
            for(int j=head[i];j+1;j=edge[j].next)
            {
                int v=edge[j].to;
                if(belong[i]!=belong[v])
                    add2(belong[i],belong[v]);
            }
        //printf("%d %d\n",scc,hungary(scc));
        printf("%d\n",scc-hungary(scc));
    }
    return 0;
}
