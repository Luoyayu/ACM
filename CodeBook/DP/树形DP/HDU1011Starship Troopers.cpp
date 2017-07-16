//树形dp第三弹
//题意:有n个房间组成一棵树,有m个士兵,从1号房间开始让士兵向相邻的房间出发，
//每个房间有一个价值代价为:虫子数/20个士兵
//问花费m个士兵最大获得价值
//设计状态dp[i][j]为根节点为i时用掉j个士兵可以获得最大possibilities
//dp[i][j]=max(dp[i][j],dp[i][j-k]+dp[to[i]][k]);
//ans = dp[1][m];
#include<bits/stdc++.h>
using namespace std;
const int maxn = 222;
const int inf = 0x3f3f3f3f;
const double pi = acos(-1);
typedef long long ll;
int tot=0,n,m,head[maxn];
bool vis[222];
int bug[222],poss[222],dp[222][222];
struct node
{
    int to,next;
}edge[maxn];
void add(int from,int to)
{
    edge[tot].to = to;
    edge[tot].next = head[from];
    head[from] = tot++;
}
void dfs(int root)
{
    int cost=(bug[root]+19)/20;//不足20的也需要1个士兵
    vis[root]=1;
    for(int i=cost;i<=m;i++)
        dp[root][i]=poss[root];//dp[i][j]=k表示在第i个洞穴用掉i个士兵可以获得的收益
    for(int i = head[root];~i;i = edge[i].next)
    {
        int to = edge[i].to;
        if(!vis[to])
        {
            dfs(to);//dfs到叶节点
            for(int j=m;j>=cost;j--)//回溯时处理
                for(int k = 1;j+k<=m;k++)//留在此节点有k人
                    if(dp[to][k])
                        dp[root][j+k]=max(dp[root][j+k],dp[root][j]+dp[to][k]);
        }
    }
}
int main()
{
    while(scanf("%d %d",&n,&m)!=EOF,n+m>0)
    {
        tot=0;  
        memset(dp,0,sizeof dp);
        memset(vis,0,sizeof vis);
        memset(head,-1,sizeof head);
        for(int i=1;i<=n;i++)
            scanf("%d%d",&bug[i],&poss[i]);
       
        for(int i=1;i<n;i++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            add(x,y);add(y,x);//本题给出的顺序并不是父子关系
        }
        if(!m)
            printf("0\n");
       else
       {
            dfs(1);
            printf("%d\n",dp[1][m]);  
       } 
    }
    return 0;
}
