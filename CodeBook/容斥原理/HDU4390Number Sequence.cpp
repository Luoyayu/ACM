#include<bits/stdc++.h>
///容斥原理第三题
///给定b序列 初步想法对b序列的每个元素搞成A*B把A B乘到其余的数位上包括自己，
///再次思考每个数都有唯一质分解，就是对于bi质分解统计形成乘积的所有的质分解，那么问题转换成把这些质因子重新组合形成成n份
///问题转换成组合计数把m个数放进n个容器，但是题目要求a>1意味着每个容器都有元素
///对于相同质因子p,记个数为mi,总方案数既 C(n-1) (mi+n-1)
///在对于至少一个为空，至少两个为空容斥
using namespace std;
typedef long long ll;
const ll maxn = 1000000+10;
const ll mod = 1e9+7;
ll n,m;
ll b[maxn],C[505][505];
vector <int> v;
void init()
{
    for(int i=0;i<=500;i++)
    {
        C[i][0]=C[i][i]=1;
        for(int j=1;j<i;j++)
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
    }
    return ;
}
ll getRaw(int n, int m)
{
    return C[m+n-1][n-1];
}
void prime_factor(int num)
{
    for(ll i=2;i*i<=num;i++)
    {
        if(num%i==0)
        {
            v.push_back(i);
            while(num%i==0)
                num/=i;
        }
    }
    if(num>1) v.push_back(num);
    return ;
}
int solve()
{
    int a[maxn]={1},cnt=0;
    sort(v.begin(),v.end());
    for(int i=1;i<v.size();i++)
    {
        if(v[i]!=v[i-1]) a[++cnt]=1;
        else a[++cnt]++;
    }
    ll ans=1;
    for(int i=0;i<=cnt;i++) ans=(ans%mod*(getRaw(n,a[i])%mod))%mod;
    for(int i=1;i<n;i++)
    {
        ll tmp=C[n][i];
        for(int j=0;j<=cnt;j++)
            tmp=(tmp%mod*getRaw(n-i,a[j]))%mod;
        if(i&1) ans+=((ans-tmp)%mod+mod)%mod;
        else ans-=((ans+tmp)%mod);
    }
    return ans;
}
int main()
{
    init();
    while(scanf("%lld",&n)!=EOF)
    {
        v.clear();
        for(int i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            prime_factor(x);
        }
        printf("%lld\n",solve());
    }
    return 0;
}
