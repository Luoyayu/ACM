#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 1e7 + 50;
ll a[maxn];
int T, n, m, k, p, q, r, mod;
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d%d%d%d%d", &n, &m, &k, &p, &q, &r, &mod);
        for (int i = 1; i <= k; i++) scanf("%lld", &a[i]);
        for (int i = k + 1; i <= n; i++)
            a[i] = (1ll * p * a[i - 1] % mod + 1ll * q * i % mod + r) % mod;

        deque<int> Q;
        ll ra = 0, rb = 0;
        Q.push_back(n - m + 1);
        for (int i = n - m + 2; i <= n; i++)
            if (a[Q.back()] < a[i]) Q.push_back(i);

        ra = a[Q.back()] ^ (n - m + 1);
        rb = Q.size() ^ (n - m + 1);
        for (int i = n - m, j = n - 1; i >= 1; i--, j--) {
            if (Q.back() == j + 1) Q.pop_back();
            while (!Q.empty() && a[Q.front()] <= a[i]) Q.pop_front();
            Q.push_front(i);
            ra += a[Q.back()] ^ i;
            rb += Q.size() ^ i;
        }
        printf("%lld %lld\n", ra, rb);
    }
    return 0;
}