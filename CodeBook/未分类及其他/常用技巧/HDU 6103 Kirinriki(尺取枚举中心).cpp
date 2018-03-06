#include <bits/stdc++.h>
#ifdef local
#include "ACM.h"
// 题意：定义长度均为n的字符串的dis为 $latex \sum_{i=0}^{n-1} |A_i - B_{n-i-1}|$
// 要求：在一个字符串中找到不重叠的子串的最长长度，且他们的dis小于等于m;
// 枚举中心点
#endif
using namespace std;
const int maxn = 5005;
char str[maxn];
int ans;
void solve(int len, int lim) {
    for (int i = 2; i <= len; i++)//遍历右端点, 取等号便可处理奇偶中心
    {
        int mid = i / 2;
        int s = 0, t = 0;
        int sum = 0;
        for (int j = 0; j < mid; j++) //遍历左端点
        {
            sum += abs(str[j] - str[i - j - 1]);
            if (sum <= lim) {
                t++;
                ans = max(ans, t);
            } else {
                t--;
                sum -= abs(str[j] - str[i - j - 1]); // 还原状态
                sum -= abs(str[s] - str[i - s - 1]);
                s++;// 移左端点
                j--;
            }
        }
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        ans = 0;
        int m;scanf("%d %s", &m, str);
        int len = strlen(str);
        solve(len, m);
        strrev(str);
        solve(len, m);
        printf("%d\n",ans);
    }
    return 0;
}
