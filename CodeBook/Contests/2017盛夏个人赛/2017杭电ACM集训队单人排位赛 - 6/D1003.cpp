#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn =  5000 +55;
char s[maxn];
ll a[maxn],dp[maxn];
bool  flag[maxn][maxn];
int len,n;
void pre()
{
    for(int i=1;i<=len;i++)
    {
        flag[i][i] = 1;
        for(int j = 1;;j++)
        {
            if(( j*2 + 1) > n || i-j <1 || i+j > len )  break;
            if(s[i-j] == s[i+j])
            {
                flag[i-j][i+j] = 1;
            }
             else
                break;
         }
     }

    for(int i = 1;i<=len;i++)
    {
        if(s[i] != s[i+1])  continue;
        flag[i][i+1] = 1;
        for(int j = 1;;j++)
        {
            if( i-j < 1|| i+j+1 > len || j*2+2 > n)   break;
            if(s[i-j] == s[i+j+1])
            {
                 flag[i-j][i+j+1] = 1;
            }
            else
                break;
        }
     }
    return ;
}
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        memset(s,0,sizeof s);
        memset(flag,0,sizeof flag);
        memset(dp,0,sizeof dp);
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        scanf("%s",s+1);
        len = strlen(s+1);
        pre();//我还有什么话可说函数都忘写@_@ 白W了3发
        //if [j~i] satify
        //dp[i]=max(dp[i],dp[j-1]+a[dis(i,j)]);
        dp[1] = a[1];
     for(int i=2;i<=len;i++){
         dp[i] = max(dp[i], dp[i-1]+a[1]);
        for(int j = 1;j<i;j++){
             if(flag[j][i]){
                 dp[i] = max(dp[i], dp[j-1]+a[i-j+1]);
             }
         }
        }
     printf("%lld\n", dp[len]);
    }
    return 0;
}
