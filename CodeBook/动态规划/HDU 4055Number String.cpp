//排列中每对中递增'I' or 'D'
//dp[i][j] 表示长度为i的签名以j结尾的满足条件的排列数 1~i
//if(a[i-1]=='I')dp[i][j]=dp[i-1][j-1]+dp[i-1][j-2]+...+dp[i-1][1];把j放在结尾就满足题意
//if(a[i-1]=='D')dp[i][j]=dp[i-1][i-1]+dp[i-1][i-2]+...+dp[i-1][j];新的结尾数字大于原排列结尾j,需要安放j，只要把前面的大于等于j的数字+1，就可以顺利放置j
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=10000+223;
const long mod= 1000000007;
char s[maxn];
int dp[maxn][maxn],sum[maxn][maxn];
int main()
{
    while(scanf("%s",s+1)!=EOF)//从1处开始存字符串
    {
        dp[1][1] = sum[1][1] = 1;
        int len=strlen(s+1)+1;
        //printf("%d\n",len);
        for(int i=2;i<=len;i++)
            for(int j=1;j<=i;j++)
            {
                if(s[i-1]=='I')
                    dp[i][j]=sum[i-1][j-1];
                else if(s[i-1]=='D')
                    dp[i][j]=((sum[i-1][i-1]-sum[i-1][j-1])%mod + mod)%mod;//+mod 负数
                else
                    dp[i][j]=sum[i-1][i-1];

                sum[i][j]=(sum[i][j-1]+dp[i][j])%mod;
            }
        printf("%d\n",sum[len][len]);
    }
    return 0;
}
