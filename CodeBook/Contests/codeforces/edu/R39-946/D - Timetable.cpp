#include <bits/stdc++.h>

#define cmin(a, b) a=min(a,b)
#define cmax(a, b) b=max(a,b)
using namespace std;
const int MAXN = 555;
const int INF = 0x3f3f3f3f;
char a[MAXN][MAXN];
int dp[MAXN][MAXN];
int mn[MAXN][MAXN];
int N, M, K;
// 01001
// 10110
// ans = 5

// 预处理分组背包
// dp[i][j] 前i天, 跳过j个最小时间
// mn[i][j] 第i天, 跳过j个最小时间
// dp[i][j]=cmin(dp[i-1][j-c]+mn[i][c]) c:0~k
vector<int> v[MAXN];

int main() {
    scanf("%d%d%d", &N, &M, &K);
    int cnt = 1;
    for (int i = 1; i <= N; i++) scanf("%s", a[i]);

    for (int i = 1; i <= N; i++)
        for (int j = 0; j < M; j++)
            if (a[i][j] == '1') v[i].push_back(j); //i天上课的时间

    for (int i = 1; i <= N; i++) {
        auto len = static_cast<int>(v[i].size());
        int mi = min(len, K);

        for (int j = 0; j <= mi; j++) {//逃课数

            int rest = len - j;
            if (!rest) { //这天不用上课
                mn[i][j] = 0;
                continue;
            }

            int Mi = INF;
            for (int k = 0; k < len; k++) {
                int et = k + rest - 1;
                if (et >= len) break;
                cmin(Mi, v[i][et] - v[i][k] + 1);
            }
            mn[i][j] = Mi;
        }
    }
    // cmin(dp[i][j], dp[i-1][j-c]+mn[i][c]) c:0~k
    for (int i = 1; i <= N; i++)
        for (int k = 0; k <= K; k++) {
            dp[i][k] = INF;
            for (int c = 0; c <= k; c++)
                cmin(dp[i][k], dp[i - 1][k - c] + mn[i][c]);
        }
    return !printf("%d\n", dp[N][K]);
}