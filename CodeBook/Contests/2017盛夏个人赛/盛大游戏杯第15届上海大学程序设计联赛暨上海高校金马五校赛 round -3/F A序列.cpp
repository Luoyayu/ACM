#include<bits/stdc++.h>
using namespace std;
const int maxn = 500010;
int L_id[maxn],R_id[maxn], dp[maxn],a[maxn],n;
//子序列[L,R] L_id[i]正向扫记录以第i个元素结尾的最长递增子序列长度,
//R_id[i]从后向前扫得出的就是第i个元素开始的子序列的最长递减子序列长度
//ans = min()
int main()
{
    while(scanf("%d", &n)!=EOF)
    {
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);

        int len = 1;L_id[1] = 1;
        dp[1] = a[1];
        for(int i = 2; i <= n; i++)
        {
            if(a[i] > dp[len])
            {
                dp[++len] = a[i];
                L_id[i] = len;
            }
            else
            {
                int pos = lower_bound(dp+1, dp + len+1 , a[i]) - dp;
                L_id[i] = pos;dp[pos] = a[i];
            }
        }

        len = R_id[n] = 1;
        dp[1] = a[n];

        for(int i = n - 1; i >= 1; i--)//反向遍历
        {
            if(a[i] > dp[len])
            {
                dp[++len] = a[i];
                R_id[i] = len;
            }
            else
            {
                int pos = lower_bound(dp, dp + len , a[i]) - dp;
                R_id[i] = pos;dp[pos] = a[i];
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++)
            ans =max(ans, min(2*L_id[i]-1,2*R_id[i]-1));
        cout<<ans<<endl;
    }
    return 0;
}
