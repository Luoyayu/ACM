#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
#include<map>
#include<iostream>
#include<string>
using namespace std;
const int maxn=1000 + 5;
const int INF = 0x3f3f3f3f;
int n,m;
struct Edge
{
    int from,to,cost;
    Edge(){}
    Edge(int f,int t,int c):from(f),to(t),cost(c){}
};
vector<int> G[maxn];
vector<Edge> edge;
map<string,int> mp;
bool inque[maxn];
int dis[maxn];
void init()
{
    edge.clear();
    mp.clear();
    for(int i=0;i<maxn;i++)
    {
        G[i].clear();
        inque[i]=0;
    }
}
void add(int u,int v,int w)
{
    edge.push_back(Edge(u,v,w));
    int m=edge.size();
    G[u].push_back(m-1);
}
int SPFA(int s)
{
    for(int i=0;i<n;i++)
        dis[i]=INF;
    dis[s]=0;inque[s]=1;
    queue<int>q;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();
        inque[u]=false;q.pop();
        for(int i=0;i<(int)G[u].size();i++)
        {
            Edge e = edge[G[u][i]];
            if(dis[e.to]>dis[u]+e.cost)
            {
                dis[e.to]=dis[u]+e.cost;
                if(!inque[e.to])
                {
                    inque[e.to]=1;
                    q.push(e.to);
                }
            }

        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        ans=max(ans,dis[i]);
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);
    while(scanf("%d",&n)!=EOF,n)
    {
        init();
        int cnt=1;
        char a[20],b[20];
        for(int i=0;i<n;i++)
        {
            scanf("%s",a);
            if(mp[a]==0)
                mp[a]=cnt++;
        }
        scanf("%d",&m);
        while(m--)
        {
            scanf("%s %s",a,b);
            int u=mp[a],v=mp[b];
            add(u,v,1);
            add(v,u,1);
        }
        int ans=0;
        for(int i=1;i<=n;i++)
            ans=max(ans,SPFA(i));
        printf("%d\n",ans==INF?-1:ans);
    }
    return 0;
}
