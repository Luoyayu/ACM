//最大递增子串和不要求连续
//dp[i]表示以i结尾的最大子串和
#include<bits/stdc++.h>
using namespace std;
const int maxn=1000 + 5;
int a[maxn],dp[maxn];
int main()
{
    int n,MAX;
    while(scanf("%d",&n)!=EOF,n)
    {
        memset(dp,0,sizeof dp);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        dp[1]=a[1];
        for(int i=2;i<=n;i++)//所有的序列都是以i结尾的子序列构成
        {
            MAX=0;
            for(int j=1;j<i;j++)
                if(a[j]<a[i])//在a[i]前的比他小的数才被考虑
                    MAX=max(dp[j],MAX);//比较前面的各个以i结尾的子串和
            dp[i]=MAX+a[i];//加上这个数构成以i结尾的数的最大子序列
           //printf("%d %d\n",MAX,dp[i]);
        }
        MAX = dp[1];
        for(int i=1;i<=n;i++)
            MAX = max(dp[i],MAX);
        printf("%d\n",MAX);
    }
}
