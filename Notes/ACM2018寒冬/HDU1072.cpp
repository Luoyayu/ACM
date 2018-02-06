#include<bits/stdc++.h>
using namespace std;
const int maxn = 10;
int g[maxn][maxn];
int sx, sy, ex, ey;
int n, m;
int dir[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
struct node {
	int x, y, steps, cnt;
	node(int x, int y, int steps, int cnt):
		x(x), y(y), steps(steps), cnt(cnt){} 
};
bool check(int x, int y) {
	if(x > n || x <= 0 || y > m || y <= 0 || !g[x][y])
		return false;
	return true;
}
int bfs() {
	queue <node> q;
	q.push(node(sx, sy, 0, 6));
	g[sx][sy] = 0; // 走过的路变成wall
	while(!q.empty()) {
		node cur = q.front();
		q.pop();
		for(int i=0; i<4; i++) {
			node nxt = cur;
			nxt.x += dir[i][0];
			nxt.y += dir[i][1];
			if(check(nxt.x, nxt.y)) {
				if(g[nxt.x][nxt.y] == 1) {
					nxt.cnt--;
					if(nxt.cnt >= 1) {
						nxt.steps++;
						q.push(nxt);
					}
				}
				else if(g[nxt.x][nxt.y] == 4) {
					nxt.cnt --;
					if(nxt.cnt >= 1) {
						nxt.steps ++;
						nxt.cnt = 6;
						q.push(nxt);
					}
					g[nxt.x][nxt.y] = 0;//不能重复到一个复位点
				}
				else if(g[nxt.x][nxt.y] == 3 && nxt.cnt >= 2)
					return nxt.steps + 1;
			}
		}	
	}
	return -1; 
}
int main() {
	int T;scanf("%d", &T);
	while(T--) {
		scanf("%d %d" ,&n, &m);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++) {
				scanf("%d", &g[i][j]);
				if(g[i][j] == 2)
					sx = i, sy = j;
			}
		printf("%d\n", bfs());
	}
	return 0;
}
