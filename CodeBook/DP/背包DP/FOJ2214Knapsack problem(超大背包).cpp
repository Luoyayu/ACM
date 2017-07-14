#include<bits/stdc++.h>
//01背包+超大背包+好题
//但是B,w[i]<=1e9比较大按照常规的时间复杂度为O(n*B) 空间复杂度为O(B)
//注意此题物品的价值之和具有范围 Σvi<=5000
//优化复杂度思想:将价值之和看作是背包的容量在尽可能塞满背包的情况下使得商品的重量之和尽可能的小
//那么在重量之和小于B的条件下价值之和最大就为答案
//常规01背包是给出背包上界,和物品价值,本题是给出价值上界如何取得最大价值,就是以价值和为上界的情况下,重量之和尽可能小
//说白了就是交换价值与背包容量
//优化后的时间复杂度为O(n*Σvi)
using namespace std;
const int inf = 1e9;
const int maxn = 505;
int w[maxn],v[maxn];
int B,n;
int dp[5005];
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int sum=0;
        scanf("%d%d",&n,&B);
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&w[i],&v[i]);
            sum+=v[i];
        }
        fill(dp,dp+sum,inf);
        dp[0]=0;
        for(int i=0;i<n;i++)
            for(int j=sum;j>=v[i];j--)
                dp[j]=min(dp[j],dp[j-v[i]]+w[i]);
        int id;
        for(id=sum;id>=0;id--)
            if(dp[i]<=B)
                break;
        printf("%d\n",id);
    }
    return 0;
}