#include<bits/stdc++.h>
#define rep(i,a,b) for(i=a;i<=b;i++)
#define rec(i,a)   for(i=0;i< a;i++)
const int B = 100000 +  10;
const int N = 10000  +  10;
const int Q = 1000   +  10;
const int P = 100    +  10;
using namespace std;
#define LL long long int
LL __gcd(LL a,LL b)
{
    return b==0?a:__gcd(b,a%b);
}
LL fastmutipuly(LL a,LL b,LL n)
{
    LL exp=a%n;
	LL res=0;
    while(b)
    {
        if(b&1)
        {
            res+=exp;
            if(res>n)res-=n;
        }
        exp<<=1;
        if(exp>n)
        exp-=n;
        b>>=1;
    }
    return res;
}
LL exp_mod(LL a,LL b,LL mod)
{
    LL t1=1;
    LL t2=a;
    while(b)
    {
        if(b&1)
        t1=fastmutipuly(t1,t2,mod);
        t2=fastmutipuly(t2,t2,mod);
        b>>=1;
    }
    return t1;
}
bool Miller_Rabbin(LL n, LL times)
{
    if(n==2)return 1;
    if(n<2||!(n&1))return 0;

    LL a,u=n-1,x,y;
    int t=0;
    while(u%2==0)
    {
        t++;
        u/=2;
    }
    srand(100);
    for(int i=0;i<times;i++)
    {
        a=rand()%(n-1)+1;
        x=exp_mod(a,u,n);
        for(int j=0;j<t;j++)
        {
            y=fastmutipuly(x,x,n);
            if(y==1&&x!=1&&x!=n-1) return false;
            x=y;
        }
        if(y!=1) return false;
    }
    return true;
}
LL Pollard_Rho(LL n,LL c)
{
    LL x,y,d,i=1,k=2;
    y=x=rand()%(n-1)+1;
    while(1)
    {
        i++;
        x = (fastmutipuly(x,x,n)+c)%n;
        d = __gcd((x-y+n)%n,n);
        if(d>1&&d<n)
            return d;
        if(x==y)
            return n;
        if(i==k)
        {
            k<<=1;
            y = x;
        }
    }
}
LL factor[200],cnt;
void Find_factor(LL n,LL c)
{
    if(n==1)return;
    if(Miller_Rabbin(n,6))
    {
        factor[cnt++] = n;
        return;
    }
    LL p=n;
    LL k=c;
    while(p>=n)
    p=Pollard_Rho(p,c--);
    Find_factor(p,k);
    Find_factor(n/p,k);
}
LL a_b(LL a,LL b)
{
    LL t1=1;
    LL t2=a;
    while(b)
    {
        if(b&1)
        t1=t1*t2;
        t2=t2*t2;
        b>>=1;
    }
    return t1;
}
map<LL,int>Map;
int main()
{
    LL n;
    int T;
    scanf("%d",&T);
    for(int __cnt=1;__cnt<=T;__cnt++)
    {
        scanf("%lld",&n);
        cnt=0;
        memset(factor,0,sizeof factor);
        if(Miller_Rabbin(n,6))
        {
        	printf("-1\n");continue;
        }
		Find_factor(n,120);
        Map.clear();
        for(int i=0;i<cnt;i++)Map[factor[i]]++;

        int mark=0;
        for(map<LL,int>::iterator it = Map.begin();it!=Map.end();it++)
        {
            if(it->second>=2)mark=1;
            if(mark)break;
        }
        if(mark)printf("0\n");
        else
        {
            LL sum=1;
            int size=Map.size();
            if(size&1)printf("-1\n");else printf("1\n");
        }
    }
    return 0;
}
