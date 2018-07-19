#include <bits/stdtr1c++.h>

using namespace std;
const int maxn = 1e5 + 7;
const int mod = 1e9 + 7;
typedef long long ll;
ll dp[2][222];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, x, A;
        scanf("%d %d %d", &n, &A, &x);
        memset(dp, 0, sizeof(dp));
        dp[1][x] = 1;
        for (int i = 2; i <= n; i++) {
            scanf("%d", &x);
            int isOdd = i & 1;
            int isEven = i & 1 ^1;
            for (int j = 0; j < 128; j++) {
                // ^ | +
                // 比较后7位方有效 128d=10000000b op=(+, |, ^) any > 100
                if ((j ^ x) < 128) dp[isOdd][j ^ x] = (dp[isOdd][j ^ x] % mod + dp[isEven][j] % mod) % mod;
                if ((j | x) < 128) dp[isOdd][j | x] = (dp[isOdd][j | x] % mod + dp[isEven][j] % mod) % mod;
                if ((j + x) < 128) dp[isOdd][j + x] = (dp[isOdd][j + x] % mod + dp[isEven][j] % mod) % mod;
            }
            memset(dp[isEven], 0, sizeof(dp[isEven]));

        }
        printf("%lld\n", dp[n & 1][A]);
    }
}