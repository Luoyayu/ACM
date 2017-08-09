#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
#define clr(a,b) memset(a,b,sizeof(a))
const int maxn = 1e5+7;
//二分尺取法
//打前缀和sum(i) =Σ[1~i) ai
//都为正数sum满足递增二分处理,枚举起点s O(n)


/* nlogn 做法
int sum[maxn];
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        clr(sum,0);
        int n,S;scanf("%d %d",&n ,&S);
        for(int i=1;i<=n;i++)
        {
            int x;scanf("%d",&x);
            sum[i]+=sum[i-1] + x;
        }

        if(sum[n]<S)
        {
            printf("0\n");
            continue;
        }
        int res = n;
        for(int s = 1; sum[s] + S <= sum[n]; s++)//枚举起点
        {
            int t = lower_bound(sum + s , sum + n , sum[s] + S) - sum;
            res = min(res, t - s);
        }
        printf("%d\n",res);
    }
    return 0;
}


*/
//O(n) 的尺取法
int a[maxn];
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n,S;scanf("%d %d",&n ,&S);
        for(int i=1;i<=n;i++)
           scanf("%d",&a[i]);

        int s = 0, t = 0, sum = 0;
        int res = n + 1;
        while(1)
        {
            while(t<=n && sum < S)
                sum += a[t++];
            if(sum<S) break;//推到尾还不行直接跳出
            res = min(res, t - s );//注意t++
            sum -= a[s++];
        }
        if(res > n)
            res = 0;
        printf("%d\n",res);
    }
    return 0;
}


