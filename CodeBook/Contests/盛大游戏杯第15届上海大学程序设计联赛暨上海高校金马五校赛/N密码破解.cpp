#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e8+10;
int dp[maxn];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        dp[0]=0;
        int Maxlen = 0;
        int a;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a);
            int left = 0,right = Maxlen - 1;
            while(left<=right)
            {
                int mid = (left+right)>>1;
                if(dp[mid]>=a)
                    right=mid -1;
                else
                    left = mid+1;
            }
            if(left>=Maxlen) Maxlen++;
            dp[left]=a;
        }
        printf("%d\n",Maxlen);
    }
    return 0;
}
