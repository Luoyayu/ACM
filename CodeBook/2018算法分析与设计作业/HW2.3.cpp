#include <bits/stdtr1c++.h>
#include "feature.h"

using namespace std;
const int maxn = 1e3 + 7;
int dp[maxn][maxn];  // dp[i][k] = max(dp[j][k-1]*num[j+1][i]) j: k+1 ~ i
int a[maxn][maxn];

char s[1000];

int main() {
    int n, K;
    scanf("%d %d", &n, &K);
    scanf("%s", s + 1);
    for (int i = 1, d = 0; i <= n; i++) {
        d = d * 10 + s[i] - '0';
        a[1][i] = d;
        dp[i][0] = a[1][i];
    }
    int MAX;
    for (int k = 1; k <= K; k++) {
        for (int i = k + 1; i <= n; i++) {
            MAX = 0;
            for (int j = k; j < i; j++) {
                int d = 0;
                for (int u = j + 1; u <= i; u++) d = d * 10 + s[u] - '0';
                a[j + 1][i] = d;
                MAX = max(MAX, dp[j][k - 1] * a[j + 1][i]);
            }
            dp[i][k] = MAX;
        }
    }
    return !printf("%d\n", dp[n][K]);
}
