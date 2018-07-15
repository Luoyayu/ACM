#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = static_cast<const int>(1e6 + 7);

void solve();

void init() {}

int main() {
    int Kase;
    init();
    scanf("%d", &Kase);
    while (Kase--) {
        solve();
    }
}

ll ans[] = {1,      1,      2,      3,      4,      6,      9,      12,
            18,     27,     36,     54,     81,     108,    162,    243,
            324,    486,    729,    972,    1458,   2187,   2916,   4374,
            6561,   8748,   13122,  19683,  26244,  39366,  59049,  78732,
            118098, 177147, 236196, 354294, 531441, 708588, 1062882};

void solve() {
    int n;
    scanf("%d", &n);
    printf("%lld\n", ans[n - 2]);
}