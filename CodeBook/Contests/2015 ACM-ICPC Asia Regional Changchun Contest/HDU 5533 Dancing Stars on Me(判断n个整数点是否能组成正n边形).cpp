#include <bits/stdc++.h>
using namespace std;
//题意：给出n个格点，问是否能组成正n多边形
//很明显只能是n=4组成正方形

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        if (n != 4) {
            for (int i = 1; i <= n * 2; i++) {
                int xx;
                scanf("%d", &xx);
            }
            puts("NO");
            continue;
        }
        int x[4], y[4];
        for (int i = 0; i < 4; i++) {
            scanf("%d%d", &x[i], &y[i]);
        }
        sort(x, x + 4);
        sort(y, y + 4);
        if (abs(x[0] - x[3]) == abs(y[0] - y[3]))
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
