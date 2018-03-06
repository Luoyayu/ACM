/*
*mobius反演定理定义F(n)和f(n)为在非负整数集上的两个函数
*并且满足F(n)=Σ(d|n) F(n/d) 既对于每个n的因子d F(商) 
*有结论f(n)=Σ(d|n) μ(d)F(n/d)
*定义μ(d) = d=1 μ(1)=1;
*2)         d=奇数个素数之积 μ(d)=-1;
*3)         d=偶数个素数之积 μ(d)=1;
*其他情况下如含有平方因子μ(d) = 0;(可以用Pollard_Rho分解出质因子然后YY)

*对于μ(d) 函数的常见性质
*1) Σ(d|n) μ(d) = 1(n==1)
*   Σ(d|n) μ(d) = 0(n>1)
*2) 对于任意正整数n有Σ(d|n) μ(d)/n = φ(n)/n
如果f(d) 让g(m)是积性函数。那么f(d) 是积性函数(这个结论很重要)。
*/
//线筛求解mobius函数值
int mob[maxn],prime[maxn],tot;
bool notprime[maxn];
void getMobius()
{
    mob[1]=1;
    for(int i=2;i<maxn;i++)
    {
        if(!notprime[i])
        {
            prime[++tot]=i;
            mob[i] = -1;//若i是质数
        }
        for(int j=1;j<=tot && i*prime[j]<maxn;j++)
        {
            notprime[ i * prime[j] ] = 1;//其他情况
            if( i % prime[j]==0)
            {
                mob[i*prime[j]]=0;
                break;
            }
            mob[i*prime[j]]=-mob[i];
        }
    }
}
//单次求解莫比乌斯函数
//莫比乌斯反演的证明


//莫比乌斯函数的应用
1.求1~N对质数p的乘法逆元

