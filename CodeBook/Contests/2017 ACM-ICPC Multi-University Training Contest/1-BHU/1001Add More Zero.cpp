#include <bits/stdc++.h>
using namespace std;

int main() {
    int cases = 1;
    double k = log(2) / log(10);
    int m;
    while (~scanf("%d", &m)) {
        int ans = m * k;
        printf("Case #%d: %d\n", cases++, ans);
    }
}