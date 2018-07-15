#include <bits/stdc++.h>
#include "feature.h"

using namespace std;

const int maxn = static_cast<const int>(1e4 + 7);
int a[maxn];

int solve(int n, int k) {
    int ans = 0, tot = 0;
    for (int i = 0; i < k; i++) {
        tot += a[i];
        if (tot > n) ans++, tot = a[i];
    }
    return ans;
}

int main() {
    int n, k;
    input("%d %d", &n, &k);
    int flag = 0;
    for (int i = 0; i <= k; i++)
        input("%d", &a[i]), flag = flag ? flag : a[i] > n;

    if (flag) return !print("No Solution!");
    return !print("%d\n", solve(n, k));
}