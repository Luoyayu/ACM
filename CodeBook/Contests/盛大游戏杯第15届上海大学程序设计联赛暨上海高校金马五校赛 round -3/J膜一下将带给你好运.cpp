#include<bits/stdc++.h>
using namespace std;
const int B = 4000000  +  10;
const int N = 10000    +  10;
const int Q = 1000     +  10;
const int P = 100      +  10;
#define LL long long int
#define clr(a) memset(a,0,sizeof a)
const LL mod = 1000000007LL;
int phi[B]={0};
int pre[B]={0};
void f()
{
    int i,j;
    phi[1]=1;
    for(i=2;i<B;i++)
    {
        if(phi[i]==0)
        {
            for(j=i;j<B;j+=i)
            {
                if(phi[j]==0)
                phi[j]=j;
                phi[j]=phi[j]/i*(i-1);
            }
        }
    }
    for(int i=1;i<B;i++)pre[i]%=mod;
    pre[1]=phi[1];
    for(int i=2;i<B;i++)pre[i]=(pre[i-1]+phi[i])%mod;

}
#define function fff
LL function(LL n)
{
	if(n<B)return pre[n];
	else
	{
		LL sum=0;
		int left;
		int right;
		for(int i=2;i<=n;i=right+1)
		{
			left=i;
			right=n/(n/i);
			sum+=(function(n/i)%mod)*((right-left+1))%mod;
			sum%=mod;
		}
		LL u=(n*(n+1)/2-sum);
		u%=mod;
		u+=mod;
		u%=mod;
		return u;;

	}
}
int main()
{
    f();
    int T;
    LL n;
    scanf("%d",&T);
    for(int cnt=1;cnt<=T;cnt++)
    {
        scanf("%lld",&n);
        LL sum=0;
        LL limit=n-233;

        LL left;
        LL right;
        for(int i=233;i<=limit;i=right+1)
        {
            left=i;
            right=min(n/(n/i),limit);
            LL u=function(right)-function(left-1);
               
            u%=mod;
            u+=mod;
            u%=mod;

            u=u*(n/i);
            u%=mod;

            sum= (sum +u) %mod;
        }
        printf("%lld\n",sum);
        /*
        n=100000000时输出770753391
        */
    }
return 0;
}

//高神太强了,Σ phi(n)*(n/i)=n/2*(n+1)
//证明:
#include<bits/stdc++.h>
using namespace std;
#define LL long long int
const LL mod = 1000000007LL;
LL phi(LL n)
{
    LL result=n;
    LL limit=(LL)sqrt(n+0.5);
    for(int i=2;i<=limit;i++)
    {
        if(n%i==0)
        {
            result=result/(i)*(i-1);
            while(n%i==0) n/=i;
        }
    }
    if(n>1)result=result/n*(n-1);
    return result;
}
LL muti(LL a,LL b)
{
    return (a%mod)*(b%mod)%mod;
}
LL f(LL n)
{
    if(n&1)return muti((n+1)/2,n);
    else return muti(n/2,n+1);
}
int main()
{
    int T;
    LL n;
    scanf("%d",&T);
    for(int cnt=1;cnt<=T;cnt++)
    {
        scanf("%lld",&n);
        LL a=f(n);
        LL b=0;
        for(int i=1;i<=232;i++)
        {
            b=b+(n/i)*phi(i)%mod;
            b%=mod;
        }
        for(int i=n-232;i<=n;i++)
        {
            b=b+(n/i)*phi(i)%mod;
            b%=mod;
        }
        a-=b;a%=mod;a+=mod;a%=mod;
        printf("%lld\n",a);

    }
    return 0;
}
