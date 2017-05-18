///第一道差分约束题；
//所谓的差分就是在有n个变量的m个形如x[i]-x[j]>=b[k]的条件下，求解x[n-1]-x[0]的最值；
///x[i]-x[j]>=a[k] => x[j]>=x[i]+a[k]转换成i->j 边权为a[k]的有向边
///x[i]-x[j]<=a[k] => x[i]<=x[j]+a[k] 转换成j->i 边权威a[k]的有向边
///题意：区间[a,b] 内点集Z至少有ci个相同元素；转换为Sb[i]-Sa[i]>=ci;
//注意到Si-Si-1>=0 Si-1 - Si>=-1;
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
#define next Next
const int maxn=50000<<2;
const int INF=0x3f3f3f3f;
int MIN,MAX;
int head[maxn],tot,n,m;

struct Edge
{
    int to,next,w;
}edge[maxn];
void add(int u,int v,int w)
{
    edge[tot].to=v;
    edge[tot].w=w;
    edge[tot].next=head[u];
    head[u]=tot++;
}
bool inque[maxn];
int dis[maxn];
void spfa(int s)
{
    for(int i=MIN;i<=MAX;i++)
        dis[i]=-INF;
    dis[s]=0;
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();q.pop();
        inque[u]=0;
        for(int i=head[u];i!=-1;i=edge[i].next)
        {
            int v=edge[i].to;
            int w=edge[i].w;
            if(dis[v]<dis[u]+w)
            {
                dis[v]=dis[u]+w;
                if(!inque[v])
                {
                    inque[v]=1;
                    q.push(v);
                }
            }
        }
    }
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        memset(head ,-1,sizeof head);
        memset(inque,0,sizeof inque);
        tot=0;
        MIN=INF,MAX=-INF;
        while(n--)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            add(u,v+1,w);
            MIN=min(MIN,u);  //起点
            MAX=max(MAX,v+1);//终点
        }
        for(int i=MIN;i<MAX;i++)
        {
            add(i,i+1,0);
            add(i+1,i,-1);
        }
        spfa(MIN);
        printf("%d\n",dis[MAX]);
    }
    return 0;
}

