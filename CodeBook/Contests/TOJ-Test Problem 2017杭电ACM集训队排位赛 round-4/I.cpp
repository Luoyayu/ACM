#include<bits/stdc++.h>
// sb了 忘了划掉a数组 T了2次
//求在数组中 0<=i<=j<=n-1 的max(aj-ai)
//既然前后取差最大那么可以前后做差得出的差序列取一个最大子序列即是答案
using namespace std;
const int maxn = 1e7;
int diff[maxn];//记录差值
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n;scanf("%d",&n);
        scanf("%d",&diff[0]);
        int sum = 0,maxsum = 0;
        for(int i=1;i<n;i++)
        {
            scanf("%d",&diff[i]);
            diff[i-1]=diff[i]-diff[i-1];
            sum+=diff[i-1];
            if(sum>maxsum) maxsum = sum;
            if(sum<0) sum=0;
        }
        printf("%d\n",maxsum);
    }
    return 0;
}
