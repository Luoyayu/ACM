#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 10000000;
typedef long long ll;
struct edge
{
    ll to, next;
}g[10000000];
int match[N], head[N];
bool use[N];
int n,cnt;
void add_edge(ll v, ll u)
{
    g[cnt].to = u, g[cnt].next = head[v], head[v] = cnt++;
}
bool dfs(int v)
{
    for(ll i = head[v]; i != -1; i = g[i].next)
    {
        ll u = g[i].to;
        if(!use[u])
        {
            use[u] = true;
            if(match[u] == -1 || dfs(match[u]))
            {
                match[u] = v;
                return true;
            }
        }
    }
    return false;
}
void hungary()
{
    int res = 0;
    memset(match, -1, sizeof match);
    for(int i = 1; i <= n; i++)
    {
        memset(use, 0, sizeof use);
        if(dfs(i)) res++;
    }
    if(res == n) printf("YES\n");
    else printf("NO\n");
}
int main()
{
    int x;
    while(scanf("%d %d", &n, &x)!=EOF)
    {
        cnt = 0;
        if(x/n>100)
        {
            printf("YES\n");
            continue;
        }
        memset(head, -1, sizeof head);
        for(ll i=x+1;i<=x+n;i++)
            for(ll j=1;j<=n;j++)
                if(i % j==0)
                    add_edge(i, j), add_edge(j, i);
        hungary();
    }
    return 0;
}


