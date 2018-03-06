///HDU 4292 网络流建图训练 建图真有趣
///F 种食物 D种酒水 N 人
///这样想 , 然后每个人连上喜欢的食物,边权为1
///人拆点 i->i` cost = 1;
#include<bits/stdc++.h>
const int inf = 1e9+7;
using namespace std;
const int N= 2002;
char pref[N];

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

using namespace std;
int main()
{
    int n,f,d;
    while(scanf("%d %d %d",&n,&f,&d)!=EOF)
    {
        Dinic __dinic;

        int s=0, end = 2*n+f+d+1;
        __dinic.pre(s,end);

        int food,drink;
        for(int i=1;i<=f;i++)//源点 连上食物 边权为食物的每种的供应量
        {
            scanf("%d",&food);
            __dinic.addedge(s,i,food);

        }
        for(int i=f+2*n+1;i<end;i++)//每种酒水连上终点,边权为供应量
        {
            scanf("%d",&drink);
            __dinic.addedge(i,end,drink);

        }
        for(int i=f+1;i<=f+n;i++)//人拆点,边权为1,有流流入有表示选上了喜欢的食物,由流流出表示选上了喜欢的酒水。
            __dinic.addedge(i,i+n,1);

        for(int i=1;i<=n;i++)
        {
            scanf("%s",pref+1);
            for(int j=1;j<=f;j++)
            {
                if(pref[j]=='Y')
                    __dinic.addedge(j,f+i,1);//左人连上食物
            }

        }

        for(int i=1;i<=n;i++)
        {
            scanf("%s",pref+1);
            for(int j=1;j<=d;j++)
            {
                if(pref[j]=='Y')
                    __dinic.addedge(f+n+i,f+2*n+j,1);//右人连上酒水
            }
        }

        printf("%d\n",__dinic.dinic());
    }
    return 0;

}
