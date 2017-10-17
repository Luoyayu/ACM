//POJ 1849 题意：给出树，两个人从起点出发，求经过所有点的最小代价
//思想最经济的做法是若两人在树的直径上那么两人想直径的两侧的子树上扫雪，总代价是2*子树的权值+树的直径==总权值*2-直径；若两人不在树的直径上那么两人需要走到树的直径上
//ans就是所有的边权*2-树的直径
//树的直径两边dfs即可
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+7;
typedef long long ll;
struct node{
    int to,next,w;
}e[maxn];
int cnt;
int head[maxn];
void addedge2(int u,int v,int w)
{
    e[cnt]=node{u,head[v],w}; head[v]=cnt++;
    e[cnt]=node{v,head[u],w}; head[u]=cnt++;
}
int dis[maxn];
void init(){
    memset(dis,0, sizeof(dis));
    memset(head,-1,sizeof(head));
    cnt = 0;
}
void dfs(int u,int fa,int d)
{
    for(int i=head[u];~i;i=e[i].next)
    {
        int v = e[i].to;
        int w = e[i].w;
        if(v!=fa){
            dis[v] = w + d;
            dfs(v,u,w+d);
        }
    }
    return;
}
int main()
{
    int st,n;scanf("%d%d",&n,&st);
    init();int TOT = 0;
    for(int i=1;i<=n-1;i++){
        int u,v,w;scanf("%d%d%d",&u,&v,&w);
        addedge2(u,v,w);TOT += 2*w;
    }
    dfs(st,-1,0);
    int id=0,MAX = -1;
    for(int i=1;i<=n;i++)
        if(dis[i] > MAX)
            MAX = dis[i], id = i;
            
    dis[id]=0;
    dfs(id,-1,0);MAX = -1;
    for(int i=1;i<=n;i++)
        MAX = max(MAX,dis[i]);
    return !printf("%d\n",TOT-MAX);
}