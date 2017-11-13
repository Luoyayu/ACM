//
// Created by Tongyu on 17.11.13.
//
// Ã‚“‚£∫
#include <bits/stdc++.h>
#ifdef LOCAL
#include "ACM.h"
#endif
using namespace std;
const int maxn = 1e3+7;
vector<int > e[maxn];
bool M[maxn];
int dis[maxn];
void dfs(int u,int fa,int d) {
    int n = e[u].size();
    for (int i = 0; i < n; i++) {
        int v = e[u][i];
        if (v != fa) {
            dis[v] = d + 1;
            dfs(v, u, d + 1);
        }
    }
    return ;
}
int main() {
    int t;scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i <= n; i++)
            e[i].clear(), M[i] = 0, dis[i] = 1;
        for (int i = 1; i <= m; i++) {
            int x;scanf("%d",&x);
            M[x] = 1;
        }
        for (int i = 1; i < n; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            e[u].push_back(v);
            e[v].push_back(u);
        }
        dis[1] = 0;
        dfs(1, -1, 0);int MAX = -1, id = 0;
        for(int i=1;i<=n;i++)
            if(M[i] && dis[i]>MAX)
                MAX = dis[i], id = i;
        dis[id] = 0;
        dfs(id, -1, 0);MAX = -1;
        for(int i=1;i<=n;i++)
            if(M[i] && dis[i]>MAX)
                MAX = dis[i];
        printf("%.2lf\n",floor(1.0*MAX/2));
    }
    return 0;
}