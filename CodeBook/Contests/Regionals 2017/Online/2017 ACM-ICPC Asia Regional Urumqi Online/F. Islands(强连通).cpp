#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;
vector<int> G[MAXN];
int low[MAXN], dfn[MAXN];
int dfs_clock;
int belong[MAXN], scc_cnt;
vector<int> scc[MAXN];
stack<int> S;
bool Instack[MAXN];
int n, m;
void tarjan(int u, int fa)
{
    int v;
    low[u] = dfn[u] = ++dfs_clock;
    S.push(u);
    Instack[u] = true;
    for(int i = 0; i < G[u].size(); i++)
    {
        v = G[u][i];
        if(!dfn[v])
        {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
        }
        else if(Instack[v])
            low[u] = min(low[u], dfn[v]);
    }
    if(low[u] == dfn[u])
    {
        scc_cnt++;
        scc[scc_cnt].clear();
        while(1)
        {
            v = S.top(); S.pop();
            Instack[v] = false;
            belong[v] = scc_cnt;
            scc[scc_cnt].push_back(v);
            if(v == u) break;
        }
    }
}
void find_cut(int l, int r)
{
    memset(low, 0, sizeof(low));
    memset(dfn, 0, sizeof(dfn));
    memset(belong, 0, sizeof(belong));
    memset(Instack, false, sizeof(Instack));
    dfs_clock = scc_cnt = 0;
    for(int i = l; i <= r; i++)
        if(!dfn[i])
            tarjan(i, -1);
}
int in[MAXN], out[MAXN];
int main()
{
    int tt;
    scanf("%d", &tt);
    while(tt--)
    {
        scanf("%d%d", &n, &m);
        int s, t;
        for(int i = 1; i <= n; i++) G[i].clear();
        while(m--)
            scanf("%d%d", &s, &t), G[s].push_back(t);
        find_cut(1, n);
        for(int i = 1; i <= scc_cnt; i++) in[i] = out[i] = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j < G[i].size(); j++)
            {
                int u = belong[i];
                int v = belong[G[i][j]];
                if(u != v)
                    out[u]++, in[v]++;
            }
        }
        if(scc_cnt == 1)
        {
            printf("0\n");
            continue;
        }
        
        int sum_ind = 0, sum_outd = 0;
        for(int i = 1; i <= scc_cnt; i++)
        {
            if(in[i] == 0) sum_ind++;
            if(out[i] == 0) sum_outd++;
        }
        printf("%d\n", max(sum_ind, sum_outd));
    }
    return 0;
}