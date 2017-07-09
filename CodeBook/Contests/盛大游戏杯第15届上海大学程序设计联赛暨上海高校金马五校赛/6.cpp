#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
int n,a[500005],dp[500005],dp1[500005];
int main()
{

    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<=n/2;i++)
        {
             dp[i]=1;
             for(int j=0;j<i;j++)
             {
                 if(a[j]<a[i])
                    dp[i]=max(dp[i],dp[j]+1);
             }
        }

        for(int i=n-1;i>=n/2;i--)
        {
            dp1[i]=1;
            for(int j=n-1;j>i;j--)
            {
                if(a[j]<a[i])
                {
                    dp1[i]=max(dp1[i],dp1[j]+1);
                }
            }
        }
        int maxx=-1;
        for(int i=0;i<n;i++)
            maxx=max(maxx,dp[i]+dp1[i]-1);
        printf("%d\n",maxx);
    }
    return 0;
}
