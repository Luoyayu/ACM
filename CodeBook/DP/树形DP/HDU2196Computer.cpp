//给出一棵树,求距离每个节点最远的距离
//按题意给出一颗无根树需要转换为有根树分析
//对于无根树上的i节点dmax={以该点为根结点的子树的最大距离,以i的父节点为根节点的子树的最大距离+w[<u,v>]}
//设计状态dp[u][0]表示在u的子树下的最远距离,dp[u][2]表示通过u的父节点能走的最远距离,dp[u][1]表示在u的子树下的次远距离
//最终的答案为max(dp[u][0],dp[u][2]);
//对于有向边<u,v>求得dp[u][0]=dp[v]+w[<u,v>];故方向为自底向上
//对于有向边<u,v>,u为父亲节点,v为子节点那么dp[v][2]=max(dp[u][2],dp[v][0]+w[<u,v>]==dp[u][0]?dp[u][1]:dp[u][0])+w<u,v>
#include<bits/stdc++.h>
using namespace std;
const int maxn = 10000+7;
struct Edge
{
    int v,w,next;
}edge[maxn<<1];
int head[maxn],tot;
void addedge(int u,int v,int w)
{
    edge[tot].v=v;
    edge[tot].w=w;
    edge[tot].next=head[u];
    head[u]=tot++;
}
int dp[maxn][3];

void dfs1(int u,int v) //每个节点子树下的最大和次大
{
    for(int i=head[u];~i;i=edge[i].next)
    {
        int v=edge[i].v;
        dfs1(v,u);//抵达叶节点
        int w=edge[i].w;
        int temp = dp[v][0] + w;
        if(temp >= dp[u][0])
        {
            dp[u][1]=dp[u][0];
            dp[u][0] = temp;
        }
        else if(temp > dp[u][1])
            dp[u][1] = temp;
    }
}

void dfs2(int u,int v)
{
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].v;
        if(dp[u][0] == dp[v][0] + edge[i].w)
            dp[v][2] = max(dp[u][2],dp[u][1]) + edge[i].w;
        else
            dp[v][2] = max(dp[u][2],dp[u][0]) + edge[i].w;
        dfs2(v,u);
    }
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        memset(head,-1,sizeof head);
        tot=0;
        for(int v=2;v<=n;v++)
        {
            int u,w;scanf("%d%d",&u,&w);
            addedge(u,v,w);
        }
        memset(dp,0,sizeof dp);
        dfs1(1,-1);dfs2(1,-1);
        for(int i=1;i<=n;i++)
            printf("%d\n",max(dp[i][0],dp[i][2]));
    }
    return 0;
}
