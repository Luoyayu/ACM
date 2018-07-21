#include <bits/stdtr1c++.h>

using namespace std;
const int maxn = 1e6 + 7;
typedef long long ll;
ll a[maxn];
ll csum[maxn];
// 题意: 所选课程学分总和不少于V的情况下, 中位数最小
// 思路: 我们针对中位数,
// 假设a[x]是中位数,那么最多能选的学分和是从x位置往两边同步延伸的最长距离, csum
// 有序前缀和
int main() {
    int t;
    scanf("%d", &t);
    for (int kase = 1; kase <= t; kase++) {
        ll n, v;
        scanf("%lld %lld", &n, &v);
        ll sum = 0, ans = -1;
        csum[0] = 0;
        for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; i++) csum[i] = csum[i - 1] + a[i];

        if (csum[n] < v) goto L;

        // for (ll i = 1; i <= n; i++) {// 假设i位置是中位数所在位置
        //     ll len = min(i - 1, n - i); // i-len-1 ~ i    n-len-1 ~n || n-len
        //     ~ len(if n-i!=len) ll suml = csum[i] - csum[i - len - 1];
        //     // 特判奇偶
        //     ll sumr = n - i != len ? csum[n] - csum[n - len - 1] : csum[n] -
        //     csum[n - len];
        //     // 如果n-i!=min,意味着两边长度不一致,
        //     if (suml + sumr >= v) {
        //         ans = a[i];
        //         goto L;
        //     }
        // }
        for (ll i = 1; i <= n; i++) {
            ll minLen = min(i - 1, n - i);
            ll sum = 0, lsum = 0, rsum = 0;
            if (i - 1 == n - i) sum = csum[n]
            }
    L:
        printf("Case #%d: %lld\n", kase, ans);
    }
}

/*
Problem Description
There are N courses to choose from this semester. The credit for the i-th lesson
is ai

Now Feigay hopes to choose some lessons and complete at least V credits, and
these courses have the lowest median credit.

Feigay wants to know what the minimum median is.

The median is a bit different here. If the number of courses selected is even,
the median is the smaller of the two numbers.


Input
The first line of the input gives the number of test cases T . T test cases
follow.

Each test case begins with two integers N and V, as mentioned above.

Next line has an integers array ai of length N, the i-th integer ai indicating
the credit of the i-th lesson.


Output
For each test case, output one line containing `Case #x: y`, where `x` is the
test case number (starting from 1) and `y` is the value of the minimum possible
median or -1 if there is no qualified course selection. T ≤ 20. 1 ≤ N ≤ 10^6. 1
≤ V ≤ 10^9. 0 < ai ≤ 1000.


Sample Input
2
6 15
6 1 13 5 4 1
3 7
3 1 2


Sample Output
Case #1: 1
Case #2: -1
*/