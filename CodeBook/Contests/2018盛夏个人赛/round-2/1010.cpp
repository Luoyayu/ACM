#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = static_cast<const int>(1e6 + 7);

int a[maxn];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int sx;
        scanf("%d", &sx);
        for (int i = 1; i < n; i++) {
            int x;
            scanf("%d", &x);
            sx = __gcd(sx, x);
        }
        printf("%d\n", sx * n);
    }
}