//树形DP第一题
//题意:给出关系树,每个点有权值,要求父节点和子节点不能同时取可以都不取,求最大值
//DP 放在树上
//把树当成有向图来处理，从父节点建一条指向子节点的有向边
//dp[i][f]表示到第i个人的时候取得的最大值,f==1表示来, f==0表示不来
//转移方程:当i来的时候:dp[i][1]+=dp[j][0] //j为i的下属
//当i不来的时候:dp[i][0]+=max(dp[j][1],dp[j][0]);//j为i的下属
#include<bits/stdc++.h>
const int maxn = 6000 + 66;
using namespace std;
int dp[maxn][2],n;
int head[maxn];
vector <int> G[maxn];
void dfs(int root)
{
    for(int i=0;i<G[root].size();i++)
        dfs(G[root][i]);//从叶节点向根节点回溯
    for(int i=0;i<G[root].size();i++)//回溯时计算dp
    {
        dp[root][0] += max(dp[G[root][i]][0],dp[G[root][i]][1]);
        dp[root][1] += dp[G[root][i]][0];
    }
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        memset(dp,0,sizeof dp);
        for(int i=1;i<=n;i++)//把权值记到来的情况中
            scanf("%d",&dp[i][1]),head[i]=-1,G[i].clear();
        int L,K;//K->L
        while(scanf("%d %d",&L, &K)&&(L&&K))
        {
            head[L] = K;//记录父节点
            G[K].push_back(L);//建立一条父节点指向子节点的有向边
        }
        int root = 1;//找到根节点
        while(head[root]!=-1)
            root=head[root];
        dfs(root);
        printf("%d\n",max(dp[root][1],dp[root][0]));
    }
    return 0;
}
