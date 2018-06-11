#include <bits/stdtr1c++.h>
#include "feature.h"

using namespace std;
const int maxn = 1e3 + 7;
int dp[maxn][maxn]; // dp[i][k] = max(dp[j][k-1]*num[j+1][i]) j: k+1 ~ i
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
                for (int u = j + 1; u <= i; u++)
                    d = d * 10 + s[u] - '0';
                a[j + 1][i] = d;
                MAX = max(MAX, dp[j][k - 1] * a[j + 1][i]);
            }
            dp[i][k] = MAX;
        }
    }
    return !printf("%d\n", dp[n][K]);
}

//int ar[maxn];
//int dp[maxn][2];
//int N;
//int Num(int b, int e)
//{
//    int i, j;
//    int res = 0;
//    for(i = b; i <= e; i++)
//    {
//        res = res*10+ar[i];
//    }
//    return res;
//}
//int main()
//{
//    int i, j;
//    while(scanf("%d", &N) != EOF)
//    {
//        for(i = 1; i <= N; i++)
//        {
//            scanf("%d", &ar[i]);
//        }
//        dp[1][0] = dp[1][1] = ar[1];
//        for(i = 2; i <= N; i++)
//        {
//            dp[i][1] = max(dp[i-1][1], dp[i-1][0]) * ar[i];
//            for(j = i-1; j >= 1; j--)
//            {
//                dp[i][0] = max(dp[i][0], Num(j, i)*dp[j][1]/ar[j]);
//            }
//        }
//        printf("%d\n", max(dp[N][0], dp[N][1]));
//    }
//    return 0;
//}






















