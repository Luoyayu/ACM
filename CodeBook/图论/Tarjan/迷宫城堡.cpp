#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=10005;
#define mt(ar,num) memset((ar),(num),sizeof(ar))
vector<int>mp[maxn];
int vis[maxn],dfn[maxn],low[maxn];
int n,m,cnt,scc_c;
inline void init()
{
    cnt=1;scc_c=0;
    mt(low,0),mt(vis,0),mt(dfn,0);
    for(int i=1;i<=n;i++)
        mp[i].clear();
}

void tarjan(int u)
{
    vis[u]=1;
    low[u]=dfn[u]=cnt++;
    for(int i=0;i<mp[u].size();i++)
    {
        int v=mp[u][i];
        if(!vis[v])
            tarjan(v);
        if(vis[v])
            low[u]=min(low[u],low[v]);
    }
    if(dfn[u]==low[u])
        scc_c++;
}
inline void solve()
{
    for(int i=1;i<=n;i++)
        if(!vis[i])
            tarjan(i);
    if(scc_c==1)
        printf("Yes\n");
    else
        printf("N0\n");
        //printf("%d\n",scc_c);
}
int main()
{
   while(scanf("%d %d",&n,&m)!=EOF && (n||m))
   {
       init();
       for(int i=0;i<m;i++)
       {
           int x,y;
           scanf("%d %d",&x,&y);
           mp[x].push_back(y);
       }
       solve();
   }
   return 0;
}
