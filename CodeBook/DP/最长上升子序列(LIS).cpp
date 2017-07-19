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
        dp[i]=1;//init
        for(int j = 0; j < i ; j++)
            if(a[j] > a[i])
                dp[i] = max(dp[i], dp[j]+1);
        MAX = max(MAX, dp[i]);//find max
    }
    return MAXlen;
}

/*O(nlogn)解法 就是在j(0~i)找最大值时采用二分的思想
* 定义dp[i] 表示在处理当前位置时,由之前元素构成的所有长度为i的子序列中,最后一个元素的最小值,
* 可知dp[]具有单调性,遂可以借助二分优化到(logn)
*/
//边读边处理的写法
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e8+10;
int dp[maxn];
int main()
{
    int n,a,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        dp[0]=0;
        int Maxlen = 0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a);
            int left = 0,right = Maxlen - 1;
            while(left <= right)
            {
                int mid = (left+right)>>1;
                if(dp[mid]>=a)
                    right = mid -1;
                else
                    left = mid + 1;
            }
            if(left >= Maxlen) Maxlen++;
            dp[left] = a;
        }
        printf("%d\n",Maxlen);
    }
    return 0;
}

//使用STL的nlogn写法
int a[maxn];
int dp[maxn];
int main2()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n;scanf("%d",&n);
        for(int i=1;i<=nn;i++)
            scanf("%d",&a[i]);

        dp[1]=a[1];
        int len = 1;
        for(int i=2; i<=n; i++)
        {
            if(a[i]>dp[len])//if 当前待选数字比当前以len为长度的结尾的元素大,加入这个元素
                dp[++len] = a[i];
            else//插入a[i]维护递增dp[]数组
            {
                int pos = lower_bound(dp+1,dp+len+1,a[i])-dp;
                dp[pos] = a[i];
            }
        }   
        printf("%d\n",len);
    }
    return 0;
}

//浙大模板
const int  MAX = 1000010 ;
#define cmp(a,b) ((a)>(b))
int n,num[MAX],len_min[MAX];
int binary_search(int a,int b,int k)
{
    int mid;
    while(a<b)
        if(cmp(k,len_min[mid=(a+b)>>1])) 
            a=mid+1;
        else b=mid;
    return a;
}
int LIS()
{
    int a=0,b=0,k;
    for(int i=0;i<n;i++)
    { 
        if(len_min[k=binary_search(a,b-1,num[i])]>=num[i]) len_min[k]=num[i];
        else len_min[b++]=num[i];
    }
    return b;
}