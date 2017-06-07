#include<bits/stdc++.h>
using namespace std;
///最小费用最大流

class MCMF
{
public:
    class point
    {
    public:
            int from,to,cap,flow,cost;
            point(int from,int to,int cap,int flow,int cost):from(from),to(to),cap(cap),flow(flow),cost(cost){}
    };
    int n,m;
    int start,ending;
    vector<point>edges;
    vector<int>G[N];
    bool inq[N];
    int d[N];
    int p[N];
    int a[N];

    void pre(int start,int ending)
    {
        this->start=start;
        this->ending=ending;
        for(int i=0;i<N;i++)G[i].clear();
        edges.clear();
        memset(inq,0,sizeof inq);
        memset(d,0,sizeof d);
        memset(p,0,sizeof p);
        memset(a,0,sizeof a);
    }

    void addedge(int from,int to,int cap,int cost)
    {
        edges.push_back(point(from,to,cap,0,cost));
        edges.push_back(point(to,from,0,0,-cost));
        m=edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }
    bool spfa(int &flow,int &cost)
    {
        for(int i=0;i<N;++i) d[i]=99999999;
        queue<int>q;
        memset(inq,0,sizeof(inq));
        d[start]=0;
        q.push(start);
        a[start]=99999999;
        p[start]=0;
        inq[start]=1;
        while(!q.empty())
        {
            int u=q.front(); q.pop();
            inq[u]=0;
            for(int i=0;i<G[u].size();i++)
            {
                point &e=edges[G[u][i]];
                if(e.cap>e.flow && d[e.to]>d[u]+e.cost)
                {
                    d[e.to]=d[u]+e.cost;
                    p[e.to]=G[u][i];
                    a[e.to]=min(a[u],e.cap-e.flow);
                    if(!inq[e.to])
                    {
                         q.push(e.to);
                         inq[e.to]=1;
                    }
                }
            }
        }
        if(d[ending]==99999999) return 0;
        flow+=a[ending];
        cost+=d[ending]*a[ending];
        int u=ending;
        while(u!=start)
        {
            edges[p[u]].flow+=a[ending];
            edges[p[u]^1].flow-=a[ending];
            u=edges[p[u]].from;
        }
        return 1;
    }

    int mcmf()
    {
        int flow=0,cost=0;
        while(spfa(flow,cost));
        return cost;
    }
};
MCMF __mcmf;
int main()
{

}
