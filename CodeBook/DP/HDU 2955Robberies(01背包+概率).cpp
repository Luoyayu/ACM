//01背包 被抓率转换成逃脱率dp[i]表示抢到价值为i的钱式的最大逃脱率
//必须安全所以每次都不能不抓！转换成安全率
#include<bits/stdc++.h>
using namespace std;
const int maxn=10005;
double  dp[maxn],possibility[maxn];
int v[maxn];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        double P;
        int n;//sum of banks
        scanf("%lf %d",&P,&n);
        P=1.0-P;//高于此安全
        memset(dp,0,sizeof dp);
        int sum=0;
        dp[0]=1.0;//抢的0$脱逃率1
        for(int i=0;i<n;i++)
        {
            scanf("%d %lf",&v[i],&possibility[i]);
            possibility[i]=1.0-possibility[i];//安全率
            sum+=v[i];//总价值
        }
        for(int i=0;i<n;i++)//遍历银行
            for(int j=sum;j>=v[i];j--)
                dp[j]=max(dp[j],dp[j-v[i]]*possibility[i]);
        for(int i=sum;i>=0;i--)
            if(dp[i]>P)
            {
                printf("%d\n",i);
                break;
            }
    }
    return 0;
}
