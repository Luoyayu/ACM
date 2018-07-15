#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = static_cast<const int>(1e2 + 7);

void solve();

int main() {
    int Kase;
    scanf("%d", &Kase);
    while (Kase--) {
        solve();
    }
}

int a[maxn];
int vis[maxn];

bool cmp(int x, int y) { return x > y; }

void solve() {
    int n, m;
    scanf("%d %d", &n, &m);
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, a + n, cmp);
    int ans = 0, flag = 0;
    // i j k
    for (int i = 0; i < n; i++) {
        if (vis[i] == 0) {
            flag = 0;
            for (int j = n - 1; j > i + 1 && flag == 0; j--) {
                if (vis[j] == 0) {
                    for (int k = j - 1; k > i; k--) {
                        if (vis[k] == 0 && a[i] * 3 + 2 * a[k] + a[j] >= m) {
                            ans++;
                            vis[i] = vis[j] = vis[k] = flag = 1;
                            break;
                        }
                    }
                }
            }
        }
        if (flag == 0) break;
    }
    printf("%d\n", ans);

}