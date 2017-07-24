///重温最短路
///题好长啊
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#define next Next
using namespace std;
const int maxn=10000+10;
const int maxV=450;
const int INF=0x3f3f3f3f;
struct node
{
    int to,next;
    int w;
}edge[maxn];
int n,m,tot,dis[maxn],head[maxn];
bool vis[maxn];
void add(int u,int v,int w)
{
    edge[tot].to=v;
    edge[tot].w=w;
    edge[tot].next=head[u];
    head[u]=tot++;
}
void spfa(int begin,int end)
{
    memset(vis,0,sizeof(vis));
    for(int i=0;i<=n*m;i++)
        dis[i]=INF;
    queue<int>q;
    q.push(begin);dis[begin]=0;
    while(!q.empty())
    {
        int u =q.front();q.pop();
        vis[u]=0;
        for(int i=head[u];i!=-1;i=edge[i].next)
        {
            int v=edge[i].to;
            int w=edge[i].w;
            if(dis[v]>dis[u]+w)
            {
                dis[v]=dis[u]+w;
                if(!vis[v])
                {
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
    }
    if(dis[end]==INF)
        printf("Holiday\n");
    else
        printf("%d blips\n",dis[end]);

}
int main()
{
    while(scanf("%d %d",&n,&m)!=EOF&&(n||m))
    {
        memset(head,-1,sizeof head);
        tot=0;
        n++;m++;
        int r=n*2-1;
        int l,w;
        char ch[2];
        for(int i=0;i<r;i++)
        {
            if(i&1)///横排
            {
                l = m;
                for(int j=0;j < l;j++)
                {
                    scanf("%d%s",&w,ch);
                    int u=(i>>1)*m+j;
                    int v=u+m;
                    if(w == 0) continue;
                    w=2520/w;
                    if(ch[0]=='V') add(u,v,w);
                    else if(ch[0]=='^') add(v,u,w);
                    else add(u,v,w),add(v,u,w);
                }
            }
            else///竖排，给出每一行
            {
                l=m-1;
                for(int j=0;j<l;j++)
                {
                    scanf("%d%s",&w,ch);
                    int u=(i>>1)*m+j;
                    int v=u+1;
                    if(w==0) continue;
                    w=2520/w;
                    if(ch[0]=='>') add(u,v,w);
                    else if(ch[0]=='<') add(v,u,w);
                    else add(u,v,w),add(v,u,w);
                }
            }
        }
    spfa(0,n*m-1);
    }
}
