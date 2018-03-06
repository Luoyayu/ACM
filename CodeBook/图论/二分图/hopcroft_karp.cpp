//hopcroft_karp算法，复杂度O(sqrt(n)*m)
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int N = 9999;
const int INF = 0x3f3f3f3f;
struct edge
{
    int to, next;
}g[N*N];
int match[N], head[N];
bool used[N];
int p, n;
int nx, ny, cnt, dis; //nx,ny分别是左点集和右点集的点数
int dx[N], dy[N], cx[N], cy[N]; //dx,dy分别维护左点集和右点集的标号
//cx表示左点集中的点匹配的右点集中的点，cy正好相反
void add_edge(int v, int u)
{
    g[cnt].to = u;
    g[cnt].next = head[v];
    head[v] = cnt++;
}
bool bfs() //寻找增广路径集，每次只寻找当前最短的增广路
{
    queue<int> que;
    dis = INF;
    memset(dx, -1, sizeof dx);
    memset(dy, -1, sizeof dy);
    for(int i = 1; i <= nx; i++)
        if(cx[i] == -1) //将未遍历的节点入队，并初始化次节点距离为0
            que.push(i), dx[i] = 0;
    while(! que.empty())
    {
        int v = que.front(); que.pop();
        if(dx[v] > dis) break;
        for(int i = head[v]; i != -1; i = g[i].next)
        {
            int u = g[i].to;
            if(dy[u] == -1)
            {
                dy[u] = dx[v] + 1;
                if(cy[u] == -1) dis = dy[u]; //找到了一条增广路，dis为增广路终点的标号
                else
                    dx[cy[u]] = dy[u] + 1, que.push(cy[u]);
            }
        }
    }
    return dis != INF;
}
int dfs(int v)
{
    for(int i = head[v]; i != -1; i = g[i].next)
    {
        int u = g[i].to;
        if(! used[u] && dy[u] == dx[v] + 1) //如果该点没有被遍历过并且距离为上一节点+1
        {
            used[u] = true;
            if(cy[u] != -1 && dy[u] == dis) continue; //u已被匹配且已到所有存在的增广路终点的标号，再递归寻找也必无增广路，直接跳过
            if(cy[u] == -1 || dfs(cy[u]))
            {
                cy[u] = v, cx[v] = u;
                return 1;
            }
        }
    }
    return 0;
}
int hopcroft_karp()
{
    int res = 0;
    memset(cx, -1, sizeof cx);
    memset(cy, -1, sizeof cy);
    while(bfs())
    {
        memset(used, 0, sizeof used);
        for(int i = 1; i <= nx; i++)
            if(cx[i] == -1)
                res += dfs(i);
    }
    return res;
}
int main()
{
    int t, a, b,x;
    while(scanf("%d %d", &n, &x)!=EOF)
    {
        cnt = 0;
        memset(head, -1, sizeof head);
        for(int i=x+1;i<=x+n;i++)
            for(int j=1;j<=n;j++)
                if(j%i==0)
                    add_edge(i,j),printf("%d %d\n",i,j);
        /*for(int i = 1; i <= p; i++)
        {
            scanf("%d",&a);scanf("%d",&b);
            add_edge(a, b);
        }*/
        nx = ny = n;
        if(hopcroft_karp() == n) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
