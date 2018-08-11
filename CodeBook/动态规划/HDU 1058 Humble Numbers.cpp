// HDU 1058 Humble Numbers.cpp
#include <bits/stdc++.h>
using namespace std;
#define lowbit(x) (x & (-x));
#define lc ((rt) << 1)
#define rc ((rt) << 1 | 1)
#define mid ((l + r) >> 1)
#define clr(a, b) memset(a, b, sizeof(a);
typedef long long ll;
typedef long double ld;
const ld pi = acos(-1);z
const int inf = 0x3f3f3f3f;
const ll llinf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 5888;
// 题意: 因子只属于{2,3,5,7}数称为丑数
// 思路: DP思路
int dp[maxn];
void init() {
    stack<int> stk;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    init();
    int n, kase = 1;
    while (cin >> n, n) {
        int ans = dp[n];
        if (kase == 11)
            printf("The 11th humble number is 12.\n");
        else {
            kase %= 10;
            if (kase == 1)
                printf("The %dst humble number is %d.", kase, ans);
            else if (kase == 2)
                printf("The %dnd humble number is %d.\n", kase, ans);
            else if (kase == 3)
                printf("The %drd humble number is %d.", kase, ans);
            else
                printf("The %dth humble number is %d.", kase, ans);
        }
    }
}
