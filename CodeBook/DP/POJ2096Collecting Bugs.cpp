//题目太长看(((φ(◎ロ◎;)φ)))
//一个软件有s各子系统,产生n个bug
//且一个bu只属于一个子系统，属于一个分类
//Ivan每天发现一个bug,这个bug属于某个子系统的概率是1/s,属于某个分类个概率是1/n
//问发现n种ug，且每个子系统都发现bug的天数的期望
//状态：dp[i][j]表示已经找到i中bugs，达到目标状态的天数的期望
//转移方程:     dp[i][j]=(i/n)*(j/s)
//              dp[i][j+1]=(i/n)*(1-j/s)
//              dp[i+1][j]=(1-i/n)*(j/s)
//              dp[i+1][j+1]=(1-i/n)*(1-j/s)
//整理的：dp[i][j]=
//边界：dp[n][s]=0
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1000+10;
double dp[maxn][maxn];
int main()
{
    int n,s;
    while(scanf("%d %d",&n,&s)!=EOF)
    {
        memset(dp,0,sizeof dp);
        for(int i=n;i>=0;i--)
            for(int j=s;j>=0;j--)
                if(i==n&&j==s)
                    dp[i][j]=0;
                else
                    dp[i][j]=(i*(s-j)*dp[i][j+1]+(n-i)*j*dp[i+1][j]+(n-i)*(s-j)*dp[i+1][j+1]+n*s)/(n*s-i*j);
            printf("%.4lf\n",dp[0][0]);
    }
    return 0;
}
