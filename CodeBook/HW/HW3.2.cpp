#include <bits/stdtr1c++.h>

using namespace std;

double a[1000];
double x[1000];

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) scanf("%lf", &a[i]);
    sort(a, a + n);
    int mid = (n - 1) >> 1;
    x[mid] = a[n - 1];
    for (int i = mid + 1; i < n; i++) x[i] = a[n - 2 * (i - mid)];
    for (int i = mid - 1; i >= 0; i--) x[i] = a[n - 2 * (mid - i) - 1];

    double sum = 0, exp = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        for (int j = i + 1; j < n; j++)
            exp += x[i] * x[j] * (j - i);
    }
    printf("%lf\n", exp / sum / sum);
}