//温习二分匹配
//增广路径算法：从未匹配的点出发，交替通过未匹配边和已匹配边，最后到达另一个未匹配点的路径
//复杂度O(v*e)
#include<cstdio>
#include<queue>
#include<string>
#include<vector>
#include<iostream>
#include<cstring>
using namespace std;
const int maxn=5000+10;
const int maxm=50000+10;
int linker[maxn],head[maxn];
bool vis[maxn];
int tot,uN,vN;
struct Edge
{
    int to;
    int next;
}edge[maxm];
void init()
{
    tot=0;
    memset(head,-1,sizeof head);
}
void add(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}
bool dfs(int u)
{
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].to;
        if(!vis[v])
        {
            vis[v]=1;
            if(linker[v]==-1||dfs(linker[v]))
            {
                linker[v]=u;
                return true;
            }
        }
    }
    return false;
}
int huangay()
{
    int res=0;
    memset(linker ,-1,sizeof linker);
    for(int u=1;u<=uN;u++)
    {
        memset(vis,0,sizeof vis);
        if(dfs(u)) res++;
    }
    return res;
}
int main()
{
    int k;
    while(scanf("%d",&k)!=EOF&&k)
    {
        init();
        scanf("%d %d",&uN,&vN);
        while(k--)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            add(x,y);
        }
        printf("%d\n",huangay());
    }
    return 0;
}
