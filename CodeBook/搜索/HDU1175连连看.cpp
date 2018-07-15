#include <bits/stdc++.h>
using namespace std;
int map[1050][1050];
int vis[1050][1050];
int n, m;
struct Node {
    int x, y, dir, times;  // dir表示方向 ，times表示转弯的次数
} st, en;
queue<Node> q;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
bool ismap(int x, int y) {
    if (x < 1 || y < 1 || x > n || y > m) return false;
    return true;
}
void BFS() {
    memset(vis, 0, sizeof(vis));
    while (!q.empty()) q.pop();
    vis[st.x][st.y] = 1;
    q.push(st);
    bool tmp = false;
    while (!q.empty()) {
        Node a = q.front();
        q.pop();
        if (a.x == en.x && a.y == en.y) {
            tmp = true;
            break;
        }
        for (int i = 0; i < 4; i++) {
            Node b;
            b.x = a.x + dx[i];
            b.y = a.y + dy[i];
            b.dir = i;
            b.times = a.times;
            if (!(a.dir == -1 || a.dir + b.dir == 3 ||
                  a.dir == b.dir))  // a.dir+b.dir==3表示转180度的弯
                b.times = a.times + 1;
            if (!ismap(b.x, b.y)) continue;
            if (vis[b.x][b.y]) continue;
            if (map[b.x][b.y] && !(b.x == en.x && b.y == en.y))
                continue;  //很重要，如果不是空格子并且不是终点
            if (b.times > 2) continue;
            vis[b.x][b.y] = 1;
            q.push(b);
        }
    }
    if (tmp)
        puts("YES");
    else
        puts("NO");
}
int main() {
    while (scanf("%d%d", &n, &m) && n && m) {
        int T;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) scanf("%d", &map[i][j]);

        scanf("%d", &T);
        while (T--) {
            scanf("%d%d%d%d", &st.x, &st.y, &en.x, &en.y);
            st.times = 0;
            st.dir = -1;
            if (map[st.x][st.y] != map[en.x][en.y])
                puts("NO");
            else if (map[st.x][st.y] == 0 || map[en.x][en.y] == 0)
                puts("NO");
            else
                BFS();
        }
    }
    return 0;
}