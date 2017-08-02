//#define Local
#include <bits/stdc++.h>
//题意：给出一棵树，并且给出每个点的权值，有三种操作
//I C1 C2 k 把C1 与 C2路径上的所有点权加上k
//D 减去 k
//Q C 查询C的点权
using namespace std;
const int maxn = 50000+7;
#define lowbit(x) x&(-x)
//************************************************************//基本数组
int a[maxn];
//************************************************************//邻接表
int edge_tot;
int head[maxn];
//vector<int> G[maxn];//
struct Edge
{
    int to,next,w;
}edge[maxn<<1];
void addedge(int u,int v,int w = 0)
{
    edge[edge_tot].to = v;
    edge[edge_tot].next = head[u];
    edge[edge_tot].w = w;
    head[u]=edge_tot++;
}
//******************************************************************//树链剖分

int sz[maxn];  //sz[u] 以u为根的子树的size
int dep[maxn]; //dep[u] u结点的深度 u到root的距离+1
int fa[maxn]; //fa[u] u的父亲
int son[maxn];//son[u] u 的重儿子
int id[maxn]; //剖分后的边在新的数据结构中的位置着重记录一条重链上的相对位置
//这个id[u]存的是(v,u)边的编号v是u其的父亲，也可以代表u的相对编号
//TODO：@@此处维护点权@@
int fid[maxn];//与id含义相反
int Top[maxn];//u所在树链起点 u,v在同一树链中当且仅当Top[u]==Top[v]
int cnt;//已编号数量

void dfs1(int u, int pre, int d)//建有根树 求出sz[],depth[],fa[],son[]
{
    dep[u] = d; fa[u] = pre; sz[u] = 1;
    for(int i = head[u]; ~i; i = edge[i].next)
    {
        int v =  edge[i].to;
        int w = edge[i].w;
        if(v != pre)
        {
            dfs1(v,u,d+1);
            sz[u]+=sz[v];
            if(son[u] == -1 || sz[v] > sz[son[u]])
                son[u] = v;
        }
    }
}

void dfs2(int u, int sp) //剖分有根树 求出id[], Top[]1
{
    Top[u] = sp; //根节点是第一条链
    id[u] = cnt ++;
    fid[id[u]] = u;
    if(son[u]==-1) return;//没有重儿子推出分支
    dfs2(son[u], sp);
    for(int i=head[u]; ~i; i =edge[i].next)
    {
        int v = edge[i].to;
        int w = edge[i].w;
        if(v != son[u] && v != fa[u])
            dfs2(v,v); //其他点的top标号为自身
    }
}

//**********************************************************//树状数组
int c[maxn];
int n;
void add(int pos,int val)
{
    while(pos<=n)
    {
        c[pos]+=val;
        pos += lowbit(pos);
    }
}
int sum(int pos)
{
    int s = 0;
    while(pos>0)
    {
        s += c[pos];
        pos -=lowbit(pos);
    }
    return s;
}

void Update(int u, int v, int k)
{
    int tu = Top[u], tv = Top[v];
    while(tu != tv) //u ,v 在不同的树链上时我们需要逼近
    {
        if (dep[tu] < dep[tv]) //保证u处于树链靠下的位置较深的位置
        {
            swap(tu,tv);
            swap(u,v);
        }
        add(id[tu],k);add(id[u]+1,-k);
        u = fa[tu];
        tu = Top[u];
    }
    if(dep[u]>dep[v]) swap(u,v);
    add(id[u], k);add(id[v]+1,-k);
}
//*************************************************************//初始化
void init()
{
    edge_tot = 0;cnt = 1;//树状数组编号从1开始
    memset(head, -1, sizeof(head));
    memset(son, -1, sizeof(son));
    memset(c, 0, sizeof(c));
}
int main()
{
#ifdef Local
    freopen("input.txt","w",stdin);
    freopen("output.txt","r",stdout);
#endif

    int M,P;
    while(scanf("%d%d%d",&n,&M,&P)!=EOF)
    {
        int u,v,C1,C2,K;
        char op[10];
        init();
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        while(M--)
        {
            scanf("%d%d",&u,&v);
            addedge(u,v);addedge(v,u);
        }
        dfs1(1,0,0);
        dfs2(1,1);
        for(int i=1;i<=n;i++)//树状数组维护每条树链
        {
            add(id[i], a[i]);
            add(id[i]+1, -a[i]);//查询单点
        }
        while(P--)
        {
            scanf("%s",op);
            if(op[0] == 'Q')
            {
                scanf("%d", &C1);
                printf("%d\n",sum(id[C1]));
            }
            else
            {
                scanf("%d%d%d", &C1, &C2, &K);
                if(op[0]=='D') K=-K;
                Update(C1, C2 ,K);
            }
        }
    }
    return 0;
}