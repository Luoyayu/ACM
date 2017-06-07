///拆点 t1->t2 建图
///源点s 汇点t
///柱子t1上有的连上s->t1 ,容量1
///能够跳出的连上t1->END ,容量为cost
///跳不出的连上 t1->t2 容量为次数
///能跳到别的点的连上 this.t2->that.t1 容量inf 表示联通
#include <bits/stdc++.h>
using namespace std;
const int N = 5000,inf=1e9+7;
int n,m;
const int maxn=50;

char map1[maxn][maxn],map2[maxn][maxn];

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
    char a[N];int start,ending;
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

int retDis(int a,int b,int c,int d)
{
    return abs(a-b)+abs(c-d);
}

inline int dot1(int a,int b)
{
    return a*m + b+1;
}

inline int dot2(int a,int b)
{
    return dot1(a,b)+ n*m;
}

int main()
{
    int t;scanf("%d",&t);
    for(int kase=1;kase<=t;kase++)
    {
        int d;
        Dinic __dinic;

        memset(map1,0,sizeof map1);
        memset(map2,0,sizeof map2);
        scanf("%d %d\n",&n,&d);

        for(int i=0;i<n;i++)
            scanf("%s",map1[i]);

        for(int i=0;i<n;i++)
            scanf("%s",map2[i]);

        m = strlen(map1[0]);
        int sum = 0;
        int END = 2*n*m+1; ///终点
        int s = 0;

        __dinic.pre(s,END);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(map2[i][j]=='L')///开始发射
                {
                    sum++;///总数
                    __dinic.addedge(s,dot1(i,j),1);
                }
            }
        }
         /// dot (i,j)=>i*m+j+1  (dot->dot') => (i*m+j+1->i*m+j+1+n*m)

        for(int i = 0; i < n; i++)
        {
            for(int j = 0;j < m; j++)
            {
                if(map1[i][j]-'0'>0)
                {
                    if(i+1<=d||j+1<=d||n-i<=d||m-j<=d)///可以跳出去的话 直接连 t1->end
                    {
                        __dinic.addedge(dot1(i,j),END,map1[i][j]-'0');
                        continue;
                    }
                    else __dinic.addedge(dot1(i,j),dot2(i,j),map1[i][j]-'0');///跳不出去的话 t1->t2;
                    ///再考虑连上那些能跳到的点 [-d,d]

                    for(int ii = -d; ii <= d; ii++)
                    {
                        for(int jj = -d; jj <= d; jj++)
                        {
                            int x = i + ii;
                            int y = j + jj;
                            if(x==i&&y==j) continue;
                            if(x<0||y<0||x>=n||y>=m||retDis(i,x,j,y) > d || map1[x][y] =='0') continue;
                            __dinic.addedge(dot2(i,j),dot1(x,y),inf);
                        }
                    }
                }
            }
        }

        int maxFlow =  __dinic.dinic();
        int ans = sum - maxFlow;

        printf("Case #%d: ",kase);
        if(ans>1)
            printf("%d lizards were left behind.\n",ans);
        else if(1==ans)
            printf("1 lizard was left behind.\n");
        else
            printf("no lizard was left behind.\n");

    }
    return 0;
}
