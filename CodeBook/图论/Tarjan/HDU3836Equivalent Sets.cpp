//集合相等传递性 1->2->3->4->1
//求最小数量的边使得个强连通分量之间联通
#include<cstdio>
#include<cstring>
#include<stack>
#include<vector>
#include<algorithm>
#define next NEXT
using namespace std;
const int maxn=20000+222;
const int maxm=50000+555;
int dfn[maxn],low[maxn],belong[maxn],Stack[maxn];//belong[1~scc]=r 该强连通的最小代表点
int scc,cnt,top,index,num[maxn];//num[1~scc]各个连通分量包含的点的个数
int head[maxn],tot=0;
bool instack[maxn];
int indeg[maxn],outdeg[maxn];
int N;
struct node
{
    int to,next;
}edge[maxm];
void add(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}
void init()
{
    index=tot=scc=top=0;
    for(int i=0;i<maxn;i++)
    {
        dfn[i]=low[i]=belong[i]=Stack[i]=instack[i]=indeg[i]=outdeg[i]=num[i]=0;
        head[i]=-1;
    }
}
void Tarjan(int u)
{
    int v;
    low[u]=dfn[u]=++index;
    Stack[top++]=u;
    instack[u]=1;
    for(int i=head[u];i+1;i=edge[i].next)
    {
        v = edge[i].to;
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
int main()
{
    int x,y,m;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&N,&m);

        if(m==0)
            printf("%d\n",N);
        else
        {
            init();
            while(m--)
                scanf("%d%d",&x,&y),add(x,y);
            for(int i=1;i<=N;i++)
                if(!dfn[i])Tarjan(i);
            if(1==scc)
                printf("0\n");
            else
            {
                for(int i=1;i<=N;i++)
                    for(int j=head[i];j+1;j=edge[j].next)
                    {
                        int v=edge[j].to; //i-> v
                        if(belong[i]!=belong[v])//遍历边处理强连通分量 如果 i,v不在一个强连通中意味着
                            indeg[belong[v]]++,outdeg[belong[i]]++; //v所在的强连通分量入度++, i所在的强连通分量出度++;
                    }
                int t1=0,t2=0;
                for(int i=1;i<=scc;i++)
                {
                    if(!indeg[i]) t1++;
                    if(!outdeg[i]) t2++;
                }
                printf("%d\n",max(t1,t2));
            }
        }
    }

    return 0;
}
