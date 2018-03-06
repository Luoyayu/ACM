///数论 建模搜索bfs 实际上是个暴力枚举题，但是需要确定无结果的停止条件
///给定一个正整数n,和若干个mi，求最小的n的倍数，且各个位不含有mi
///数位DP思路,从低位到高位枚举，先枚举低位A,然后A*10变成高位，在枚举B,当前结果为A*10+B,如果这种情况不行的话把他的余数记录,以此为余数的都不行
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<queue>
#define next Next
using namespace std;
const int maxn=10000+5;
bool vis[maxn],del[maxn];
int n,m;
int pre[maxn];
char ans[maxn];
bool bfs()
{
    queue<int>q;
    q.push(0);
    while(!q.empty())
    {
        int cur=q.front();q.pop();
        for(int i=0;i<=9;i++)//从低位晋升高位的枚举
        {
            if(del[i] || !cur&&!i) //0不能作为高位,第一次不能给0
                continue;
            int next=(cur*10+i)%n;
            if(vis[next]) continue;
//还是对模数进行分类,如果摸到了余数一样的数，那么对该数的操作与哪个数结果一样的，不满足条件剪枝跳过。
            ans[next]= (char) ('0' + i);vis[next]=1;
            pre[next]=cur;
            q.push(next);

            if(!next) return 1;//OK
        }
    }
    return 0;//模边也没有
}
void solve()
{
    string res;
    int p=0;
    while(p!=0||res.empty())
    {
        res+=ans[p];
        p=pre[p];
    }
    reverse(res.begin(),res.end());
    printf("%s\n",res.c_str());
}
int main()
{
    int kase=1;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(vis,0,sizeof vis);
        memset(del,0,sizeof del);
        while(m--)
        {
            int k;scanf("%d",&k);
            del[k]=true;
        }
        printf("Case %d: ",kase++);
        if(bfs())
            solve();
        else
            printf("-1\n");
    }
    return 0;
}

