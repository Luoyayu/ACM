#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// 题意：定义向量距离为$\sum_{i=1}^n|a_i-b_i|^p$
// 当两向量的元素个数相同时求距离的运算才有效
// 给出n,v,p;
// 表示给出的A，B向量的长度为n,我们要从A，B中取其子向量，所谓子向量是从原向量中连续的a_i构成的新向量
// 问有多少组子向量A，B满足dis(A,b)<=v, p∈{1,2,3} n<=1e5
// 思想双指针$O(n^2)$枚举，
// 对右端点，左端点按单调性枚举

const int maxn = 1e5+7;
ll a[maxn],b[maxn];
ll v, p, f[maxn][maxn], w[maxn<<2], g[maxn];

inline cal(ll x)
{
    if(x<0) x=-x;
    ll ret = 1;
    for(int i=1;i<=p;i++) ret*=x;
    return ret;
}
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d%lld%lld",&n,&v,&p);

        memset(g,0,sizeof(g));
        memset(w,0,sizeof(w));

        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        for(int i=1;i<=n;i++) scanf("%lld",&b[i]);

        ll ans = 0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                f[i][j] = cal(a[i]-b[i]); // 先预算abs(A_i-B_j)^p;

        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                int k = i - j + n;
                g[k]++;
                w[k] += f[i][j];
                int G = g[k]; ll W = w[k];
                while(G>0 && W > V)
                {
                    G--;
                    w -= f[i-G][j-G];
                }
                g[k] = G; w[k] = W;
                ans += G;
            }
        printf("%lld\n",ans);
    }
    return 0;
}