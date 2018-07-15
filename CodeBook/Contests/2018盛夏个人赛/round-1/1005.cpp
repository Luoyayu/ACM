#include <bits/stdc++.h>

using namespace std;
int n, m;
char g[222][222];
int vis[222][222];

int dirx[] = {-1, 0, 0, 1};
int diry[] = {0, 1, -1, 0};
struct node {
    int x, y, step;
};

int check(int x, int y) {  // (x, y)
    int flag1 = 1, flag2 = 1, flag3 = 1, flag4 = 1;
    // 上
    for (int i = 1; i <= x - 1; i++) {
        if (g[x - i][y] == 'x') {
            flag1 = 1;
            break;
        }
        if (g[x - i][y] == 'o') {
            flag1 = 0;
            break;
        }
    }
    // 下
    for (int i = 1; i <= n - x; i++) {
        if (g[x + i][y] == 'x') {
            flag2 = 1;
            break;
        }
        if (g[x + i][y] == 'o') {
            flag2 = 0;
            break;
        }
    }
    // 左
    for (int i = 1; i <= y - 1; i++) {
        if (g[x][y - i] == 'x') {
            flag3 = 1;
            break;
        }
        if (g[x][y - i] == 'o') {
            flag3 = 0;
            break;
        }
    }
    // 右
    for (int i = 1; i <= m - y; i++) {
        if (g[x][y + i] == 'x') {
            flag4 = 1;
            break;
        }
        if (g[x][y + i] == 'o') {
            flag4 = 0;
            break;
        }
    }
    if (flag1 && flag2 && flag3 && flag4) return 1;
    return 0;
}

int bfs(int sx, int sy) {
    memset(vis, 0, sizeof(vis));
    queue<node> q;
    q.push(node{sx, sy, 0});
    vis[sx][sy] = 1;
    if (g[sx][sy] == 'o' || check(sx, sy) == 0) return -1;
    while (!q.empty()) {
        node cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = dirx[i] + cur.x;
            int ny = diry[i] + cur.y;
            if (nx == 0 || nx == n + 1 || ny == 0 || ny == m + 1)
                return cur.step + 1;
            if (vis[nx][ny] == 0 && g[nx][ny] == '.' && check(nx, ny)) {
                vis[nx][ny] = 1;
                q.push(node{nx, ny, cur.step + 1});
            }
        }
    }
    return -1;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        getchar();
        int sx, sy;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                scanf("%c", &g[i][j]);
                if (g[i][j] == '@') sx = i, sy = j;
            }
            getchar();
        }

        int ans = bfs(sx, sy);
        if (ans == -1)
            printf("no zuo no die!\n");
        else
            printf("%d\n", ans);
    }
}