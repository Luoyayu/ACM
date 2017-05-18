
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
#define MAX 800000
typedef __int64 LL;
LL su[MAX];
int cnt=1;
bool isprime[MAX]={0,0};
void prime()
{
    //fill(isprime+2,isprime+MAX,1);
    memset(isprime,1,sizeof(isprime));
    for(LL i=2;i<=MAX;i++)
    {
        if(isprime[i])
            su[cnt++]=i;
        for(LL j=1;j<cnt&&su[j]*i<MAX;j++)
            isprime[su[j]*i]=0;//筛掉小于等于i的素数和i的积构成的合数
    }
}
int main()
{
    prime();
    //for(LL i=1;i<cnt;i++)
        //printf("%d ",su[i]);
    printf("OK\n");
    return 0;
}
