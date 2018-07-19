#include <bits/stdtr1c++.h>

using namespace std;
typedef long long ll;
const int maxn = 6666;
const int inf = 0x3f3f3f3f;
int g[maxn][maxn];
int n;

// exp max under numb max
int superStart, superEnd;

class Dinic {
   public:
    struct point {
        int from, to, cap, flow;

        point(int from, int to, int cap, int flow)
            : from(from), to(to), cap(cap), flow(flow) {}
    };

    vector<point> edges;
    vector<int> G[maxn];
    int mark[maxn], d[maxn], cur[maxn];
    int start, ending;

    void addedge(int from, int to, int cap) {
        edges.emplace_back(from, to, cap, 0);
        edges.emplace_back(to, from, 0, 0);
        int m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }

    int bfs(int start, int ending) {
        memset(mark, 0, sizeof(mark));
        memset(d, -1, sizeof d);
        queue<int> q;
        q.push(start);
        d[start] = 0;
        mark[start] = 1;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i = 0; i < G[u].size(); i++) {
                point e = edges[G[u][i]];
                if (!mark[e.to] && e.cap > e.flow) {
                    mark[e.to] = 1;
                    d[e.to] = d[u] + 1;
                    q.push(e.to);
                }
            }
        }
        return mark[ending];
    }

    int dfs(int x, int a) {
        if (x == ending || !a ) return a;
        int flow = 0, f;
        for (int &i = cur[x]; i < G[x].size(); i++) {
            point &e = edges[G[x][i]];
            if (d[x] + 1 == d[e.to] &&
                (f = dfs(e.to, min(a, e.cap - e.flow))) > 0) {
                e.flow += f;
                edges[G[x][i] ^ 1].flow -= f;
                flow += f, a -= f;
                if (!a) break;
            }
        }
        return flow;
    }

    int dinic() {
        int flow = 0;
        while (bfs(this->start, this->ending)) {
            memset(cur, 0, sizeof cur);
            flow += dfs(start, inf);
        }
        return flow;
    }

    void init(int start, int ending, int N) {
        this->start = start;
        this->ending = ending;
        for (int i = 0; i <= N; i++) G[i].clear();
        edges.clear();
        memset(mark, 0, sizeof mark);
        memset(d, 0, sizeof d);
    }
} __dinic;

int solve(int minVal) {
    __dinic.init(superStart, superEnd, n);

    for (int i = 1; i <= n; i++) {
        __dinic.addedge(superStart, i, 1);
        __dinic.addedge(i + n, superEnd, 1);  // super end=2*n+1
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (g[i][j] >= minVal) __dinic.addedge(i, j + n, 1);

    return __dinic.dinic() == n;  // maxcnts=n
}

int main() {
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) scanf("%d", &g[i][j]);

        superStart = 0;
        superEnd = 2 * n + 1;

        int l = 0, r = 1e9;
        while (l < r - 1) {
            int mid = (l + r) >> 1;
            if (solve(mid) == 0)
                r = mid;  // min <- mid
            else
                l = mid;
        }
        printf("%d\n", l);
    }
}

/*
Problem Description
In GGO, a world dominated by gun and steel, players are fighting for the honor of being the strongest gunmen. Player Shino is a sniper, and her aimed shot kills one monster at a time. Now she is in an n×n map, and there are monsters in some grids. Each monster has an experience. As a master, however, Shino has a strange self-restrain. She would kill at most one monster in a column, and also at most one in a row. Now she wants to know how to get max experience, under the premise of killing as many monsters as possible.
 

Input
The first line contains an integer n（n≤500）
Then n lines follow. In each line there are n integers, and Aij represents the experience of the monster at grid (i,j). If Aij=0, there is no monster at grid (i,j).（Aij≤1e9）
The experience is the minimal experience of all the monster which are killed.
It guaranteed that the maximum of the experience of the monster is not larger than 10^9
 

Output
One integer, the value of max experience.
 

Sample Input
2
2 0
1 8
 

Sample Output
2
*/