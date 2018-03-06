//FAS：a+t[a]>=b       => a-b>=-t[a];
//FAF：a+t[a]>=b+t[b]  =>a-b>=t[b]-t[a];
//SAF:a>=b+t[b]       => a-b>=t[b]
//SAS:a>=b            => a-b>=0
#include <queue>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#define next Next
#define OK ios::sync_with_stdio(false)
const int INF = 100000000;
const int maxn = 1000000+10;
using namespace std;
struct Edge
{
    int to;
    int w;
    int next;
}edge[maxn];
int head[maxn],dis[maxn],tot,cnt[maxn];
bool inque[maxn];
int n,m;
int t[maxn];
void add(int u, int v, int w)
{
    edge[tot].to = v;
    edge[tot].w = w;
    edge[tot].next = head[u];
    head[u] = tot++;
}
bool spfa(int s)
{
    for(int i=1;i<=n;i++)
        dis[i]=-INF,cnt[i]=1,inque[i]=0;
    dis[s]=0;inque[s]=1;cnt[0]++;
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
                    if(++cnt[v]>n)return 0;
                    inque[v]=1;
                    q.push(v);
                }
            }
        }
    }
    return 1;
}
int main()
{
    OK;
    int kase=1;
    while(scanf("%d",&n)!=EOF,n)
    {
        memset(head,-1, sizeof(head));
        tot=0;
        for(int i=1;i<=n;i++)
            scanf("%d",&t[i]),add(0,i,0); //!!! 初始建边很重要
        char cmd[10];
        while(scanf("%s",cmd),cmd[0]!='#')
        {
            int a,b;
            scanf("%d%d",&a,&b);
            if(strcmp("FAS",cmd)==0)
                add(b,a,-t[a]);
            else if(strcmp("FAF",cmd)==0)
                add(b,a,t[b]-t[a]);
            else if(strcmp("SAF",cmd)==0)
                add(b,a,t[b]);
            else if(strcmp("SAS",cmd)==0)
                add(b,a,0);
        }
        printf("Case %d:\n",kase++);
        if(spfa(0))
        {
            for(int i=1; i<=n; i++)
                printf("%d %d\n",i,dis[i]);
        }
        else
            printf("impossible\n");
        printf("\n");
    }
    return 0;
}
