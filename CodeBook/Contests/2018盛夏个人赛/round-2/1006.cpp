#include <bits/stdtr1c++.h>

using namespace std;

double solve(int a, int b, int c, int d) {
    int x1px2 = a - b;
    if (x1px2 >= c + d || x1px2 <= c - d || x1px2 <= d - c || x1px2 < 0)
        return 0;
    double h, x1, x2;
    x1 = (d * d - c * c + x1px2 * x1px2) / 2.0 / x1px2;
    h = sqrt(d * d - x1 * x1);
    return (a + b) * h / 2;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        int aa[] = {a, b, c, d};
        double ans = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    for (int u = 0; u < 4; u++) {
                        if (i == j || i == k || i == u || j == k || j == u ||
                            k == u)
                            continue;
                        ans = max(ans, solve(aa[i], aa[j], aa[k], aa[u]));
                    }
                }
            }
        }
        if (ans == 0)
            printf("IMPOSSIBLE\n");
        else
            printf("%.2f\n", ans);
    }
}