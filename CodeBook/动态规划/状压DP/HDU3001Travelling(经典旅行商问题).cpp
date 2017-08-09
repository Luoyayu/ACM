#include<bits/stdc++.h>
/*状压DP第一题 旅行商 TSP 问题

//题意:必须访问N个城市至少一次至多两次,N 座城市, M条道路+费用
//使用3进制数表示1~N个城市的状态
//定义状态dp[i][j]=cost为1~N城市处于i状态,目前最后一个访问的城市是j所需要的费用
//由dp[i][j]转移下到一个城市v: dp[i+3^v][v]=min(dp[i+3^v][v],dp[i][j]+Cjv);
//初始化dp[3^j][j]=0;(j=1.2.3···n)表示从城市j出发的cost=0;

//定义所有N个城市的
*/
using namespace std;
const int  inf = 0x3f3f3f3f;
//3^10 = 59049
//复杂度O(3^n * n)
#define clr(a,b) memset((a),(b),sizeof(a))
const int maxn = (pow(3.0,10.0))+5;
int dp[maxn][11];
#define gets(i,j) ((i)/len[(j)])%3 //计算状态i下城市j的状态(访问次数)
int c[20][20];//距离
int len[11];//三进制状态数
inline void init()
{
    len[0]=1;
    for(int i=1;i<=10;i++)
        len[i]=len[i-1]*3;
}
int main()
{
    int n,m;
    init();
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        clr(dp,inf);clr(c,inf);//初始化状态为inf表示未到达,初始化距离为inf
        for(int i=0;i<m;i++)
        {
            int a,b,w;scanf("%d%d%d",&a,&b,&w);
            c[--a][--b]=c[b][a]=min(c[a][b],w);
        }
        int ans = dp[0][0];//最小费用初始为inf
        for(int i=0;i<n;i++)
            dp[len[i]][i]=0; //初始化城市出发状态,出发费用为0

        for(int i=1;i<len[n];i++)//遍历状态
        {
            bool viss = 1;//假设在状态i下所有的城市都被访问过
            
            for(int j = 0;j < n;j++)
            {
                if(gets(i,j)==0)
                {
                    viss =  0;
                    continue;
                }

                for(int v = 0;v < n;v++)//在状态i下最后到达城市j,转移到其他状态v
                {
                    if(gets(i,v)==2)//城市v已经被访问2次,不能再次访问
                        continue;
                    int u = i + len[v];//计算新的状态
                    dp[u][v] = min(dp[u][v],dp[i][j]+c[j][v]);

                }
            }

            if(viss)
                for(int j = 0;j < n;j++)
                    ans = min(dp[i][j],ans);
        }

        if(ans == dp[0][0])
            ans = -1;
        printf("%d\n",ans);
    }
    return 0;
}
