#include <bits/stdc++.h>
//百度之星复赛没写出就当做教训吧 ,总结下数位DP模板吧
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
ll dp[105][11][2];
int digit[105];
char num[105];
ll dfs(int pos, int d, int inc, bool limit, bool lead)
{
    if (pos == -1) return lead;
    if (!limit && lead && dp[pos][d][inc] != -1) return dp[pos][d][inc];
    int up = limit ? digit[pos] : 9;
    ll ans = 0;
    for (int i = (inc && lead ? d : 0); i <= up; i++)
        ans += dfs(pos - 1, i, (i > d && lead) || inc, limit && i == up, lead || i != 0);
    ans %= mod;
    return !limit && lead?dp[pos][d][inc] = ans:ans;
}
int main()
{
    int t;scanf("%d", &t);
    memset(dp, -1, sizeof(dp));
    while (t--)
    {
        scanf("%s", num);
        int len = strlen(num);
        for (int i = 0; i < len; i++)
            digit[len - i - 1] = num[i] - '0';
        printf("%I64d\n", dfs(len - 1, 0, 0, true, false));
    }
    return 0;
}