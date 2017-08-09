//题有点长
//HDU 1531 King 差分约束
//a[si+ni]-a[si-1]<=k-1|>=k-1
//<=最短路 >=最长路
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define next Next
#define OK ios::sync_with_stdio(false)
const int maxn=(100+25)<<2;
const int INF =0x3f3f3f3f;
int n,m,dis[maxn];
bool inque[maxn];
int head[maxn],tot;
int cnt[maxn];
struct Edge
{
    int to,next,w;
}edge[maxn];
void add(int u,int v,int w)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    edge[tot].w=w;
    head[u]=tot++;
}
bool spfa(int s)
{
    for(int i=0;i<=n;i++)
        dis[i]=INF,inque[i]=0,cnt[i]=0;
    queue<int>Q;
    Q.push(s);
    inque[s]=1;dis[s]=0;cnt[s]++;
    while(!Q.empty())
    {
        int u=Q.front();Q.pop();
        inque[u]=0;
        for(int i=head[u];i!=-1;i=edge[i].next)
        {
            int v=edge[i].to,w=edge[i].w;
            if(dis[v]>dis[u]+w)
            {
                dis[v]=dis[u]+w;
                if(!inque[v])
                {
                    if(++cnt[v]>n+1) return 0;
                    inque[v]=1;
                    Q.push(v);
                }
            }
        }
    }
    return 1;
}
int main()
{
    OK;
    while(scanf("%d",&n),n)
    {
        char ch[5];
        tot=0;
        scanf("%d",&m);
        memset(head,-1, sizeof(head));
        while(m--)
        {
            int u,v,w;
            scanf("%d%d%s%d",&u,&v,ch,&w);
            if(ch[0]=='g')
                add(u+v,u-1,-w-1);
            else
                add(u-1,u+v,w-1);
        }
        for(int i=0;i<=n;i++)
            add(n+1,i,0);
        if(spfa(n+1))//当然可以用流输出
            printf("lamentable kingdom\n");
        else
            printf("successful conspiracy\n");
    }
    return 0;
}
