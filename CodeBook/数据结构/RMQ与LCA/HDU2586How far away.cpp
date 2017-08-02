//离线算法
/*
#include <bits/stdc++.h>
//LCA-tarjan+并查集的离线算法
//题意：给出一个无环无向图,Q次询问任意两点距离
//分析：离线处理算出LCA　那么任意两点(i,j)的距离就可以表示成
//离线算法流程：通过深搜
//dir[i]+dir[j]-2*dir[LCA(i,j)] dir[x] 为x到根的距离

const int maxn = 40000+7;
const int maxQ = 200+7;
using namespace std;

int father[maxn];
int find(int x)
{
    if(father[x]==-1) return x;
    return father[x]=find(father[x]);
}
void merge(int u,int v)
{
    int fu = find(u), fv = find(v);
    if(fv != fu)
        father[fv]=fu;
}
int dis[maxn];
bool vis[maxn];//访问标记

struct Edge
{
    int to,next,w;
}e[maxn<<1];
int tot=0, head[maxn<<1];
void addedge(int u,int v,int w)
{
    e[tot].to =v;
    e[tot].w = w;
    e[tot].next = head[u];
    head[u] = tot++;
}

vector<int> query[maxn];
vector<int> num[maxn];
int ans[maxn];
void init()
{
    tot=0;
    memset(father,-1, sizeof(father));
    memset(vis,0, sizeof(vis));
    memset(head,-1, sizeof(head));
    memset(dis,0,sizeof(dis));
    memset(ans,0, sizeof(ans));
    for(int i=0;i<maxn;i++)
    {
        query[i].clear();
        num[i].clear();
    }

}
void tarjan(int u,int val)
{
    vis[u]=1;
    dis[u]=val;
    for(int i=head[u];~i;i=e[i].next)
    {
        int to = e[i].to;
        if(vis[to]) continue;
        tarjan(to,val+e[i].w);
        merge(u,to);//当遍历完一棵子树就将该子树和父亲节点u合并
    }
    for(int i=0;i<query[u].size();i++)//处理完u节点的子树就可以回答有关u的询问
    {
        int to = query[u][i];
        if(vis[to]==0) continue;//如果to被访问过就可以回答这个询问

        ans[num[u][i]] = dis[u]+dis[to]-2*dis[find(to)];//find(to)就是lca(u,i)
    }
}
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        init();
        int n,m;scanf("%d%d",&n,&m);
        for(int i=1;i<n;i++)
        {
            int a,b,c;scanf("%d%d%d",&a,&b,&c);
            addedge(a,b,c);
            addedge(b,a,c);
        }

        for(int i=0;i<m;i++)
        {
            int n1,n2;scanf("%d%d",&n1,&n2);
            query[n1].push_back(n2);
            num[n1].push_back(i);//记录回答顺序
        }
        tarjan(1,0);
        for(int i=0;i<m;i++)
            printf("%d\n",ans[i]);
    }
    return 0;
}

 */
在线算法
预备指示 RMQ dp
RMQ(区间最值查询) ST+dfs 算法
对于长度为n的序列a定义dp[i][j]表示从a[i]开始长度为2^j的区间的最值。
对于dp[i][j]这偶数个数字a[i,i+1,i+2···i+2^j-1],
区间拆成a[i, i+2^(j-1)-1] + a[i+2^(j-1), i+2^j-1] 每段长度都是2^(j-1)
得出转移方程dp[i][j]=min/max(dp[i][j-1],dp[i-2^(j-1)][j-1]),
则对于每次询问[L,R]的最值,取找到这个区间的最下幂
区间长度j-i+1 取k = log2(j-i+1) RMQ(a,i,j)=max(dp[i][k],dp[j-2^k+1][k])
能做到预处理O(nlogn)(可优化质O(n)) 查询O(1)
初状态dp[i][0]=a[i]
#include <bits/stdc++.h>
using namespace std;
const int N = 50005;
int maxdp[N][20], mindp[maxn][20];
int dp[N][20];
void init(int n)
{
    int k = log2(n);
    for(int j = 1; j<=k; ++j)
        for(int i = 1; i + (1 << j) - 1 <= n; ++i)
        {
            maxdp[i][j] = max(maxdp[i][j - 1], maxdp[i + (1 << (j - 1))][j - 1]);
            mindp[i][j] = max(mindp[i][j - 1], mindp[i + (1 << (j - 1))][j - 1]);
        }
}

pair<int,int> RMQ(int l, int r)
{
    if(l > r) swap(l, r);
    int k = log2(r-l+1.0);
    MAX =  max(maxdp[l][k], maxdp[r - (1 << k) + 1][k]);
    MIN =  min(mindp[l][k], mindp[r - (1 << k) + 1][k])
    return make_pair(MIN,MAX); 
}

int main()
{
    int num, query;
    while(scanf("%d %d", &num, &query) != EOF)
    {
        for(int i = 1; i <= num; ++i)
        {
            scanf("%d", &mindp[i][0]);
            maxdp[i][0]=maxdp[i][0];
        }
        init(num);
        while(query--)
        {
            int a,b;scanf("%d%d", &a, &b);
            pair<int,int> ans = RMQ(a,b);
        }
    }
    return 0;
}


//补在线做法
#include<bits/stdc++.h>
const int maxn = 40000+111;
using namespace std;
int dp[maxn<<1][25];
int ver[maxn<<1];
int dep[maxn<<1];
int vis[maxn];
int dir[maxn];
int first[maxn];
int head[maxn];
int tot,cnt;
struct Edge
{
    int to, next, w;
}edge[maxn<<1];
void addedge(int u,int v,int w)
{
    edge[tot].to = v;
    edge[tot].next = head[u];
    edge[tot].w = w;
    head[u] = tot++;
}

void init()
{
    memset(dp,0,sizeof(dp));
    memset(vis,0,sizeof(vis));
    memset(head,-1,sizeof(head));
    memset(dir,0, sizeof(dir));
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
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        init();
        int n,m;scanf("%d %d",&n,&m);
        for(int i=1;i<n;i++)
        {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            addedge(a,b,c);
            addedge(b,a,c);
        }
        dfs(1,1);ST(2*n-1);
        while(m--)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            printf("%d\n",dir[u]+dir[v]-dir[LCA(u,v)]*2);
        }
    }
    return 0;
}
