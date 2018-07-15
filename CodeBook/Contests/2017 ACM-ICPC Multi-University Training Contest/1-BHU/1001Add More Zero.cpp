#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAX_N = 100000 + 10;
int main() {
    int cases = 1;
    double k = log(2) / log(10);
    int m;
    while (~scanf("%d", &m)) {
        int ans = m * k;
        printf("Case #%d: %d\n", cases++, ans);
    }
    return 0;
}