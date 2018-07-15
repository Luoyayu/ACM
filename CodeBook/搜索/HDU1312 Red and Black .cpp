#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 1005;
char map[maxn][maxn];
int vis[maxn][maxn];
int dir[4][2] = {-1, 0, 0, 1, 0, -1, 1, 0};
int n, m, sx, sy, cnt;
struct node {
    int x, y;
};
int check(node &a) {
    if (map[a.x][a.y] == '#' || a.x < 0 || a.x >= n || a.y < 0 || a.y >= m ||
        vis[a.x][a.y])
        return 0;
    return 1;
}
void bfs() {
    cnt = 1;
    node st, nx;
    queue<node> q;
    st.x = sx, st.y = sy;
    vis[sx][sy] = 1;
    q.push(st);
    while (!q.empty()) {
        st = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            nx = st;
            nx.x += dir[i][0], nx.y += dir[i][1];
            if (check(nx)) {
                vis[nx.x][nx.y] = 1;
                q.push(nx);
                cnt++;
            }
        }
    }
}
int main() {
    while (scanf("%d%d", &m, &n) != EOF && (n || m)) {
        memset(map, 0, sizeof map);
        memset(vis, 0, sizeof vis);
        for (int i = 0; i < n; i++) {
            getchar();
            for (int j = 0; j < m; j++) {
                scanf("%c", &map[i][j]);
                if (map[i][j] == '@') sx = i, sy = j;
            }
        }
        bfs();
        printf("%d\n", cnt);
    }
    return 0;
}