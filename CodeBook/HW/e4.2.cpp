#include <bits/stdc++.h>
#include "feature.h"
// 实现单源最短路经的迪杰斯特拉算法（Dijkstra），要求：分别采用数组、最小堆实现优先级队列

using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 4000 + 10;
struct Edge {
    int from, to, dist;
};

struct HeapNode {
    int d, u;

    bool operator<(const HeapNode &rhs) const {
        return d > rhs.d;
    }
};

struct Dijkstra {
    int n, m;
    vector<Edge> edges;
    vector<int> G[maxn];
    bool done[maxn];    // 是否已永久标号
    int d[maxn];        // s到各个点的距离
    int p[maxn];        // 最短路中的上一条弧

    void init(int n) {
        this->n = n;
        for (int i = 0; i < n; i++) G[i].clear();
        edges.clear();
    }

    void AddEdge(int from, int to, int dist) {
        edges.push_back((Edge) {from, to, dist});
        m = static_cast<int>(edges.size());
        G[from].push_back(m - 1);
    }

    void dijkstra(int s) {
        priority_queue<HeapNode> Q;
        for (int i = 0; i < n; i++) d[i] = INF;
        d[s] = 0;
        memset(done, 0, sizeof(done));
        Q.push((HeapNode) {0, s});

        while (!Q.empty()) {
            HeapNode x = Q.top();
            Q.pop();
            int u = x.u;
            if (done[u]) continue;
            done[u] = true;
            for (int i = 0; i < G[u].size(); i++) {
                Edge &e = edges[G[u][i]];
                if (d[e.to] > d[u] + e.dist) {
                    d[e.to] = d[u] + e.dist;
                    p[e.to] = G[u][i];
                    Q.push((HeapNode) {d[e.to], e.to});
                }
            }
        }
    }
} solver;

int main() {
    int n, m;
    int st, ed;
    scanf("%d %d %d %d", &n, &m, &st, &ed);
    solver.init(n);
    for (int i = 0; i < m; i++) {
        int u, v, dis;
        scanf("%d %d %d", &u, &v, &dis);
        solver.AddEdge(u, v, dis);
    }
    solver.dijkstra(st);
    print("%d\n", solver.d[ed]);
}

/*
 *
6 8 2 5
0 2 1
0 4 2
0 5 3
1 4 4
1 5 5
2 3 6
2 4 7
4 5 2
 -> and=9
 */