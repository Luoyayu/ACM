
#include<bits/stdc++.h>
///题意有一颗树，每个节点有两个值a,b;再有m个查询，查询一个点的编号u，要求找出u的后代中
///某个节点v,使得v.a>u.a, 且v.b是u所有后代中b最大的那个点
#define lson node << 1
#define rson node << 1 | 1
using namespace std;
const int maxn = 50002;
struct staff      //员工节点
{
    int superior;
    int ability;
    int loyalty;
}People[maxn];

struct node       //邻接表保存树
{
    int to;
    int next;
}D[maxn];

struct subTree    //存储子树的起始编号和终止编号
{
    int st;
    int ed;
};

int N, Q;
int tot, dfs_clock;
int head[maxn];
int ans[maxn];     //存储答案
subTree sub[maxn];   //存储编号为i的员工，其下属的起始编号和终止编号
int SegTree[ maxn << 2 ];   //线段树，存储忠诚度的最大值
int vis[ 1000010 ];      //忠诚度→编号映射
bool cmp( staff a, staff b )
{
    return a.ability > b.ability;
}

void add( int u, int v )    //头插法加点
{
    D[tot].to = v;
    D[tot].next = head[u];
    head[u] = tot++;
}

void DFS( int cur )             //DFS遍历，记录其子树的起始编号和终止编号
{
    sub[cur].st = dfs_clock++;
    for ( int i = head[cur]; i != -1; i = D[i].next )
        DFS( D[i].to );
    sub[cur].ed = dfs_clock;
}

void init()                     //初始化
{
    tot = 1;
    memset( head, -1, sizeof(head) );
    memset( SegTree, -1, sizeof(SegTree) );
    dfs_clock = 1;
}

int query(int node,int begin, int end, int left, int right )   //区间查最值
{
    if ( left <= begin && end <= right )
        return SegTree[node];
    int m = ( begin + end ) >> 1;
    int ret = -1;
    if ( left <= m ) ret = max( ret, query(lson,begin, m, left, right ) );
    if ( right > m )  ret = max( ret, query( rson, m+1, end, left, right ) );
    return ret;
}

void PushUp( int node )
{
    SegTree[node] = max( SegTree[ node << 1 ], SegTree[ node << 1 | 1 ] );
}

void update( int id, int val, int node, int l, int r )   //节点加入线段树
{
    if ( l == id && r == id )
    {
        SegTree[node] = val;
        return;
    }

    int m = ( l + r ) >> 1;
    if ( id <= m ) update( id, val, lson , l, m);
    else update( id, val, rson , m+1, r);

    PushUp( node );
}

int main()
{
    int T;
    scanf( "%d", &T );
    while ( T-- )
    {
        init();

        scanf( "%d%d", &N, &Q );
        for ( int i = 1; i < N; ++i )
        {
            int a, aby, loy;
            scanf( "%d%d%d", &a, &loy, &aby );
            add( a, i );
            People[i].ability = aby;
            People[i].loyalty = loy;
            People[i].superior = a;
            vis[loy] = i;
        }

        DFS( 0 );  //根节点编号为0

        sort( People + 1, People + N, cmp );  //按能力值从大到小排序

        int j;
        for ( int i = 1; i < N; i = j )
        {
            j = i;
            while ( j < N && People[i].ability == People[j].ability )
            {
                int id = vis[ People[j].loyalty ];
                int tp = -1;
                if ( sub[id].st + 1 <= sub[id].ed - 1 )
                    tp = query( 1, 1, dfs_clock - 1,  sub[id].st + 1, sub[id].ed - 1 );
                if ( tp == -1 ) ans[id] = -1;
                else ans[id] = vis[tp];
                ++j;
            }

            j = i;
            while ( j < N && People[i].ability == People[j].ability )
            {
                int id = vis[ People[j].loyalty ];
                update( sub[id].st, People[j].loyalty,  1, 1, dfs_clock - 1 );
                ++j;
            }
        }

        while ( Q-- )
        {
            int a;
            scanf( "%d", &a );
            printf( "%d\n", ans[a] );
        }
    }
    return 0;
}
