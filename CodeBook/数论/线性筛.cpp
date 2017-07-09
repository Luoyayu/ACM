
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
#define MAX 800000
const int maxn=10005;
bool isprime[maxn];//isprime[i]表示i是不是质数
int p[maxn], tot=0;//p[maxn]用来存质数 tot从0计数
void init()
{
    memset(isprime,1,sizeof isprime);//假设都是质数
    for(int i = 2; i < maxn; i++)
    {
        if(isprime[i]) p[tot ++] = i;//把质数存起来
        for(int j = 0; j < tot && i * p[j] < maxn; j++)
        {
            isprime[i * p[j]] = false;
            if(i % p[j] == 0) break;//保证每个合数被它最小的质因数筛去
        }
    }
}
int main()
{
    init();
    for(int i=1;i<tot;i++)
        printf("%d,",p[i]);
    printf("OK\n");
    return 0;
}
