#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e6 + 7;
int x[maxn];
int work[maxn];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        int ans = 0;
        for (int i = 0; i < m; i++) scanf("%d", &x[i]);
        memset(work, 0, sizeof(work));
        // n~m-1个任务
        for (int i = 0, j = 0; i < m; i++, j++) {
            if (j == n) j = 0;
            work[j] = max(work[j], x[i]) + 45;
            // for (int k = 0; k < n; k++)
            //     printf("%d%c", work[k], k == n - 1 ? '\n' : ' ');
        }
        sort(work, work + n);
        printf("%d\n", work[n - 1]);
    }
}