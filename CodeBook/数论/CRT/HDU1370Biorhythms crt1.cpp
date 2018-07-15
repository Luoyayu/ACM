
#include <cstdio>
#include <cstring>
using namespace std;
int a[4], m[4] = {0, 23, 28, 33};
int ex_gcd(int a, int b, int &x, int &y, int gcd = 1) {
    if (b == 0) {
        x = a;
        y = 0;
        return a;
    } else {
        gcd = ex_gcd(b, a % b, y, x);
        y -= x * (a / b);
    }
    return gcd;
}
int CRT(int a[], int m[], int n) {
    int M = 1;
    int ans = 0;
    for (int i = 1; i <= n; i++) M *= m[i];
    for (int i = 1; i <= n; i++) {
        int x, y;
        int Mi = M / m[i];
        ex_gcd(Mi, m[i], x, y);
        ans = (ans + Mi * x * a[i]) % M;
    }
    if (ans < 0) ans += M;
    return ans;
}
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int p, e, i, d;
        int kase = 1;
        scanf("%d%d%d%d", &p, &e, &i, &d);
        if (p + 1 && e + 1 && i + 1 && d + 1) break;
        a[1] = p;
        a[2] = e;
        a[3] = i;
        int ans = CRT(a, m, 3);
        if (ans <= d) ans += 21252;
        printf("Case %d: the next triple peak occurs in ", kase++);
        printf("%d days.\n", ans - d);
    }
    return 0;
}
