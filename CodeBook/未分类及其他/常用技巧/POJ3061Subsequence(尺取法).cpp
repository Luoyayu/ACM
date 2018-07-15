#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define clr(a, b) memset(a, b, sizeof(a))
const int maxn = 1e5 + 7;
//二分尺取法
//打前缀和sum(i) =Σ[1~i) ai
//都为正数sum满足递增二分处理,枚举起点s O(n)

/* nlogn 做法
int sum[maxn];
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        clr(sum,0);
        int n,S;scanf("%d %d",&n ,&S);
        for(int i=1;i<=n;i++)
        {
            int x;scanf("%d",&x);
            sum[i]+=sum[i-1] + x;
        }

        if(sum[n]<S)
        {
            printf("0\n");
            continue;
        }
        int res = n;
        for(int s = 1; sum[s] + S <= sum[n]; s++)//枚举起点
        {
            int t = lower_bound(sum + s , sum + n , sum[s] + S) - sum;
            res = min(res, t - s);
        }
        printf("%d\n",res);
    }
    return 0;
}


*/
// O(n) 的尺取法
// 思想：先固定好初始长度，然后左端点向右移动1个单位右端点调整，这样便能取遍序列所有满足的情况
//#include <bits/stdc++.h>
#include <algorithm>
#include <cstdio>
#ifdef Local
#include "ACM.h"
#endif
using namespace std;
const int maxn = int(1e5 + 7);
int a[maxn];
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, ss, tot = 0;
        scanf("%d%d", &n, &ss);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]), tot += a[i];

        if (tot <= ss) {
            printf("%d\n", tot == ss ? n : 0);
            continue;
        }
        a[0] = 0;
        int s = 0, t = 0;
        int sum = 0;
        int res = n + 1;
        while (1) {
            while (t <= n && sum < ss) sum += a[t++];
            // debug(t);
            if (sum < ss) break;    //推到尾部跳出
            res = min(res, t - s);  // t已经加1
            // debug(res);
            sum -= a[s++];
            // debug(sum);
        }
        printf("%d\n", res > n ? 0 : res);
    }
    return 0;
}
