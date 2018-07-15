
#include <cmath>
#include <cstdio>
using namespace std;
inline double F(double x) {
    return 8 * pow(x, 4.0) + 7 * pow(x, 3.0) + 2 * pow(x, 2.0) + 3 * x + 6;
}
int main() {
    int t;
    scanf("%d", &t);
    double MAX = F(100.0);
    double MIN = F(0.0);
    while (t--) {
        double y;
        scanf("%lf", &y);
        if (y >= MIN && y <= MAX) {
            double l = 0.0, r = 100.0, M;
            while (r - l > 1e-7) {
                M = (r + l) / 2;
                double ans = F(M);
                if (ans < y)
                    l = M;
                else
                    r = M;
            }
            printf("%.4lf\n", (l + r) / 2);
        } else
            printf("No solution!\n");
    }
    return 0;
}
