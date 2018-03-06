//TODO:LCA的相关问题的树上特殊解法CF#362(Div.2)C @17.8.6 @http://dwz.cn/6mlS7u
//最小割,建立网络流求解最大权闭合子图问题
//最大权闭合子图指的是一个有向图G(V,E)的点集V,且该点集满足如果u在V中,那么u指向的后继v也在V中,给每个点分配一个权值(可正可负),那么最大的权闭合图就是点权最大的闭合图。
//最大流最小割定理：一个流f'是最大流f''当且仅当他的残余网络不含增广路径。一个割是最小割就是网络中容量最小的割，且这些割边在f''中满流
//最大权闭合子图建图模型：S,T 对于节点i如果点权为正建立从S->i的边边权为 w,如果点权为负建立i->T 边权为-w,对于原图的有向边(u,v) 建边u->v 边权inf。
//对这个网络流求最小割得最优解为ans = 总获益-最小割
//最小割就等于 未选点的获益+选点的花费
//输出最大闭合子图

/*【最大权闭合子图的权值==正权值之和-最小割】的简单证明
 *1）首先最小割一定是简单(s-t)割，因为和s相连的边集本身就可以构成一个割且这个割肯定不是无穷大，而最小割一定小于这个割，因此最小割一定不含无穷的边，故最小割必是简单割（所有割边与s或t相连）
 *其次简单割一定也对应一个闭合子图
 *2）由1)我们可设闭合子图V和s构成S集,和t构成T集。证明闭合子图是简单割：若闭合子图不是简单割，则存在一条边(u,v) u∈S,v属于T且c(u,v)=∞
 *证明简单割是闭合子图：对于子图V中的任意一点u,u∈S，而u的任意一条出边c(u,v)=∞,故v点不在简单割的割集里，因此v不属于T,v∈S，所以V中的所有点均在S中，故S-s是闭合子图
*/

#include <bits/stdc++.h>
const int N = 2500;
const int M = 10500;
typedef __int64 ll;
using namespace std;
const ll inf = 1LL<<62;
#define clr(a,b) memset(a,b,sizeof(a))
struct Edge{
    ll from, to, cap, nex;
}edge[M*10];

ll head[N], tot_edge;
void addedge(ll u, ll v, ll cap)
{
    Edge E = { u, v, cap, head[u]};
    edge[ tot_edge ] = E;
    head[u] = tot_edge ++;

    Edge E2= { v, u, 0,   head[v]};
    edge[ tot_edge ] = E2;
    head[v] = tot_edge ++;
}
ll sign[N], s, t;
bool BFS(ll from, ll to)
{
    clr(sign,-1);
    sign[from] = 0;
    queue<ll>q;
    q.push(from);
    while(!q.empty())
    {
        ll u = q.front(); q.pop();
        for(ll i = head[u]; i!=-1; i = edge[i].nex)
        {
            ll v = edge[i].to;
            if(sign[v]==-1 && edge[i].cap)
            {
                sign[v] = sign[u] + 1, q.push(v);
                if(sign[to] != -1)return true;
            }
        }
    }
    return false;
}
ll Stack[M*4], top, cur[M*4];
ll dinic()
{
    ll ans = 0;
    while(BFS(s, t))
    {
        memcpy(cur, head, sizeof(head));
        ll u = s; top = 0;
        while(1)
        {
            if(u == t)
            {
                ll flow = inf, loc;
                for(ll i = 0; i < top; i++)
                    if(flow > edge[ Stack[i] ].cap)
                    {
                        flow = edge[Stack[i]].cap;
                        loc = i;
                    }
                for(ll i = 0; i < top; i++)
                {
                    edge[ Stack[i] ].cap -= flow;
                    edge[Stack[i]^1].cap += flow;
                }
                ans += flow;
                top = loc;
                u = edge[Stack[top]].from;
            }
            for(ll i = cur[u]; ~i; cur[u] = i = edge[i].nex)
                if(edge[i].cap && (sign[u] + 1 == sign[ edge[i].to ]))break;
            if(~cur[u])
            {
                Stack[top++] = cur[u];
                u = edge[ cur[u] ].to;
            }
            else
            {
                if(!top)break;
                sign[u] = -1;
                u = edge[ Stack[--top] ].from;
            }
        }
    }
    return ans;
}

vector<ll>G[N];
ll cnt;
void init(ll n)
{
    clr(head,-1);
    tot_edge = cnt = 1;
    for(int i = 0; i <= n; i++)G[i].clear();
}
int main()
{
    int T;scanf("%d",&T);
    s = 0, t = 2501;
    for(int kase=1; kase<=T; kase++)
    {
        ll n; scanf("%I64d",&n);
        init(n);
        ll sum = 0;
        for(int i = 1; i <= n; i++)
        {
            ll m;scanf("%I64d",&m);
            G[i].push_back(0x3f3f3f3f);
            for(int j = 1; j <= m; j++)
            {
                int a,b;ll k;
                scanf("%d %d %I64d",&a,&b,&k);
                G[i].push_back(cnt++);
                sum += b;
                addedge(s, G[i][j], b);
                addedge(G[i][j], t, a);
                while(k--)
                {
                    int u,v;scanf("%d %d",&u,&v);
                    addedge(G[i][j], G[u][v], inf);
                }
            }
        }
        printf("Case #%I64d: %I64d\n", kase, sum - dinic());
    }
    return 0;
}