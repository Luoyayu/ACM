#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        int ans, num;
        scanf("%d", &n);
        scanf("%d", &ans);
        for (int i = 2; i <= n; i++) {
            scanf("%d", &num);
            ans ^= num;
        }
        int x, y;
        for (int i = 1; i <= n - 1; i++) scanf("%d %d", &x, &y);
        if (ans == 0)
            printf("D\n");
        else
            printf("Q\n");
    }
    return 0;
}