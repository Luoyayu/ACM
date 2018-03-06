#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 471115667135LL;
const int maxn=1000000+10;
ll A[maxn];
ll multi(ll a, ll b)
{
    return (a%mod) * (b%mod) %mod;
}
void pre()
{
    for(int i=0;i<maxn;i++) A[i]=1;
    for(int i=1;i<maxn;i++)
        for(int j=i;j<maxn;j+=i)
        A[j]=multi(A[j], i);4
}
int main()
{
    int n;
    pre();
    while(scanf("%d",&n)!=EOF)
        printf("%lld\n",A[n]);
    return 0;
}
