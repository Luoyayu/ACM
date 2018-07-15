#include <bits/stdc++.h>
//题意：给出一棵树每个节点有一个数字对应的颜色ci,定义两点之间路径长度为出现的不同颜色节点的数目
//求树上 n(n-1)/2个边的长度
//正面算每个点对每条边的贡献不容易，考虑对于每个点没有参与的路径，转换答案为(路径总数)*(颜色总数)-未贡献
//对于一种颜色cx,只要求其未参与贡献的边的条数
//问题转换成求不含颜色cx的联通块的总size 未参与贡献size*(size-1)/2
//对于颜色为x的节点v,求不含颜色x的size算到子节点的最高不含x的子树,未贡献值Vsize-maxSonsize
using namespace std;
const int maxn = 200007;
typedef long long ll;
int cnt;
vector<int> tr[maxn];
void addedge2(int u, int v) {
    tr[u].push_back(v);
    tr[v].push_back(u);
}
ll c[maxn], sum[maxn], sz[maxn];
bool vis[maxn];
ll ans;
void init() {
    ans = cnt = 0;
    memset(vis, 0, sizeof(vis));
    memset(sum, 0, sizeof(sum));
}
ll dfs(int u, int pa) {
    sz[u] = 1;
    ll all_son = 0;
    int CNT = tr[u].size();
    for (int i = 0; i < CNT; i++) {
        int v = tr[u][i];
        if (v == pa) continue;
        ll last = sum[c[u]];
        sz[u] += dfs(v, u);
        ll add = sum[c[u]] - last;
        ans += (sz[v] - add) * (sz[v] - add - 1LL) / 2;
        all_son += sz[v] - add;
    }
    sum[c[u]] += all_son + 1;
    return sz[u];
}
int main() {
    int n;
    int kase = 1;
    while (scanf("%d", &n) != EOF) {
        init();
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &c[i]);
            if (vis[c[i]] == 0) cnt++;
            vis[c[i]] = 1;
            tr[i].clear();
        }

        for (int i = 1; i < n; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            addedge2(x, y);
        }
        printf("Case #%d: ", kase++);
        if (cnt == 1) {
            printf("%lld\n", 1LL * n * (n - 1LL) / 2);
            continue;
        }
        dfs(1, -1);
        for (int i = 1; i <= n; i++) {
            if (vis[i] == 0) continue;
            ans += (n - sum[i]) * (n - sum[i] - 1LL) / 2;
        }
        printf("%lld\n", (long long)n * (n - 1LL) / 2 * cnt - ans);
    }
    return 0;
}
