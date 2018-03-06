//Wiki公式题
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
const int mod = int (1e9+7);
typedef long long ll;
const int maxn = int(1e5+7);
int dp[maxn];
void init()
{
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(int i=1;i<maxn;i++)
    {
        for(int j = 1,r = 1;i-(3*j*j-j)/2>=0;j++,r*=-1)
        {
            dp[i] += dp[i-(3*j*j-j)/2] * r;
            dp[i] %= mod;
            dp[i]=(dp[i] + mod) % mod;
            if(i-(3*j*j+j)/2>=0)
            {
                dp[i] += dp[i-(3*j*j+j)/2]*r;
                dp[i] %= mod;
                dp[i] = (dp[i]+mod)%mod;
            }
        }
    }
}
int main()
{
    init();
    int t;scanf("%d", &t);
    while(t--)
    {
        int n;scanf("%d", &n);
        printf("%d\n",dp[n]);
    }
    return 0;
}