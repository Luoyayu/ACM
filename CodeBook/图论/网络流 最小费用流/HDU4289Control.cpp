///给定图去掉某些点需要话费，求最小话费使得图不联通 最小割==最大流
///连一条自己到自己的边(i->i+n)
///剩下对于图中的边 a,b 连上a+n->b ||  b+n->a
#include <bits/stdc++.h>
using namespace std;
const int N =  20000,inf=1e9+7;
class Dinic
{
public:
    struct point
    {
        int from,to,cap,flow;
        point(int from,int to,int cap,int flow):from(from),to(to),cap(cap),flow(flow){}
    };
    vector<point>edges;
    vector<int>G[N];
    int mark[N];
    int d[N];
    int cur[N];
    char a[N];
    int start;
    int ending;
    void addedge(int from,int to,int cap)
    {
        edges.push_back(point(from,to,cap,0));
        edges.push_back(point(to,from,0,0));
        int m=edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }
    int bfs(int start,int ending)
    {
        memset(mark,0,sizeof(mark));
        memset(d,-1,sizeof d);
        queue<int>q;
        q.push(start);
        d[start]=0;
        mark[start]=1;
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            for(int i=0;i<G[u].size();i++)
            {
                point e=edges[G[u][i]];
                if(!mark[e.to]&&e.cap>e.flow)
                {
                    mark[e.to]=1;
                    d[e.to]=d[u]+1;
                    q.push(e.to);
                }
            }
        }
        return mark[ending];
    }
    int dfs(int x,int a)
    {
        if(x==ending||a==0) return a;
        int flow=0,f;
        for(int &i=cur[x];i<G[x].size();i++)
        {
            point &e=edges[G[x][i]];
            if(d[x]+1==d[e.to]&&(f=dfs(e.to,min(a,e.cap-e.flow)))>0)
            {
                e.flow+=f;
                edges[G[x][i]^1].flow-=f;
                flow+=f;
                a-=f;
                if(a==0) break;
            }
        }
        return flow;
    }
    int dinic()
    {
        int flow=0;
        while(bfs(this->start,this->ending))
        {
            memset(cur,0,sizeof cur);
            flow+=dfs(start,inf);
        }

        return flow;
    }
    void pre(int start,int ending)
    {
        this->start=start;
        this->ending=ending;
        for(int i=0;i<N;i++) G[i].clear();
        edges.clear();
        memset(mark,0,sizeof mark);
        memset(d,0,sizeof d);
    }
};
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        Dinic __dinic;
        int S,D;scanf("%d%d",&S,&D);
        D+=n;
        __dinic.pre(S,D);
        for(int i=1;i<=n;i++)
        {
            int w;scanf("%d",&w);
            __dinic.addedge(i,n+i,w);
            __dinic.addedge(n+i,i,w);
        }
        for(int i=1;i<=m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            __dinic.addedge(u+n,v,inf);
            __dinic.addedge(v+n,u,inf);
        }
        printf("%d\n",__dinic.dinic());
    }
    return 0;
}


