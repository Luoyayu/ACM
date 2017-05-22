///数位DP入门题
///查看1~n中有多少个数字中含有49
///dp[i][j]表示的是i位数字并且第i位上的数字为j所不含49的个数
#include<cstdio>
#include<cstring>
using namespace std;
typedef __int64 ll;
ll n,dp[20][10];
void init()
{
    memset(dp,0,sizeof dp);
    dp[0][0]=1;
    for(int i=1;i<20;i++)

        for(int j=0;j<10;j++)///枚举第i位
            for(int k=0;k<10;k++)///枚举第i-1位
                if(!(j==4&&k==9))
                    dp[i][j]+=dp[i-1][k];
}

ll solve(ll n)
{
    int digit[20];//分数
    int len=1;
    ll m=n;
    while(n)
    {
        digit[len++]=n%10;
        n/=10;
    }

    digit[len+1]=0;
    ll ans=0;
    for(int i=len;i>0;i--)
    {
        for(int j=0;j<digit[i];j++)
            if(!digit[i+1]==4&&j==9)
                ans+=dp[i][j];

        if(digit[i]==9 && digit[i+1]==4)
            break;
    }
    return m-ans;
}
int main()
{
    int t;
    init();
    scanf("%d",&t);
    while(t--)
    {
        scanf("%I64d",&n);
        printf("%I64d\n",solve(n+1));
    }
    return 0;
}
