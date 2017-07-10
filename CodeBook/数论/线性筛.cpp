#include<bits/stdc++.h>
using namespace std;
const int maxn=10005;
bool notprime[maxn];//notprime[i]==0表示i是质数
int p[maxn], Ptot=0;//p[maxn]用来存质数 tot从0计数
void getPrime()
{
    for(int i = 2; i <= maxn; i++)
    {
        if(!notprime[i]) p[Ptot++] = i;//把质数存起来
        for(int j = 0; j < Ptot && i * p[j] < maxn; j++)
        {
            notprime[i * p[j]] =1;
            if(i % p[j] == 0) break;//确保每个合数只被它最小的质因数筛去
        }
    }
    return ;
}
int main()
{
    getPrime();
    for(int i=1;i<tot;i++)
        printf("%d ",p[i]);
    printf("OK\n");
    return 0;
}

//mobius线筛
/*若i为奇数个不同素数之积,mob[i]=-1,
* 若i为偶数个不同素数之积,mob[i]=1;
* 若i有平方因子mob[i]=0;(其他情况)
*/
int mob[maxn];
void getMobius()
{
    int Mtot=0;
    moi[1]=1;
    for(int i=2;i<maxn;i++)
    {
        if(notprime[i])
        {
            prime[Mtot++]=i;
            mob[i]=-1;
        }
        for(int j=1;j<maxn&&i*prime[j]<maxn;j++)
        
    }
}
