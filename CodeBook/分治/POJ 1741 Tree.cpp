#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = int (1e5 + 7);
const int inf = 0x3f3f3f3f;
struct node{
    int to, next, w;
}e[maxn];
int head[maxn], ecnt;
int n,k;
void addedge(int u, int v, int w) {
    e[ecnt] = node{v, head[u], w};
    head[u] = ecnt++;
}

int vis[maxn];
struct Q_Q {
    int N;
    int subTMaxSize, CenterIdx;
    int sz[maxn];
    void dfs(int u, int fa) {
        sz[u] = 1;
        int res = 0; //此处不是平衡度，应是子树的大小，平衡度一个点为0
        for (int i = head[u]; ~i; i = e[i].next) {
            int v = e[i].to;
            if (v == fa || vis[v]) continue; // 无向图两个都要判
            dfs(v, u);
            sz[u] += sz[v];
            res = max(res, sz[v] - 1);
        }
        res = max(res, N - sz[u]);
        if (res < subTMaxSize)
            subTMaxSize = res, CenterIdx = u;
    }
    int retCenter(int st) {
        subTMaxSize = inf, CenterIdx = 0;
        dfs(st, 0);
        return CenterIdx;
    }
};
Q_Q X_X;
int data[maxn], Len;
int dis[maxn];
int ANS;

void dfs(int u, int fa) {
    data[++Len] = dis[u];
    for (int i = head[u]; ~i; i = e[i].next) {
        int v = e[i].to;
        int w = e[i].w;
        if (v == fa || vis[v]) continue;
        dis[v] = dis[u] + w;
        dfs(v, u);
    }
}

int cal(int u, int now) {
    dis[u] = now; //更改u到虚根的距离
    Len = 0;
    dfs(u, 0);
    sort(data + 1, data + Len + 1);
    int res = 0;
    int l = 1, r = Len;
    while (l < r)
        if (data[r] + data[l] <= k)
            res += r - l++;
        else r--;
    return res;
}

void solve(int u) {
    ANS += cal(u, 0);
    //cal经过根u的路径数，在降维后要考虑选择的两个点都在根一侧
    vis[u] = 1;
    for (int i = head[u]; ~i; i = e[i].next) {
        int v = e[i].to;
        int w = e[i].w;
        if (vis[v]) continue;
        ANS -= cal(v, w); //除掉那些经过u的孩子h为根和v
        X_X.N = X_X.sz[v];
        // printf("Center root : %d\n",X_X.retCenter(v));
        solve(X_X.retCenter(v));
    }
}

void init(){
    ANS = 0;
    ecnt = 0;
    memset(head, -1, sizeof(head));
    memset(vis, 0, sizeof(vis));
}

int main() {
    while (scanf("%d %d", &n, &k) != EOF, n + k) {
        init();
        for (int i = 1; i < n; i++) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            addedge(u, v, w);
            addedge(v, u, w);
        }
        X_X.N = n;
        int st = 1;
        int root = X_X.retCenter(st);
#ifndef ONLINE_JUDGE
        printf("Root = %d\n", root);
#endif
        solve(root);
        printf("%d\n", ANS);
    }
    return 0;
}