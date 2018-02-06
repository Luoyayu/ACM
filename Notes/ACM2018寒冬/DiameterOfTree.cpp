#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
struct node {
	int to,next,w;
}e[maxn];
int dis[maxn];
int ecnt,head[maxn];
void addedge2(int u, int v, int w) {
	e[ecnt] = node{u,head[v],w}; head[v] = ecnt ++;
	e[ecnt] = node{v,head[u],w}; head[u] = ecnt ++;
}

void dfs(int u, int fa, int d) {
	for(int i=head[u];~i;i=e[i].next) {
		int v = e[i].to, w = e[i].w;
		if(v!=fa) {
			dis[v] = w + d;
			dfs(v, u, dis[v]);
		}
	}
}

void init() {
	memset(head, -1, sizeof(head));
	memset(dis, 0, sizeof(dis));
	ecnt = 0;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	
	for(int i=0; i<m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		addedge2(u, v, w);
	}
	int st = 1;
	dfs(st, -1, 0);

}
