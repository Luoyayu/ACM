// 01背包+滚动数组
// //时间复杂度O(VN) 空间复杂度O(V)
#include <bits/stdtr1c++.h>
#include "feature.h"

const int maxn = 1e6 + 7;
int dp[maxn];
int c[maxn], w[maxn];
using namespace std;

int main() {
    int n, V;
    scanf("%d %d", &n, &V);

    for (int i = 0; i < n; i++)
        scanf("%d %d", &c[i], &w[i]);

    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
        for (int v = V; v >= c[i]; v--)
            dp[v] = max(dp[v], dp[v - c[i]] + w[i]);
    printf("%d\n", dp[V]);
}

/*
5 5

1 2
3 2
4 1
1 4
2 2
 */