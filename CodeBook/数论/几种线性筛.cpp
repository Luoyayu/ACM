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
/*若i为奇数个不同素数之积,mob[i]=-1,当n为质数的时候 mob[]=-1;
* 若i为偶数个不同素数之积,mob[i]=1;
* 若i有平方因子(既把n质分解后有某项质数的质数>1)mob[i]=0;(其他情况)
* 由积性函数的性质知mob[a*b]=mob[a]*mob[b] 若b有平方因子那么通过n*b可以筛去
*/
int mob[maxn];
int notprime[maxn];
int prime[manx];
void getMobius()
{
    int Mtot=0;
    moi[1]=1;
    for(int i=2;i<maxn;i++)
    {
        if(notprime[i])
        {
            prime[Mtot++]=i;
            mob[i]=-1;//若i是质数
        }
        for(int j=1;j<Mtot && i*prime[j]<maxn;j++)
        {
            notprime[ i * p[j] ] = 0;//其他情况
            if( i % prime[j]==0)
            {
                mob[i*prime[j]]=0;
                break;
            }
            mob[i*p[j]]=-mob[i];
        }
    }
}


//一筛三用 模板
bool isNotPrime[MAXN + 1];
int mu[MAXN + 1], phi[MAXN + 1], primes[MAXN + 1], cnt;
inline void euler()
{
    isNotPrime[0] = isNotPrime[1] = true;
    mu[1] = phi[1] = 1;
    for (int i = 2; i <= MAXN; i++)
    {
        if (!isNotPrime[i])
        {
            primes[++cnt] = i;
            mu[i] = -1;
            phi[i] = i - 1;
        }

        for (int j = 1; j <= cnt; j++)
        {
            int t = i * primes[j];
            if (t > MAXN) break;

            isNotPrime[t] = true;

            if (i % primes[j] == 0)
            {
                mu[t] = 0;
                phi[t] = phi[i] * primes[j];
                break;
            }
            else
            {
                mu[t] = -mu[i];
                phi[t] = phi[i] * (primes[j] - 1);
            }
        }
    }
}
