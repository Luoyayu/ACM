//可能是树状数组+树剖
//注意若查询修改规模较大时,通过前缀和模拟树状数组
#include <bits/stdc++.h>
using namespace std;
const int maxn = 100001;
typedef  long long ll;
//#pragma comment(linker, "/STACK:1024000000,1024000000") //这两个dfs还是不会爆栈的

//**************************************************基本数据
int se[maxn][2];
ll ans_edge[maxn];
ll ans_node[maxn];
//*************************************************数据结构
int head[maxn];
int tot_edge;
struct E
{
    int to,next,w;
}e[maxn<<1];
void addedge(int u, int v,int w=0)
{
    e[tot_edge].to = v;
    e[tot_edge].next = head[u];
    head[u] = tot_edge++;
}
//*****************************************************  建立有根树+树链剖分
int son[maxn], fa[maxn], sz[maxn], dep[maxn], id[maxn];
int fid[maxn], Top[maxn];
int cnt = 1;
void dfs(int u, int pre, int d)
{
    dep[u] = d; fa[u] = pre; sz[u] = 1;
    for(int i = head[u]; ~i; i = e[i].next)
    {
        int v = e[i].to;
        if(v != pre)
        {
            dfs(v, u, d+1);
            sz[u] += sz[v];
            if(son[u]==-1 || sz[v] > sz[son[u]])
                son[u] = v;
        }
    }
}

void dfs2(int u, int sp)
{
    Top[u] = sp;
    id[u] = cnt++;fid[id[u]] = u;
    if(son[u]==-1) return ;
    dfs2(son[u], sp);
    for(int i = head[u]; ~i; i = e[i].next)
    {
        int v = e[i].to;
        if(v != son[u]&&v!=fa[u]) dfs2(v, v);
    }
}
//******************************************************* //树链操作
void Change(char type, int u,int v,int k)
{
    if(type=='1')//维护点
    {
        int tu = Top[u],tv = Top[v];
        while(tu != tv)
        {
            if(dep[tu] < dep[tv])
            {
                swap(u,v);
                swap(tu,tv);
            }
            ans_node[ id[tu] ] += k;  //增益标记
            ans_node[ id[u]+1 ] -= k;
            u = fa[tu];tu = Top[u];
        }
        if(dep[u] > dep[v]) swap(u,v);
        ans_node[ id[u]    ] += k;
        ans_node[ id[v] + 1] -= k;
    }

    else//维护边
    {
        int tu = Top[u],tv = Top[v];
        while(tu != tv)
        {
            if(dep[tu] < dep[tv])
            {
                swap(u,v);
                swap(tu,tv);
            }
            ans_edge[ id[tu] ] += k;
            ans_edge[ id[u]+1 ] -= k;
            u = fa[tu];tu = Top[u];
        }
        if(dep[u] > dep[v]) swap(u,v);
        ans_edge[ id[u] + 1 ] += k;//注意在同一条链上边权的维护姿势,边权由该边的深度较大的节点维护
        ans_edge[ id[v] + 1 ] -= k;
    }
}
//*******************************************************初始化
#define clr(x,y) memset(x,y,sizeof(x))
void init()
{
    clr(head,-1);clr(son,-1);
    clr(ans_edge,0);clr(ans_node,0);
    clr(sz,0);cnt = 1;tot_edge = 0;
}
//*****************************************************
int main()
{
    int t;scanf("%d",&t);
    for(int kase = 1; kase<=t; kase++)
    {
        init();
        int n,m;scanf("%d%d",&n,&m);
        for(int i=1;i<n;i++)
        {
            int u,v;scanf("%d%d",&u,&v);
            se[i][0] = u; se[i][1] = v;
            addedge(u,v); addedge(v,u);
        }
        dfs(1,0,0);dfs2(1,1);
        while(m--)
        {
            char op[10];scanf("%s",op);
            int u,v,k;scanf("%d %d %d",&u,&v,&k);
            Change(op[3],u,v,k);
        }

        for(int i=2;i<=n;i++) //前缀和即每个点/边的值
        {
            ans_node[i] += ans_node[i-1];
            ans_edge[i] += ans_edge[i-1];
        }
        printf("Case #%d:\n",kase);
        for(int i=1;i<n;i++)
            printf("%lld ",ans_node[id[i]]);
        printf("%lld\n",ans_node[id[n]]);

        bool flag = 0;
        for(int i = 1; i <= n-1; i++)
        {
            if(dep[ se[i][0] ] < dep[ se[i][1] ])//保证该边由深度较大的点维护
                swap(se[i][0],se[i][1]);
            if(flag == 0)
                printf("%lld",ans_edge[ id[se[i][0]] ]),flag = 1;
            else printf(" %lld",ans_edge[ id[se[i][0]] ]);
        }
        printf("\n");
    }
    return 0;
}
