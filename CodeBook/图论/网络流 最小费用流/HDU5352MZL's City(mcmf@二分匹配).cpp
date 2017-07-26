#include<bits/stdc++.h>
using namespace std;
//题意：N个城市,M年,每年一个操作
//op1: 1 X, 重建城市X和与X直接或间接相连的城市
//op2: 2 X Y 建X,Y之间的双向边
//op3: 3 P X1 Y1 ·· 摧毁p条边(Xi,Yi)
//每年最多重建K个城市
//思想：把操作看成点连边
//问最终最多重建多少城市,并且输出每年修建城市的数量的字典序 
//最小费用(字典序)最大流(最多修建城市&&每年最多修K个城市)问题
//建模: 1) 源点0,汇点n+1
//      2) 每个城市分别向汇点建边 费用0,容量为1(只能被重建1次)
//      3) 对于op1 编号[n+2~n+k],从源点建边容量为K,操作i向关联的点连边,容量为1,费用为0 
const int maxn = 210;
int g[maxn][maxn];
bool flag[maxn];
int ans[510];
int n,m,k;
class MCMF
{
public:
    class point
    {
    public:
            int from,to,cap,flow,cost;
            point(int from,int to,int cap,int flow,int cost):from(from),
            to(to),cap(cap),flow(flow),cost(cost){}
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
void dfs(int root,int par)
{
    _mcmf.addedge(par,root,1,0);
    flag[root]=0;
    for(int i=1;i<=n;i++)
    {
        if(g[root][i]&&!flag[i])
            dfs(i,par);
    }
}

int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        MCMF _mcmf;
        int as = 0;
        scanf("%d%d%d",&n,&m,&k);
        int yuan = 0;
        int hui = n + 2;
        _mcmf.pre(yuan,hui);
        for(int i=1;i<=n;i++)
            _mcmf.addedge(i,n+1,1,0);
        memset(g,0,sizeof(g));
        int MAXcost = 510;
        for(int i=1;i<=m;i++)
        {
            int op,p,x,y;
            scanf("%d",&op);
            if(op==1)
            {
                memset(flag,0,sizeof(flag));
                scanf("%d",&p);
                dfs(p,index);
                ans[as++]=_mcmf.edges.size();
                _mcmf.addedge(0,hui,k,MAXcost);
                MAXcost--;
                hui++;
            }
            else if(op==2)
            {
                scanf("%d%d",&x,&y);
                g[x][y]=g[y][x]=1;
            }
            else if(op==3)
            {
                scanf("%d",&p);
                for(int i=1;i<=p;i++)
                {
                    scanf("%d%d",&x,&y);
                    g[x][y]=g[y][x]=0;
                }
            }
        }
        int cost;
        if(as==0)
        {
            printf("0\n");
            continue;
        }
        printf("%d\n",_mcmf.mcmf());
        for(int i=0;i<as-1;i++)
            printf("%d ",_mcmf[ans[i]].flow);
        printf("%d ",_mcmf[ans[as-1]].flow);
    }
    return 0;
}
