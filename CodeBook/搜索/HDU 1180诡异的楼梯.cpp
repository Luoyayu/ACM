#include <bits/stdc++.h>
using namespace std;
const int N = 50;
char Map[N][N];
bool vis[N][N];
int n, m;
int sx, sy;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
struct node {
    int x, y;
    int step;
    friend bool operator<(const node &a, const node &b) {
        return a.step > b.step;
    }
};

node st;

bool check(int x, int y) {
    if (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && Map[x][y] != '*')
        return true;
    return false;
}

int bfs() {
    char c;
    priority_queue<node> q;
    node st, nx;
    st.x = sx, st.y = sy, st.step = 0, vis[sx][sy] = 1;
    q.push(st);
    while (!q.empty()) {
        st = q.top();
        q.pop();
        for (int i = 0; i < 4; i++) {
            nx = st;
            nx.x += dir[i][0], nx.y += dir[i][1], nx.step++;
            if (check(nx.x, nx.y) &&
                (Map[nx.x][nx.y] == '-' || Map[nx.x][nx.y] == '|')) {
                if (nx.step % 2 == 1) {
                    if (Map[nx.x][nx.y] == '-')
                        c = '|';
                    else if (Map[nx.x][nx.y] == '|')
                        c = '-';
                } else
                    c = Map[nx.x][nx.y];
                nx.x += dir[i][0], nx.y += dir[i][1];
                if ((c == '-' && (dir[i][1] == -1 || dir[i][1] == 1)) ||
                    (c == '|' && (dir[i][0] == -1 || dir[i][0] == 1)))
                    nx.step++;
            }
            if (check(nx.x, nx.y)) {
                if (Map[nx.x][nx.y] == 'T') return nx.step;
                vis[nx.x][nx.y] = 1;
                q.push(nx);
            }
        }
    }
    return -1;
}

int main() {
    while (~scanf("%d %d", &n, &m)) {
        for (int i = 0; i < n; i++) {
            getchar();
            for (int j = 0; j < m; j++) {
                scanf("%c", &Map[i][j]);
                if (Map[i][j] == 'S') sx = i, sy = j;
            }
        }

        memset(vis, 0, sizeof(vis));
        printf("%d\n", bfs());
    }
    return 0;
}