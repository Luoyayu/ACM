#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define rep(i, s, t) for(int i = s;i <= t;i++)
#define rap(i, s, t) for(int i = s;i >= t;i--)
using namespace std;
int N, M;
int node[10005];
struct Edge
{
    int v, next, l;
}edge[100005];
int visit[10005];
int dis[10005];
int cnt_edge;
int ans;
int dfs(int u, int val)
{
    int sum = 0;
    visit[u] = 1;
    for(int i = node[u];i != -1;i = edge[i].next)
    {
        int v = edge[i].v;
        if(visit[v] == 1)
            sum = max(sum, dis[v] + edge[i].l);
        else
        {
            dfs(v, val + edge[i].l);
            sum = max(sum, dis[v] + edge[i].l);
        }
    }
    ans = max(ans, val + sum);
    dis[u] = sum;
    return sum;
}
void add_edge(int u, int v, int w)
{
    edge[cnt_edge].v = v;
    edge[cnt_edge].l = w;
    edge[cnt_edge].next = node[u];
    node[u] = cnt_edge++;
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &N, &M);
        memset(node, -1, sizeof(node));
        memset(visit, 0, sizeof(visit));
        memset(dis, 0, sizeof(dis));
        cnt_edge = 0;
        rep(i, 1, M){
            int a, b, l;
            scanf("%d%d%d", &a, &b, &l);
            add_edge(a, b, l);
        }
        ans = 0;
        rep(i, 1, N){
            if(visit[i] == 0)
                dfs(i, 0);
        }
        printf("%d\n", ans);
    }
    return 0;
}