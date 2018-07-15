// bfs + dfs check
#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

int dir[][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1},
                {-1, 0}, {0, -1}, {1, 0}, {0, 1}};  //同时记录反方向 i==反(i+2)
bool map[10][10][5];  // map[][][]三维数组，记录箱子(x,y)坐标和方向
int a[10][10], b[10][10];  // a存图，b副本
int x1, y1, x2, y2, tx, ty, px, py, ax, ay;
int N, M;

struct node {
    int x, y, px, py, step;  //箱子的坐标(x,y)、人的坐标(px,py)、步数
    node() {}
    node(int x, int y, int px, int py, int step)
        : x(x), y(y), px(px), py(py), step(step) {}
};

bool dfs(int x, int y)  // dfs判断人是否能够到达箱子的后面
{
    if (x == tx && y == ty) return true;                   //到达箱子后面
    if (x < 0 || x >= N || y < 0 || y >= M) return false;  //越界的返回false
    if (x == ax && y == ay) return false;  //该点是箱子挡住路了
    if (b[x][y] == 1) return false;        //该点是墙壁挡住路了
    b[x][y] = 1;                           //走过的标记不能再走
    return (dfs(x + 1, y) || dfs(x - 1, y) || dfs(x, y + 1) ||
            dfs(x, y - 1));  //深搜
}

void bfs() {
    bool flag = false;
    node n(x1, y1, px, py, 0), m;
    queue<node> Q;
    Q.push(n);
    while (!Q.empty()) {
        m = Q.front();
        Q.pop();
        if (m.x == x2 && m.y == y2) {
            flag = true;
            break;
        }
        for (int i = 0; i < 4; i++) {
            n.x = m.x + dir[i][0];  //后来箱子的位置
            n.y = m.y + dir[i][1];
            // i+2 箱子的反方向
            tx = m.x + dir[i + 2][0];  //后来人的位置
            ty = m.y + dir[i + 2][1];

            ax = m.x;
            ay = m.y;  //原来箱子的位置

            n.px = m.px;
            n.py = m.py;  //原来人的位置
            n.step = m.step + 1;
            if (n.x >= 0 && n.x < N && n.y >= 0 && n.y < M &&
                !map[n.x][n.y][i] && a[n.x][n.y] != 1)  //箱子前方没问题
            {
                //初始化b[][]
                for (int ii = 0; ii < N; ii++)
                    for (int jj = 0; jj < M; jj++) b[ii][jj] = a[ii][jj];

                if (tx >= 0 && tx < N && ty >= 0 && ty < M && a[tx][ty] != 1 &&
                    dfs(n.px, n.py))  //人能到达箱子的后方
                {
                    //则箱子能推倒该点(n.px,n.py)
                    n.px = tx;
                    n.py = ty;
                    map[n.x][n.y][i] = true;  //标记该点和来的这个i方向
                    Q.push(n);
                }
            }
        }
    }
    if (flag)
        printf("%d\n", m.step);
    else
        printf("-1\n");
}
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &N, &M);
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) {
                scanf("%d", &a[i][j]);
                b[i][j] = a[i][j];
                if (a[i][j] == 2) x1 = i, y1 = j;
                if (a[i][j] == 3) x2 = i, y2 = j;
                if (a[i][j] == 4) px = i, py = j;
                for (int k = 0; k < 4; k++) map[i][j][k] = false;
            }
        bfs();
    }
    return 0;
}
