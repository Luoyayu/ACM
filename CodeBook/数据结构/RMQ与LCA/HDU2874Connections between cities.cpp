#include<bits/stdc++.h>
//并查集判断在不在一棵树上
const int maxn = 20000+11;
typedef long long ll;
using namespace std;
int dp[maxn<<1][25];
int ver[maxn<<1];
int dep[maxn<<1];
int vis[maxn<<1];
int dir[maxn<<1];
int first[maxn<<1];
int head[maxn<<1];
int tot,cnt;
int F[maxn<<1];//并查集
struct Edge
{
    int to, next, w;
}edge[maxn<<2];

void addedge(int u,int v,int w)
{
    edge[tot].to = v;
    edge[tot].next = head[u];
    edge[tot].w = w;
    head[u] = tot++;
}

void init()
{
    memset(edge,0, sizeof(edge));
    memset(dp,0,sizeof(dp));
    memset(vis,0,sizeof(vis));
    memset(head,-1,sizeof(head));
    memset(dir,0, sizeof(dir));
    for(int i=0;i<maxn;i++)
        F[i]=i;
    dir[1]=0;
    cnt = tot = 0;
}

void dfs(int u,int dfn)
{
    vis[u]=1;ver[++cnt] = u;first[u]=cnt;dep[cnt]=dfn;
    for(int i = head[u];~i;i=edge[i].next)
    {
        int v = edge[i].to;
        int w = edge[i].w;
        if(!vis[v])
        {
            dir[v] = dir[u]+w;
            dfs(v,dfn+1);
            ver[++cnt] = u;
            dep[cnt] = dfn;
        }
    }
}


void ST(int n)
{
    int k = int (log2(n));
    for(int i=1;i<=n;i++)   dp[i][0]=i;
    for(int j=1;j<=k;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
        {
            int a = dp[i][j-1];
            int b = dp[i+(1<<(j-1))][j-1];

            if(dep[a]<dep[b]) dp[i][j]=a;
            else dp[i][j]=b;
        }
}
int RMQ(int l,int r)
{
    int k = int(log2(r-l+1.0));
    int a = dp[l][k];
    int b = dp[r-(1<<k)+1][k];
    if(dep[a]<dep[b]) return a;
    return b;
}
int LCA(int u,int v)
{
    int x = first[u], y = first[v];
    if(x>y) swap(x,y);
    return ver[RMQ(x,y)];
}
int find(int x)
{
    if(F[x]==x) return F[x];
    else return F[x]=find(F[x]);
}
void merge(int x,int y)
{
    int fx = find (x);
    int fy = find (y);
    if(fx!=fy)
        F[fy]=fx;
}

int main()
{
    int n,m,q;
    while(scanf("%d%d%d",&n,&m,&q)!=EOF)
    {
        init();
        for(int i=1;i<=m;i++)
        {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            addedge(a,b,c);
            addedge(b,a,c);
            merge(a,b);
        }
        for(int i=1;i<=n;i++)
            if(!vis[i])//对于没跑过的点跑下!!!!!
                dfs(i,1);
        ST(2*n-1);
        while(q--)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            if(find(u)!=find(v))
            {
                printf("Not connected\n");
                continue;
            }
            int short_path = dir[u]+dir[v]-dir[LCA(u,v)]*2;
            printf("%d\n",short_path);
        }
    }
    return 0;
}
