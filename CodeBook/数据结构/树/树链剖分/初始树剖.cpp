嗯该学树链剖分了(轻重链剖分)
TODO : 长链剖分 树链剖分解决的问题;
复杂 O(logn) 对于一颗无根树，每条边有边权，实现以下操作：
    1.查询u到v的路径上边权之和 2.查询u到v的路径上边权最大值 3.修改u到v上的路径每条边的边权 ····
    将无根树转换为有根树 记录每个节点x的信息有：
    1.x.father 2.x.children(x的所有孩子集合)3.x.size(
        以x为根的树的规模)4.x.depth(x在书中的深度,
                                    到root的距离 + 1)4.x.next = u : u∈x.children
    ,
                                                   u.size最大 成为重儿子
                                                   与重儿子相连的边成为重边,
                                                   其余为轻边

    一个无向无圈图转换成有根树后经过剖分形成

//树剖性质1) 对于轻边(u, v) size(v) <=size(u/2)
// 2) 从root 到某一点的路径上 不超过logn 条轻边和 不超过logn条重边
#include <bits/stdc++.h>
    using namespace std;
const int maxn = int(1e6 + 7);

int edge_tot;
int head[maxn];
// vector<int> G[maxn];//不含边权
struct Edge {
    int to, next, w;
} edge[maxn << 1];
void addedge(int u, int v, int w = 0) {
    edge[edge_tot].to = v;
    edge[edge_tot].next = head[u];
    edge[edge_tot].w = w;
    head[u] = edge_tot++;
}

int sz[maxn];   // sz[u] 以u为根的子树的size
int dep[maxn];  // dep[u] u结点的深度 u到root的距离+1
int fa[maxn];   // fa[u] u的父亲
int son[maxn];  // son[u] u 的重儿子
int id[maxn];   //剖分后的边在新的数据结构中的位置
int fid[maxn];  //与id含义相反
int Top[maxn];  // u所在树链起点 u,v在同一树链中当且仅当Top[u]==Top[v]
int cnt;        //已编号数量

void dfs1(int u, int pre, int d)  //建有根树 求出sz[],depth[],fa[],son[]
{
    dep[u] = d;
    fa[u] = pre;
    sz[u] = 1;
    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].to;
        // int w = edge[i].w;
        if (v != pre) {
            dfs1(v, u, d + 1);
            sz[u] += sz[v];
            if (son[u] == -1 || sz[v] > sz[son[u]]) son[u] = v;
        }
    }
}

void dfs2(int u, int sp)  //剖分有根树 求出id[], Top[]
{
    Top[u] = sp;  //根节点是第一条链
    id[u] = cnt++;
    fid[id[u]] = u;
    if (son[u] == -1) return;  //没有重儿子推出分支
    dfs2(son[u], sp);
    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].to;
        int w = edge[i].w;
        if (v != son[u] && v != fa[u]) dfs2(v, v);  //其他点的top标号为自身
    }
}

int query(int u, int v)  //假设要查询u到v的路径上的权值之和
{}
void init() {
    edge_tot = cnt = 0;
    memset(head, -1, sizeof(head));
    memset(son, -1, sizeof(son));
}
int main() {}
