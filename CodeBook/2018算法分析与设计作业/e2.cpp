#include <bits/stdtr1c++.h>
#include "feature.h"

using namespace std;

int main() {
    char a[1007], b[1007];
    scanf("%s %s", a + 1, b + 1);
    int k;
    scanf("%d", &k);
    auto lena = static_cast<int>(strlen(a + 1));
    auto lenb = static_cast<int>(strlen(b + 1));
    int dp[lena + 7][lenb + 7];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= lena; i++) dp[i][0] = i * k;
    for (int i = 1; i <= lenb; i++) dp[0][i] = i * k;

    for (int i = 1; i <= lena; i++)
        for (int j = 1; j <= lenb; j++)
            dp[i][j] = min(min(dp[i - 1][j] + k, dp[i][j - 1] + k),
                           dp[i - 1][j - 1] + abs(a[i] - b[j]));
    printf("%d\n", dp[lena][lenb]);
}