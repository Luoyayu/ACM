#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=20000<<1;
const int W = 0;//未确定的点
const int R = 1;//选取的点
const int B = 2;//抛弃的点
int n,m,cnt,MM;
int head[maxn],tot;
int color[maxn],ans[maxn];
struct Edge
{
    int to,next;
}edge[maxn];
void add(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}
int dfs(int u)
{
    color[u]=R,color[u^1]=B;ans[++cnt]=u;//u染成红色，u^1染成蓝色,u的所有后继都染成红色；
    for(int i=head[u];i+1;i=edge[i].next)
    {
        int v=edge[i].to;
        if(color[v]==R) continue;
        if(color[v]==B||!dfs(v)) return 0; //在后继中发现蓝色的点触发矛盾，
    }
    return 1;
}
int solve()
{
    memset(color,0,sizeof color);
    for(int i=0;i<MM;i++)
        if(color[i] == W)
        {
            cnt = 0;
            if(!dfs(i))//染色失败时还原白色
            {
                for(int j=1;j<=cnt;j++)
                    color[ans[j]] = color[ans[j]^1] = W;
                if(!dfs(i^1))
                    return 0;//同组的另一个节点又失败了，推出矛盾
            }
        }
    return 1;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        MM=n<<1;
        tot=0;
        memset(head,-1,sizeof head);
        for(int i=0;i<m;i++)
        {
            int u,v;scanf("%d %d",&u,&v);
            u--;v--;
            add(u,v^1);add(v,u^1);
        }
        if(solve())
        {
            for(int i=0;i<MM;i++)
                if(color[i]==R)
                    printf("%d\n",i+1);
        }
        else
            printf("NIE\n");
    }
    return 0;
}
