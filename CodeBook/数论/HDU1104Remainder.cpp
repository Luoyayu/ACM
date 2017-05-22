///2017年5月19日17点13分
///给定三个整数 N,M,K 对于N有三种操作，N+M,N-M,N*M,N%M;
///问怎么样最少操作使得(起始N+1)%K==(现在N)%K
///注意此处的mod模后的结果都为正,故A%B=(A%B+B)%B;
///由HDU4474的结论可知,模数相等的情况下对两个数操作结果是一致的
///担心自己忘了还是写一边吧:
#include<cstdio>
#include<vector>
#include<string>
#include<queue>
#include<iostream>
#include<cstring>
int mod;
int n,m,k;
const int maxn=1000000+555;
bool vis[maxn];
using namespace std;
struct node
{
    int num;
    int step;
    string road;
}q1,now;
void bfs()
{
    memset(vis,0,sizeof vis);
    queue<node> q;
    q1.num=n,q1.step=0,q1.road="";
    q.push(q1);
    vis[(n%k+k)%k]=1;//标记该余数
    while(!q.empty())
    {
        now = q.front();q.pop();
        if(((n+1)%k+k)%k == (now.num%k+k)%k)
        {
            printf("%d\n",now.step);
            cout<<now.road<<endl;
            return;
        }
        q1.step=now.step+1;
        for(int i=0;i<4;i++)
        {
            if(i==0)
            {
                q1.num = (now.num+m)%mod;
                q1.road = now.road+'+';
            }
            else if(i==1)
            {
                q1.num = (now.num-m)%mod;
                q1.road = now.road+'-';
            }
            else if(i==2)
            {
                q1.num = (now.num*m)%mod;
                q1.road = now.road+'*';
            }
            else
            {
                q1.num = (now.num%m+m)%m%mod;
                q1.road = now.road+'%';
            }

            if(!vis[(q1.num%k+k)%k])
            {
                q.push(q1);
                vis[(q1.num%k+k)%k]=1;
            }
        }
    }
    printf("0\n");
}
int main()
{
    while(scanf("%d%d%d",&n,&k,&m)!=EOF,(n||k||m))
    {
        mod=k*m;//由于有操作N%M,对于N%N%K是错误的,故每次mod (N*K)稳
        bfs();
    }
    return 0;
}
