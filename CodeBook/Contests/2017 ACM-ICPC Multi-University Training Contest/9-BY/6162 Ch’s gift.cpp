//LCA水题啊还好队友机智两发就看出来W在long long 上
#include<bits/stdc++.h>
typedef long long ll;
const int maxn = 100000+111;
using namespace std;
int dp[maxn<<1][25];
int ver[maxn<<1];
int dep[maxn<<1];
int quan[100010];
int vis[maxn];
vector<int> dir[maxn];//记录每个节点到根节点路径上的所有点权
int first[maxn];
int head[maxn];
int tot,cnt;
struct Edge
{
    int to,next;
}edge[maxn<<1];
void addedge(int u,int v)
{
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}
void init(int n)
{
    memset(dp,0,sizeof(dp));
    memset(vis,0,sizeof(vis));
    memset(head,-1,sizeof(head));
    for(int i=0;i<=n;i++)
        dir[i].clear();
    cnt = tot = 0;
}
void dfs(int u,int dfn)
{
    vis[u]=1;ver[++cnt] = u;first[u]=cnt;dep[cnt]=dfn;
    for(int i = head[u];~i;i=edge[i].next)
    {
        int v = edge[i].to;
        if(!vis[v])
        {
            dir[v].assign(dir[u].begin(),dir[u].end());//现学的技能担心会在这里被卡,标算维护的是treap
            dir[v].push_back(quan[v]);
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
int main()
{
    int n,m;
    while(~scanf("%d %d",&n,&m))
    {
        init(n);
        for(int i=1;i<=n;i++)
            scanf("%d",&quan[i]);
        for(int i=1;i<=n-1;i++)
        {
            int a,b; scanf("%d %d",&a,&b);
            addedge(a,b); addedge(b,a);
        }
        dir[1].push_back(quan[1]);
        dfs(1,1); ST(2*n-1);
        while(m--)
        {
            int s,t,a,b;
            scanf("%d%d%d%d",&s,&t,&a,&b);
            int v=LCA(s,t);
            ll sum=0;
            for(int i=0;i<dir[s].size();i++)
                if(dir[s][i]<=b&&dir[s][i]>=a)
                    sum+=dir[s][i];

            for(int i=0;i<dir[t].size();i++)
                if(dir[t][i]<=b&&dir[t][i]>=a)
                    sum+=dir[t][i];

            for(int i=0;i<dir[v].size();i++)
                if(dir[v][i]<=b&&dir[v][i]>=a)
                    sum-=2*dir[v][i];

            if(quan[v]>=a&&quan[v]<=b)//和维护最短路不同，这里我们每个边对应它深度较大的点权所以最后得加上合适的拐点
                sum+=quan[v];

            printf("%I64d%c",sum,m==0?'\n':' ');
        }
    }
    return 0;
}