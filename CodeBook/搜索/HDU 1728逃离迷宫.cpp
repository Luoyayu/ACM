#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 105;
int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
int vis[15][4][maxn][maxn];
char map[maxn][maxn];
int x1, y1, y2, x2, n, m, k;
struct node {
    int x, y, z, times;
    friend bool operator<(node a, node b) { return a.times > b.times; }

} st, nt;
int check(node p) {
    if (map[p.x][p.y] == '*' || p.x < 0 || p.x >= n || p.y < 0 || p.y >= m)
        return 1;
    return 0;
}
void bfs() {
    int i;
    priority_queue<node> q;
    st.x = x1, st.y = y1, st.times = 0, st.z = 0;
    q.push(st);
    while (!q.empty()) {
        st = q.top();
        q.pop();
        if (st.x == x2 && st.y == y2)
            if (st.times <= k) {
                printf("yes\n");
                return;
            }
        if (st.times > k) continue;
        for (i = 0; i < 4; i++) {
            nt.x = st.x + dir[i][0];
            nt.y = st.y + dir[i][1];
            if (check(nt)) continue;

            if (st.x == x1 && st.y == y1) {
                nt.z = i;
                nt.times = 0;
            } else {
                if (i != st.z) {
                    nt.z = i;
                    nt.times = st.times + 1;
                } else {
                    nt.z = i;
                    nt.times = st.times;
                }
            }
            if (vis[nt.times][i][nt.x][nt.y]) continue;
            vis[nt.times][i][nt.x][nt.y] = 1;
            q.push(nt);
        }
    }
    printf("no\n");
}
int main() {
    int t, i, j;
    scanf("%d", &t);
    while (t--) {
        memset(vis, 0, sizeof(vis));
        scanf("%d %d", &n, &m);
        for (i = 0; i < n; i++) scanf("%s", map[i]);
        scanf("%d%d%d%d%d", &k, &y1, &x1, &y2, &x2);
        y1--, x1--, x2--, y2--;
        if (x1 == x2 && y1 == y2) {
            printf("yes\n");
            continue;
        }
        bfs();
    }
    return 0;
}