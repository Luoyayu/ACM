//N个客人 第i个人会在si时间到达,订ni个烧烤，所有烤串总共需要ti时间 需要在ei前完成
//至多M个烤串同时被烤
//完成的时间需要在(si,ei]内
#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 200+7;
int N,M;
struct node
{
    int si,ni,ei,ti;
}Person[maxn];
class Dinic
{
public:
    struct point
    {
        int from,to,cap,flow;
        point(int from,int to,int cap,int flow):
            from(from),to(to),cap(cap),flow(flow){}
    };
    vector<point>edges;
    vector<int>G[N];
    int mark[N], d[N], cur[N];
    char a[N];
    int start,ending;
    void addedge(int from,int to,int cap)
    {
        edges.push_back(point(from,to,cap,0));
        edges.push_back(point(to,from, 0, 0));
        int m=edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }
    int bfs(int start,int ending)
    {
        memset(mark,0,sizeof(mark));
        memset(d,-1,sizeof d);
        queue<int> q;
        q.push(start);
        d[start]=0;
        mark[start]=1;
        while(!q.empty())
        {
            int u=q.front();q.pop();
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
    while(scanf("%d%d",&N,&M)!=EOF)
    {
        Dinic.__Dinic;
        __Dinic.pre();
        for(int i=0;i<N;i++)
            scanf("%d%d%d%d",&Person[i].si,&Person[i].ni,&Person[i].ei,&Person[i].ti);
        
    }
}
