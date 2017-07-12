//孪生素数对数
#include<cstdio>
#include<cstring>
#include<cmath>
#define lowbit(x) (x&(-x))
using namespace std;
const int maxn=100005;
int c[maxn],n;
int prime[maxn];
bool vis[maxn];
void add(int x,int d)
{
    while(x<=maxn)
        c[x]+=d,x+=lowbit(x);
}
int sum(int x)
{
    int ret=0;
    while(x)
       ret+=c[x],x-=lowbit(x);
    return ret;
}

int main()
{
    memset(vis,0,sizeof vis);
    int NUM=1;
    for(int i=2;i<maxn;i++)
        if(!vis[i])
        {
            prime[NUM++]=i;
             for(int j=2*i;j<maxn;j+=i)
               vis[j]=1;
        }


    //for(int i=1;i<maxn;i++)
       //printf("%d ",prime[i]);
    for(int i=2;i<=maxn;i++)
        if(prime[i]-prime[i-1]==2)
            add(prime[i],1);
    while(scanf("%d",&n)!=EOF&&n>=0)
    {
        if(n==1)
            printf("0\n");
        else
            printf("%d\n",sum(n));
    }
    return 0;

}
