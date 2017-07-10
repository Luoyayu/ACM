//欠下的还是要还的
#include<bit/stdc++.h>
using namespace std; 
int main()
/*O(n^2)解法 
* 定义dp[i]表示为以第i个位置的数作为子序列中的最后一个元素时,能够构成子序列的最大长度.
* 建立转移方程: dp[i] = max(dp[i], dp[j] + 1) (j<i && a[j]<a[i])
*/
int getMaxlen()
{
    int MAXlen = 0;
    for(int i = 0; i < n; i++)
    {
        dp[i]=1;
        for(int j = 0; j < i ; j++)
            if(a[j] > a[i])
                dp[i] = max(dp[i], dp[j]+1);
        MAX = max(MAX, dp[i]);//find max
    }
    return MAXlen;
}

/*O(nlogn)解法 就是在j(0~i)找最大值时采用二分的思想
* 定义mininum[i] 表示在处理当前位置时,由之前元素构成的所有长度为i的子序列中,最后一个元素的最小值
*/
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
