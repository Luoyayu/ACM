//SPJ 神奇(巨难想)网络流
//题意: 给出N*M的数迷 每一行或每一列空白成为一个回,有些黑色格子左下角表示列的和,右上角表示行的和，每个回的数字可以重复
//给出合适的数迷填法
//结题报告：以白色空格为节点,假设流是从左流入,从上流出,那么流入的容量为行和,流出的容量为列和,再求最大流,填数要求1-9 但是流有限制故统统减为0-8
//建图：
#include<bits/stdc++.h>
const int maxn = 1e6+5;
const int inf = 0x3fffffff;
#define Debug(x) cout<<#x<<"="<<x;
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
using namespace std;
int main()
{
    int n,m;
    while(scanf("%d%d",&你，&m)!=EOF)
    {
        Dinic __dinic;
        __dinic.init();
        string input;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                {
                    scanf("%s",input.c_str());

                }

    }
}