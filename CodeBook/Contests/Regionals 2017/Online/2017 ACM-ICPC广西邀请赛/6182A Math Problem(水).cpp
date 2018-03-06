#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
//题意:求有多少k满足k^k<=n n(1e18)
//大概16^16=1e19 题设1e^18
//有点蠢,手撸快速乘,快速幂练习

ll qmul(ll a,ll b) //cal (a*b)
{
    ll ret = 0, t = a;
    while(b)
    {
        if(b&1) ret+=t;
        k+=k;b>>=1;
    }
    return ret;
}

ll power(ll a,ll b)//cal a^b //二进制拆b遇到1累乘否则累乘基数 
{
    ll ret = 1, t = a;
    while(b)
    {
        if(b&1) ret = qmul(ret,t);
        t=qmul(t,t);b>>=1;
    }
    return ret;
}
typedef long long ll;
const int maxn = 16;
ll ans[maxn];
int main()
{
    for(int i=1;i<=maxn;i++)
        ans[i] = power(i*1LL,i*1LL);
    int n;
    while(cin>>a)
    {
        int cnt = 0;
        for(int i=1;i<=maxn;i++)
            if(ans[i]<=n) cnt ++;
        printf("%d\n",cnt);
    }
    return 0;
}