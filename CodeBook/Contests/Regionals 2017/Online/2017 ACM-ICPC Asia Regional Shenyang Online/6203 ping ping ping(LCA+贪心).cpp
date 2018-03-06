//好题lca+贪心
//题意：给出一棵有根树根节点标号 0，给出k个点对 (u,v)表示从u到v的路径(含u,v)上有一点坏掉，问最少坏掉几个点
#include <bits/stdc++.h>
using namespace std;
//ping ping ping
//本题得贪心策略 ：本题不是单纯得删除lca(u,v)，例如对于一条链上的(root,a1,a2,a3) lca(root, a1)=root lca(a1,a3)=a1 ；那么不是删去root 而是删去a1即可断开两条通信恰好是lca深度较大的点应该删去，所以原本深度最小的lca没有必要删去
//解决办法：问题在于删去的点一定是lca,那么每次删去lca后暴力dfs，把删去lca的子树的所有未被标记的点都标记一遍，这样标记算法O(N)N为子树节点数，然后按照点对lca的深度从深到浅处理，如果当前点对两个有一个已经被标记，说明两点已经断开了，没有必要再次删除，否则断开，标记lca子树。如此贪心即可。
const  int maxn = 1e4 + 7;
struct query { int u,v,dep,lca;};
bool operator <(query a, query b)//排序lca深度
{return a.dep<b.dep;}
priority_queue<query> que;
#define clr(a,b) memset(a,b,sizeof(a));
bool vis[maxn];

namespace LCA
{
    int head[maxn];
    int edge_tot;
    struct {int to,next;}edge[maxn<<1];
    void addedge(int u,int v)
    {
        edge[edge_tot].to = v;
        edge[edge_tot].next = head[u];
        head[u] = edge_tot ++;
    }
    int son[maxn],dep[maxn],fa[maxn],id[maxn],sz[maxn],Top[maxn];
    int cnt;
    void dfs(int u,int pre,int d)
    {
        dep[u] = d; fa[u] = pre; sz[u] = 1;
        for(int i = head[u]; ~i; i = edge[i].next)
        {
            int v = edge[i].to;
            if(v != pre)
            {
                dfs(v,u,d+1); sz[u]+=sz[v];
                if(son[u]==-1 || sz[v]>sz[son[u]]) son[u]=v;
            }
        }
    }
    void dfs2(int u,int sp)
    {
        Top[u] = sp;id[u] = cnt ++;
        if(son[u]==-1) return;
        dfs2(son[u], sp);
        for(int i=head[u]; ~i; i =edge[i].next)
        {
            int v = edge[i].to;
            if(v != son[u] && v != fa[u])dfs2(v,v);
        }
    }
    int LCA(int x,int y)
    {
        for(;Top[x]!=Top[y];dep[Top[x]]>dep[Top[y]]?x=fa[Top[x]]:y=fa[Top[y]]){}
        return dep[x]<dep[y]?x:y;
    }
    void init()
    {
        memset(son,-1, sizeof(son));
        memset(head,-1, sizeof(head));
        edge_tot = 0;
        cnt = 0;
    }
}

void dfs(int u)
{
    vis[u]=1;
    for(int i=LCA::head[u];~i;i=LCA::edge[i].next)
    {
        int v = LCA::edge[i].to;
        if(!vis[v]&&LCA::dep[v]>LCA::dep[u]) dfs(v);
    }
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        LCA::init();clr(vis,0);while(!que.empty())que.pop();
        int ans = 0;
        for(int i=1;i<=n;i++)
        {
            int u,v;scanf("%d%d",&u,&v);//注意起点从0开始
            LCA::addedge(++u,++v);LCA::addedge(v,u);
        }
        LCA::dfs(1,0,0);LCA::dfs2(1,1);
        int q;scanf("%d",&q);
        while(q--)
        {
            int u,v,lca,dep;
            scanf("%d %d",&u,&v);
            lca = LCA::LCA(++u,++v);
            dep = LCA::dep[lca];
            que.push(query{u,v,dep,lca});
        }
        while(!que.empty())
        {
            int u = que.top().u, v = que.top().v;
            int lca = que.top().lca;que.pop();
            if(vis[u]||vis[v]) continue;//两端点之一已经访问过pass
            ans++;dfs(lca);
        }
        printf("%d\n",ans);
    }
    return 0;
}
