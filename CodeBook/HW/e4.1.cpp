#include <bits/stdtr1c++.h>
#include "feature.h"

using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = static_cast<const int>(1e3 + 7);
int d[maxn];
int g[maxn][maxn];
bool done[maxn];
int n, m, st, ed;

void Dijkstra() {
    memset(done, 0, sizeof(done));

    for (int i = 0; i < n; i++) d[i] = (i == st ? 0 : INF);
    for (int i = 0; i < n; i++) {
        int x, m = INF;
        for (int y = 0; y < n; y++) if (!done[y] && d[y] <= m) m = d[x = y];
        done[x] = 1;
        for (int y = 0; y < n; y++) d[y] = min(d[y], d[x] + g[x][y]);
    }
}

int main() {
    while (scanf("%d %d %d %d", &n, &m, &st, &ed) != EOF) {
        memset(g, INF, sizeof(g));
        while (m--) {
            int u, v, dis;
            scanf("%d %d %d", &u, &v, &dis);
            g[u][v] = dis;
        }
        Dijkstra();
        printf("%d\n", d[ed]);
    }
}