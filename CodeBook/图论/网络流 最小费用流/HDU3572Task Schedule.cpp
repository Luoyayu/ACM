//Task Schedule 补题计划
//每个任务ni只能在第(si,ei)经过时长pi的时间完成
//每个任务可以被划分，可以中断，可以转移到另外的机器上
//问题归纳：最大流判满流 
//建图：把每个任务看成点,s到每个任务连边,容量为所需的天数,
//然后把持续总天数看成一个个点练到超级汇点,容量为M或inf既可,每个任务连上时间区间上的每个天数点,容量为1,
//这样只要从超级源点可以满流即可完成

#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int exp = 10e-7;
const int maxn = 2000;
int N,M,T;//M机器数量
template <class T>
struct Dinic
{
    struct point
    {
        int from,to;
        T cap,flow;
        point(int from,int to,T cap,T flow):
                from(from),to(to),cap(cap),flow(flow){}
    };
    vector<point>edges;
    vector<int>G[maxn];
    int mark[maxn],cur[maxn];
    T d[maxn];
    int start,ending;
    void addedge(int from,int to,T cap)
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
    T dfs(int x,T a)
    {
        if(x==ending||a==0) return a;
        T flow=0,f;
        for(int &i=cur[x];i<G[x].size();i++)
        {
            point &e=edges[G[x][i]];
            if(d[x]+1==d[e.to]&&(f=dfs(e.to,min(a,e.cap-e.flow)))>0)
            {
                e.flow+=f;
                edges[G[x][i]^1].flow-=f;
                flow+=f;a-=f;
                if(a==0) break;
            }
        }
        return flow;
    }
    T dinic(int start, int ending)
    {
        this->start = start;
        this->ending = ending;
        T flow=0;
        while(bfs(this->start,this->ending))
        {
            memset(cur,0,sizeof cur);
            flow+=dfs(start,inf);
        }
        return flow;
    }
    void init()
    {
        for(int i=0;i<maxn;i++) G[i].clear();
        edges.clear();
        memset(mark,0,sizeof mark);
        memset(d,0,sizeof d);
    }
};

int main()
{
    scanf("%d", &T);
    Dinic<int> __dinic;
    for(int kase=1;kase<=T;kase++)
    {
        __dinic.init();
        scanf("%d %d", &N, &M);
        int Last_time = -inf, sump = 0; //判sump满流
        int s = 0;
        for(int i=1; i<=N; i++)
        {
            int x,y,z;
            scanf("%d %d %d",&x,&y,&z);
            sump += x;
            Last_time = max(z,Last_time);
            __dinic.addedge(s,i,x);
            for(int j = y; j <= z; j++)
                __dinic.addedge(i,N+j,1);
        }
        int t = Last_time +1 + N;
        for(int i=1; i<=Last_time; i++)
            __dinic.addedge(i+N,t,M);

        int maxFlow = __dinic.dinic(s,t);
        if(maxFlow==sump) printf("Case %d: Yes\n\n",kase);
        else printf("Case %d: No\n\n",kase);
    }
    return 0;
}