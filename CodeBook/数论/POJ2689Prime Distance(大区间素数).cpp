//好题 大区间筛素数
#include<cstdio>
#include<cstring>
#include<algorithm>
//题意给出范围[l,u]算出最近的素数距离和最远的素数距离
//大区间素数筛选,考虑到区间长度只有1e6,可以算出1e6中的合数,然后余下的是素数
//方法是求出1e6内的素数用他们的倍数来筛[l,r]中的合数,注意数组开不下要来个区间映射
using namespace std;
typedef long long ll;
int L,R;
const int maxn=1e5+7;
int prime[maxn];//prime[i]==0为质数
void getPrime()
{
    for(int i=2;i<=maxn;i++)
    {
        if(!prime[i]) prime[++prime[0]]=i;
        for(int j=1;j<=prime[0]&&prime[j]<=maxn/i;j++)
        {
            prime[prime[j] * i] = 1;//不是素数
            if(i % prime[j]==0) break;
        }
    }
}
const int maxc = 1e6+7;
bool notprime[maxc];
int prime2[maxc];//存大区间素数
void getPrime2()//计算区间素数
{
    memset(notprime,0,sizeof notprime);
    if(L<2) L=2;
    for(int i=1;i<=prime[0]&&(long long)prime[i]*prime[i]<=R;i++) //用小区间去筛大区间
    {
        int s = L/prime[i]+(L%prime[i]>0);//倍数
        if(s==1)s=2;//注意s==1时会把2筛成合数
        for(int j=s;(long long)j*prime[i]<=R;j++)
            if((long long)j*prime[i]>=L)
                notprime[j*prime[i]-L]=1;//区间映射 X-L
    }//懵圈写错位置 T出天际
        prime2[0]=0;
        for(int i=0;i<=R-L;i++)//开新数组区间映射回去X+L
            if(!notprime[i])
                prime2[++prime2[0]]=i+L;
}
int main()
{
    getPrime();
    while(scanf("%d%d",&L,&R)!=EOF)
    {
        getPrime2();
        if(prime2[0]<2) printf("There are no adjacent primes.\n");
        else
        {
            int x1 = 0,x2=1e9,y1 = 0, y2 = 0;
            for(int i=1;i<prime2[0];i++)
            {
                if(prime2[i+1]-prime2[i]<x2-x1)
                {
                    x1 = prime2[i];
                    x2 = prime2[i+1];
                }
                if(prime2[i+1]-prime2[i]>y2-y1)
                {
                    y1 = prime2[i];
                    y2 = prime2[i+1];
                }
            }
            printf("%d,%d are closest, %d,%d are most distant.\n",x1,x2,y1,y2);
        }
    }
    return 0;
}
