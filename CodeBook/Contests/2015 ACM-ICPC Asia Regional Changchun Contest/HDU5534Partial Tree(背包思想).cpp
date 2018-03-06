#include <bits/stdc++.h>
//题意：
using namespace std;
const int maxn=  2015;
const int inf = 0x3f3f3f3f;
int w[maxn];
int dp[maxn];
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n;scanf("%d",&n);
        for(int i=0;i<n-1;i++) scanf("%d",&w[i]);
        for(int i=1;i<n-1;i++) w[i] -= w[0], dp[i] = -inf;
        dp[0] = 0;

        for(int i=1;i<=n-2;i++)
            for(int se=i;se<=n-2;se++)
                dp[se] = max(dp[se],dp[se-i]+w[i]);
        printf("%d\n",dp[n-2]+w[0] * n);
    }
    return 0;
}