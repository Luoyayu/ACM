#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:102400000,102400000")
typedef long long ll;
int head[M],vis[M],f[M],siz[M],id[M],n,ecnt = 1;
ll ansl,ansr;
int N,root;
struct edge {
    int to, next;
}e[N * 4];
ll mp[M],inv[M],v[M],K,dir[M];
void add(int u, int v) {
    e[ecnt].next = head[u];
    e[ecnt].to = v;
    head[u] = ecnt++;
}

void getroot(int u,int fa) {
    f[u] = 0;
    siz[u] = 1;
    for (int i = head[u]; i; i = e[i].next) {
        int to = e[i].to;
        if (vis[to] || to == fa) continue;
        getroot(to, u);
        siz[u] += siz[to];
        f[u] = max(f[u], siz[to]);
    }
    f[u] = max(f[u], N - siz[u]);
    if (f[u] < f[root]) root = u;
}
void dfs(int u,int fa,ll now) {
    dir[++dir[0]] = now * v[u] % mod;
    id[dir[0]] = u;
    for (int i = head[u]; i; i = e[i].next) {
        int to = e[i].to;
        if (vis[to] || to == fa) continue;
        dfs(to, u, now * v[u] % mod);
    }
}
void update(int u,ll x,ll y) {
    ll tmp = mp[inv[x * v[u] % mod] * K % mod];
    if (!tmp) return;
    if (y > tmp) swap(y, tmp);
    if (y < ansl || y == ansl && tmp < ansr) 
        ansl = y, ansr = tmp;
}

void solve(int u) {
    vis[u] = 1;
    mp[1] = u;
    for (int i = head[u]; i; i = e[i].next) {
        int to = e[i].to;
        if (vis[to]) continue;
        dir[0] = 0;
        dfs(to, u, 1LL);
        for (int j = 1; j <= dir[0]; ++j) 
            update(u, dir[j], id[j]);
        for (int j = 1; j <= dir[0]; ++j) 
            if (!mp[dir[j]] || mp[dir[j]] > id[j])
                mp[dir[j]] = id[j];
    }
    mp[1] = 0;
    for (int i = head[u]; i; i = e[i].next) {
        int to = e[i].to;
        if (vis[to]) continue;
        dir[0] = 0;
        dfs(to, u, 1);
        for (int j = 1; j <= dir[0]; ++j) mp[dir[j]] = 0;
    }
    for (int i = head[u]; i; i = e[i].next) {
        int to = e[i].to;
        if (vis[to]) continue;
        root = 0;
        N = siz[to];
        getroot(e[i].to, root);
        solve(root);
    }
}
int main() {
    inv[1] = 1;
    for (int i = 2; i < mod; i++) {
        int a = mod / i, b = mod % i;
        inv[i] = (inv[b] * (-a) % mod + mod) % mod;
    }
    while (~scanf("%d%I64d", &n, &K)) {
        ecnt = 1;
        memset(head, 0, sizeof(head));
        memset(vis, 0, sizeof(vis));
        ansl = ansr = inf;
        for (int i = 1; i <= n; ++i) 
            scanf("%I64d", &v[i]);
        for (int i = 1; i < n; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            add(u, v);add(v, u);
        }
        f[0] = inf;
        N = n;
        root = 0;
        getroot(1, 0);
        solve(root);
        if (ansl == inf) puts("No solution");
        else printf("%lld %lld\n", ansl, ansr);
    }
}