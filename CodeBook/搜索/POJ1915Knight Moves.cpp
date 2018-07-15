#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
using namespace std;
const int maxn = 305;
int dir[8][2] = {-2, 1, -1, 2, 1, 2, 2, 1, 2, -1, 1, -2, -1, -2, -2, -1};
int vis[maxn][maxn];
int n, sx, sy, ex, ey;
struct node {
    int x, y, step;
};
int bfs() {
    queue<node> q;
    node start, mid, next;
    start.x = sx, start.y = sy, start.step = 0;
    q.push(start);
    while (!q.empty()) {
        mid = q.front();
        q.pop();
        if (mid.x == ex && mid.y == ey) return mid.step;
        for (int i = 0; i < 8; i++) {
            next.x = mid.x + dir[i][0];
            next.y = mid.y + dir[i][1];
            if (next.x == ex && next.y == ey) return mid.step + 1;
            if (next.x >= 0 && next.x < n && next.y >= 0 && next.y < n &&
                !vis[next.x][next.y]) {
                next.step = mid.step + 1;
                vis[next.x][next.y] = true;
                q.push(next);
            }
        }
    }
    return 0;
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
        memset(vis, 0, sizeof vis);
        vis[sx][sy] = true;
        printf("%d\n", bfs());
    }
    return 0;
}