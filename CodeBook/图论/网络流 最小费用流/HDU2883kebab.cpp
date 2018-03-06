//N个客人 第i个人会在si时间到达,订ni个烧烤，所有烤串总共需要ti时间 需要在ei前完成
//至多M个烤串同时被烤 完成的时间需要在(si,ei]内
//note: 时间范围很大不可完全设点
//N个客人 第i个人会在si时间到达,订ni个烧烤,所有烤串总共需要ti时间,需要在ei前完成
//完成的时间需要在(si,ei]内
//note: 时间范围很大不可完全设点,需要离散处理,对于区间去重后得到(cnt-1)个时间区间,把不重叠的时间段看成点,这样只用操作时间段便可形成可行流
//喜闻乐见 建图思路:0->task(t*n)->time_blocks(inf)->t(sum of each [time_block * M] )
#include<bits/stdc++.h>
#define captype int
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 20000;
int N,M;
struct node
{
    int si,ni,ei,ti;
}Person[maxn];

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
int Time[maxn];
int main()
{
    while(scanf("%d%d",&N,&M)!=EOF)
    {
        Dinic<int> __Dinic;
        __Dinic.init();
        int s = 0;
        int sum = 0;
        unsigned cnt = 0;
        for(int i=1;i<=N;i++)
        {
            scanf("%d %d %d %d", &Person[i].si, &Person[i].ni, &Person[i].ei, &Person[i].ti);
            sum += Person[i].ti*Person[i].ni;
            Time[cnt++]=Person[i].si;
            Time[cnt++]=Person[i].ei;
        }
        sort(Time, Time+cnt);

        #ifdef Local
        cout<<"origin cnt = "<<cnt<<endl;
        cout<<"cnt = "<<cnt<<endl;
        cnt = unique(Time, Time+cnt)-Time;
        cout<<"now cnt = "<<cnt<<endl;
        for(int i=0;i<cnt;i++)
            cout<<Time[i]<<" ";
        cout<<endl;
        #endif // Local
    
        int t = N + cnt + 1;
        for(int i=1;i<=N;i++) __Dinic.addedge(s,i,Person[i].ni*Person[i].ti);//从连0->任务点 容量为ni*ti

        for(int i=1;i<=cnt-1;i++)//cnt-1个时间区间
        {
            __Dinic.addedge(N+i,t,(Time[i]-Time[i-1])*M); //连区间 //M为最多烤的数量,(Time[i]-Time[i-1])*M 即为这段独立时间段可以烤的数量之和，既为n+i->t的容量

            for(int j=1;j<=N;j++)
                if(Person[j].si<=Time[i-1]&&Time[i]<=Person[j].ei)//把此人所需的时间划分为时间段后连起来
                    __Dinic.addedge(j,N+i,inf);//人连时间段，容量无限大确保满流
        }
        printf("%s\n",__Dinic.dinic(s,t)==sum?"Yes":"No");
    }
    return  0;
}
