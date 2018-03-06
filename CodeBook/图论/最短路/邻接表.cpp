#include<bits/stdc++.h>
//邻接表的高效形式
const int maxn = 1000;
using namespace std;
int head[maxn];
int tot=0;//边数
struct Edge
{
    int to,next,w; // to为弧头结点的序号,next为下一条边的序号
}edge[maxn];
void add(int from,int to,int w)
{
    edge[tot].to = to;
    edge[tot].w = w;
    edge[tot].next = head[from];
    head[from] = tot++;
}
//edge[i]指的是第i条边  head[i]记录从当前输入来看,序号为i的弧 尾结点出发的的一条边
void XXX()
{
    for(int i = head[cur];~i;i = edge[i].next)
    {
        int to = edge[i].to;
        int w = edge[i].w;
        //do something
    }
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);

    memset(head,-1,sizeof head);
    for(int i=0;i<m;i++)
    {
        int from,to,w;
        scanf("%d%d%d",&u,&v,&w);
        add(from,to,w);
    }
    
}