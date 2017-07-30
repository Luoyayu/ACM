/* by gjp
#include<bits/stdc++.h>
#define N 100000 +  10
#define Q 1000   +  10
#define P 100    +  1
using namespace std;
typedef long long LL;
__int64 a,b,c,d,k;
__int64 sum=0;
__int64 i,j;
int mark[N],prime[N],mobius[N];
LL pre[N];
void structmobius()
{
    int i,j;
    int count=0;
    memset(mark,0,sizeof mark);
    mobius[1]=1;
    for(i=2;i<=N;i++)
    {
        if(mark[i]==0)
        {
            prime[count++]=i;
            mobius[i]=-1;
        }
        for(j=0;j<count;j++)
        {
            if(i*prime[j]>N)
            break;
            mark[i*prime[j]]=1;
            if(i%prime[j]==0)
            {
                mobius[i*prime[j]]=0;
                break;
            }
            else
            mobius[i*prime[j]]-=mobius[i];
        }
    }
    pre[1]=mobius[1];
    for(int i=2;i<N;i++)pre[i]=pre[i-1]+mobius[i];
}

int main()
{
    structmobius();
    int T;scanf("%d",&T);
    for(int cnt=1;cnt<=T;cnt++)
    {
        scanf("%I64d%I64d%I64d%I64d%I64d",&a,&b,&c,&d,&k);if(k==0)
        {
            sum=0;
            printf("Case %d: %I64d\n",cnt,sum);
            continue;
        }
        //a=1;c=1
        b/=k;d/=k;
        LL sum=0LL;
        if(b>=d)swap(b,d);
        int limit=min(b,d);
        int left, right;
        for(int i=1;i<=limit;i=right+1)
        {
            left=i;
            right=min(b/(b/i),d/(d/i));
            sum+=(LL)((pre[right]-pre[left-1])*(b/i)*(d/i));
        }

        LL sum2=0;
        for(int i=1;i<=limit;i=right+1)
        {
            left=i;
            right=b/(b/i);
            sum2+=(LL)((pre[right]-pre[left-1])*(b/i)*(b/i));
        }
        printf("Case %d: %lld\n",cnt,sum-sum2/2);
    }
return 0;
}
*/

#include<bits/stdc++.h>
using namespace std;
//题意:给定x∈[1,b] y∈[1,d]求gcd(x,y)==k的对数,x,y与y,x属于相同的情况
//解法一:容斥 等价于求gcd(x/k,y/k)==1的对数 即x∈[1,b/k],y∈[1,d/k] gcd(x,y)==1
//问题转换为,限制x<y枚举[1,b]中的x再确定另一个区间里与x互质的数的个数 即问题变成 在区间[1,d]中与x互质的数的个数
//可以先求出x的所有质因数,那么在[1,d/k]里是其质因子倍数的数都可以删去,余下的就是互素的数的个数
//if w是x的素因子,那么(1,d)内中是w的倍数的数的个数有d/w个 然后愉快的容斥求出即可
const int maxn = 1e5;
vector<int> prime_factor[555];
void init()
{
    for(int i=2;i*i<maxn;i++)
    {
        if(prime_factor[i].size()==0)
            for(int j=i;j<maxn;j+=i)
                prime_factor[j].push_back(i);
    }
}

int solve(int m,int d)
{
    int ret = 0;
    int cnt = prime_factor[m].size();
    for(int i=1;i<cnt<<1;i++)
    {
        int mulSum = 1,tot = 0;
        for(int j=0;j<cnt;j++)
        {
            if(i&(1<<j))
            {
                tot++;
                mulSum*=prime_factor[m][j];
            }

        }
        if(tot&1) ret+=m/mulSum;
        else ret-=m/mulSum;
    }
    return ret;
}
int main()
{
    init();
    int t;scanf("%d",&t);
    for(int kase =1;kase<=t;kase++)
    {
        int a,b,c,d,k;
        cin>>a>>b>>c>>d>>k;
        b/=k,d/=k;//gcd([1,b]<[1,d])==1//枚举x属于[1,b]
        int ans = 0;
        for(int i=1;i<=b;i++)
            ans+=solve(i,d);
        printf("Case %d: %d\n",kase,ans);
    }
    return 0;
}


//解法二：莫比乌斯反演
//欠下的还是要换的
//设F(d)=gcd(x,y)==1的倍数的对数
//设f(d)=gcd(x,y)==1 题设求f(1)
//由莫比乌斯反演的f(x)=Σ(x|d) u(d/x)F(d);
//F(n)=a/k/n*(b/k/n);
//f(1)=Σ(i=1)
//得:ans = mu[1]*F[1]+mu[2]*F[2]+···+mu[min(a,b)]*F(min(a,b));
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+7;
int mob[maxn],prime[maxn],tot;
bool notprime[maxn];
void init()
{
    mob[1] = 1;
    for(int i=2;i<maxn;i++)
    {
        if(!notprime[i])
        {
            prime[++tot] = i;//更正板子问题 ++前置!
            mob[i] = -1;//若i是质数
        }
        for(int j=1; j<=tot && i*prime[j]<maxn; j++)
        {
            notprime[ i * prime[j] ] = true;//其他情况
            if( i % prime[j]==0)
            {
                mob[i*prime[j] ] = 0;//含有质因子平方的情况
                break;
            }
            mob[i*prime[j]] = -mob[i];
        }
    }
}

int main()
{
    int a,b,c,d,k;
    init();
    int t;scanf("%d",&t);
    for(int kase = 1;kase <= t;kase++)
    {
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
        printf("Case %d: ",kase);
        if(k==0)
        {
            printf("0\n");
            continue;
        }
        b/=k,d/=k;
        long long ans1 = 0,ans2 = 0;
        int MIN = min(b,d);
        for(int i=1;i<=MIN;i++)
            ans1+=(long long)mob[i]*(b/i)*(d/i);
        for(int i=1;i<=MIN;i++)
            ans2+=(long long)mob[i]*(MIN/i)*(MIN/i);
        printf("%lld\n",ans1-ans2/2);
    }
    return 0;
}


