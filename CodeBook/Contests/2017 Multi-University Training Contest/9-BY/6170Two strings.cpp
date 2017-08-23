#include<bits/stdc++.h>
using namespace std;
const int maxn = 2500 + 55;
bool dp[maxn][maxn]; // dp[i][j] 表示 A的前i个字符可以匹配 B的前j个字符
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        string a,b;cin>>a>>b;
        a = '#' + a;
        b = '#' + b;
        int lena = a.size()-1, lenb = b.size()-1;
        memset(dp, false, sizeof dp);
        dp[0][0] = 1;
        //a* 可变成空串
        if(b[2]=='*') dp[0][2] = 1;
        for(int i=1;i<=lena;i++)
            for(int j=1;j<=lenb;j++)
            {
                if(a[i]==b[j] || b[j]=='.') dp[i][j] = dp[i-1][j-1];

                if(b[j] == '*') // a* 变成空串或者变成a
                {
                    dp[i][j] = dp[i][j-2] || dp[i][j-1];

                    if(a[i]==a[i-1])
                        dp[i][j] = dp[i-1][j] || dp[i-1][j-1];
                }
            }
        if(dp[lena][lenb]) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
