
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
int phi(int n) {
    int ret = n;
    int m = sqrt(n + 0.5);
    for (int i = 2; i <= m; i++) {
        if (n % i == 0) {
            ret = ret / i * (i - 1);
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) ret = ret / n * (n - 1);
    return ret;
}
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        printf("%d\n", phi(n));
    }
    return 0;
}
