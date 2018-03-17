#include <bits/stdc++.h>

using namespace std;
const int maxn = 1001;
const int inf = 0x3f3f3f3f;
int a[maxn];

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int n;
    scanf("%d", &n);
    int tot = 0, sum = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        tot += a[i];
    }
    sort(a + 1, a + n+1, cmp);
    a[n + 1] = 0;
    int ans = -inf;
    for (int i = 0; i <= n + 1; i++) {
        sum += a[i];
        ans = max(sum - (tot - sum), ans);
    }
    printf("%d\n", ans);

}