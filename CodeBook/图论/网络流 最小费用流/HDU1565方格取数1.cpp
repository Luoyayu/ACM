///网络流解法分析
///最大点权独立集=总权-最小点权覆盖集 最小点权覆盖集 = 最小割 = 最大网络流
///奇偶建二分图+跑最大流==最小点权覆盖
///建模方法：行+列==奇数作为X集合 其余作为Y集合
#include<bits/stdc++.h>
using namespace std;
const int maxn=55;
const int  N = 2000;
const int inf = 0x3f3f3f3f;
int g[maxn][maxn];
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
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        Dinic __dinic;
        int total = 0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                scanf("%d",&g[i][j]),total+=g[i][j];

        int s=0;
        int end=n*n+1;
        __dinic.pre(s,end);

        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                int t=(i-1)*n+j;
                if((i+j)&1) /// 奇数
                {
                    __dinic.addedge(s,t,g[i][j]);
                    if(i>=2)
                    __dinic.addedge(t,t-n,inf);
                    if(i<=n-1)
                    __dinic.addedge(t,t+n,inf);
                    if(j>=2)
                    __dinic.addedge(t,t-1,inf);
                    if(j<=n-1)
                    __dinic.addedge(t,t+1,inf);
                }
                else///偶数
                    __dinic.addedge(t,end,g[i][j]);

            }

        printf("%d\n",total-__dinic.dinic());

    }
    return 0;
}
