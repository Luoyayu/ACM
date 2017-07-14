//树形dp第三弹
//题意:有n个房间组成一棵树,有m个士兵,从1号房间开始让士兵向相邻的房间出发，
//每个房间有一个价值代价为:虫子数/20个士兵
//问花费m个士兵最大获得价值
//设计状态dp[i][j]为根节点为i时用掉j个士兵可以获得最大possibilities
//dp[i][j]=max(dp[i][j],dp[i][j-k]+dp[son[i]][k]);
//ans = dp[1][m];
#include<bits/stdc++.h>
using namespace std;
const int maxn = 111;
const int inf = 0x3f3f3f3f;
const double pi = acos(-1);
typedef long long ll;
int tot=0;
int head[maxn];
bool vis[maxn];
struct node
{
    int to,next,num;
}p[maxn];
void add(int from,int to,int w)
{
    p[tot].to = to;
    p[tot].num = w;
    p[tot].next = head[from];
    head[from] = tot++;
}
int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF&&n+1&&m+1)
    {
        tot=0;
        for(int i=1;i<=n;i++)
        {
            
        }


    }

}