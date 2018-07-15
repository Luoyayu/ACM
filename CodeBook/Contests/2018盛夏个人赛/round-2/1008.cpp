#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = static_cast<const int>(1e6 + 7);

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        char s[222];
        int n;
        scanf("%d", &n);
        int ans = 0;
        while (n--) {
            scanf("%s", s);
            ans += strlen(s);
        }
        printf("%d\n", ans);
    }
}