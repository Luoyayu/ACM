#include <bits/stdtr1c++.h>
#include "feature.h"

using namespace std;

const int maxn = 1e6 + 7;
const int inf = 0x3f3f3f3f;
int a[maxn];
int dp[maxn];

int getMaxlen(int n) { //n^2
    int MAXlen = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
            if (a[j] < a[i])
                dp[i] = max(dp[i], dp[j] + 1);
        MAXlen = max(MAXlen, dp[i]);
    }
    return MAXlen;
}

void solve(int n) { // nlogn
    fill(dp, dp + maxn, inf);
    for (int i = 0; i < n; i++)
        *lower_bound(dp, dp + n, a[i]) = a[i];
    printf("%lu\n", lower_bound(dp, dp + n, inf) - dp);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    return !printf("%d\n", getMaxlen(n));
}