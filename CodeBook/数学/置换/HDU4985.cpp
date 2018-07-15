#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 7;
int a[maxn];
int vis[maxn];
vector<int> v[maxn];
int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            vis[i] = 0;
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            int st = i;
            if (vis[st]) continue;
            v[cnt].push_back(st);
            int nxt = a[i];
            vis[st] = 1;
            printf("st: %d; nxt: %d\n", st, nxt);
            while (1) {
                if (vis[nxt] == 0) {
                    vis[nxt] = 1;
                    if (nxt == st) {
                        break;
                        cnt++;
                    }
                    v[cnt].push_back(nxt);
                    nxt = a[nxt];
                    printf("nxt: %d\n", nxt);
                }
            }
        }
        for (int i = 0; i < cnt; i++) {
            printf("( ");
            for (auto x : v[i]) printf(" %d", x);
            printf(")");
        }
        printf("\n");
    }
}