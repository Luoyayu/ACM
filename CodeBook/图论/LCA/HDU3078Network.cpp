#include <bits/stdc++.h>
//奋起吧LCA+在线修改+查询
//LCA爬路径sort
using namespace std;
const int maxn = int(8e4+7);
int ver[maxn<<1];
int first[maxn];
bool vis[maxn];
int len[maxn<<1];
int dep[maxn<<1];
int fa[maxn];//记录前驱节点
int val[maxn];
vector<int> e[maxn];
int cnt;
int dp[maxn<<1][25];

bool cmp(int &a,int &b)
{
    return a>b;
}

void init()
{
    for(int i=0;i<maxn;i++)
        e[i].clear();
    memset(fa,0, sizeof(fa));
    memset(dp,0,sizeof(dp));
    memset(len,0, sizeof(len));
    memset(vis,0, sizeof(vis));
}
void dfs(int u,int dfn,int par)
{
    vis[u]=1;
    first[u]=++cnt;ver[cnt]=u;dep[cnt]=dfn;fa[u]=par;
    for(int i=0;i<e[u].size();i++)
        if(!vis[e[u][i]])
        {
            dfs(e[u][i],dfn+1,u);
            ver[++cnt]=u;dep[cnt]=dfn;
        }
}

void ST(int n)
{
    int k = int (log2(n));
    for(int i=1;i<=n;i++)
        dp[i][0]=i;
    for(int j=1;j<=k;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
        {
            int a = dp[i][j-1];
            int b = dp[i+(1<<(j-1))][j-1];
            dp[i][j]=(dep[a]<dep[b]?a:b);
        }
}

int RMQ(int l,int r)
{
    int k = int (log2(r-l+1.0));
    int a = dp[l][k];
    int b = dp[r-(1<<k)+1][k];
    if(dep[a]<dep[b]) return a;
    return b;

}

int LCA(int u,int v)
{
    int x = first[u];
    int y = first[v];
    if(x>y) swap(x,y);
    return ver[RMQ(x,y)];
}
void retPath(int &index,int s,int t)
{
    while(s != t)
    {
        len[index++] = val[s];
        s = fa[s];
    }
    len[index++] = val[t];
}

void solve(int kth, int u, int v)
{
    int lca_uv = LCA(u,v);
    //printf("LCA :%d\n",lca_uv);
    int cnt = 0;
    retPath(cnt,u,lca_uv); //此处由深到浅还原路径，勿忘
    retPath(cnt,v,lca_uv);
    cnt--;
    if(kth>cnt)
        printf("invalid request!\n");
    else
    {
        sort(len,len+cnt,cmp);
        printf("%d\n",len[kth-1]);
    }
    return ;
}

int main()
{
    int n,q;
    init();
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) scanf("%d",&val[i]);
    for(int i=1;i<n;i++)
    {
        int u,v;scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1,1,-1);
    ST(2*n-1);
    
    for(int i=0;i<q;i++)
    {
        int op,x,y;
        scanf("%d%d%d",&op,&x,&y);
        if(!op) val[x]=y;
        else solve(op,x,y);
    }
     /*
    for(int i=1;i<=5;i++)
        printf("fa: %d\n",fa[i]);
        */
    return 0;
}