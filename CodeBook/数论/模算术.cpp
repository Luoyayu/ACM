#include<cstdio>
typedef unsigned long long ull;
///a ^p % n
ull pow_mod(ull a,ull p,ull n)
{
    if(!p) return 1;
    ull ans=pow_mod(a,p>>1,n);
    ans=(ans%n)*(ans%n)%n;
    if(p&1) ans=(ans%n)*(a%n)%n;
    return ans;
}
int main()
{
    ull a,p,n;
    scanf("%lld%lld%lld",&a,&p,&n);
    printf("%lld\n",pow_mod(a,p,n));
    return 0;
}
