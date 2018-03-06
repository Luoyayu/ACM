#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int N = 100000 +  10;
typedef long long ll;
struct point
{
    int from,to;
    ll dis;
    point (int from,int to,ll dis):from(from),to(to),dis(dis){}
};
ll a[N],dp[N];
int mark[N],father[N];
vector<point>G[N];
void dfs(int u)
{
    mark[u]=1;
    for(int i=0;i<G[u].size();i++)
    {
        int to=G[u][i].to;
        int dis=G[u][i].dis;
        if(mark[to]==0)
        {
            dp[to]=min(dp[u]+a[u],dp[u]+dis);
            int root=father[u];
            while(root!=1)
            {
                dp[to]=min(dp[to],dp[root]+a[root]);
                root=father[root];
            }
            if(root==1)
            dp[to]=min(dp[to],a[1]);
            dfs(to);
        }
    }
    return ;
}
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        for(int i=0;i<N;i++)
            mark[i]=dp[i]=a[i]=father[i]=0,G[i].clear();
        for(int i=1;i<=n;i++)
            scanf("%I64d",&a[i]);
        father[1]=1;
        for(int i=1;i<n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            G[x].push_back(point(x,i+1,(ll)y));
            father[i+1]=x;
        }
        dfs(1);
        for(int i=1;i<=n;i++)
            printf("%I64d ",dp[i]);
        printf("\n");
    }
    return 0;
}
