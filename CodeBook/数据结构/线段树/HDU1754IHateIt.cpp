#include <bits/stdc++.h>
// TODO: 单点更新, 区间RMQ
using namespace std;
#define lowbit(x) x&(-x);
#define mid ((l + r) >> 1)
#define lc (rt << 1)
#define rc (rt << 1 | 1)
#define clr(a, b) memset(a, b, sizeof(a);
#define debug(a) cout << #a << " = " << a << endl;
typedef long long ll;
typedef long double ld;
const ld pi = acos(-1);
const int inf = 0x3f3f3f3f;
const ll llinf = 0x3f3f3f3f3f3f3f3f;

int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

const int maxn = 1e6 + 7;

// 线段树复习
//多校练习题HDU4920
struct node {
    int l, r, mx;
} tr[maxn << 2];
int a[maxn];

void build(int rt, int l, int r) {  // 当前根节点标号, 当前节点对应区间[l,r]
    tr[rt] = {l, r, 0};
    if (l == r) {
        cin >> tr[rt].mx;
        return;
    }
    build(lc, l, mid);
    build(rc, mid + 1, r);
    // maintain 需要维护的节点值, 从左右区间返回
    tr[rt].mx = max(tr[lc].mx, tr[rc].mx);  // 递归返回最值
}

int query(int rt, int L,
          int R) {  // 返回[L,R]的最值, [l,r]是当前节点rt对应的区间
    int l = tr[rt].l, r = tr[rt].r;
    if (l >= L && r <= R)
        return tr[rt]
            .mx;  // 当前节点标号为rt的区间在要查询的[L,R]内直接返回这个区间的最值
    int ans = 0;
    if (L <= mid)
        ans =
            query(lc, L, R);  // 出现 L mid R这种情况时, 分别更新左区间和右区间
    if (mid < R) ans = max(ans, query(rc, L, R));
    return ans;
}

// 查询和更新非常类似
void update(int rt, int pos, int val) {  // a[pos]=val;
    int l = tr[rt].l, r = tr[rt].r;
    if (l == r && l == pos) {  // 一直更新到 l==r==pos
        tr[rt].mx = val;
        return;
    }
    if (pos <= mid)
        update(lc, pos, val);  // 查询时如果是 l pos mid 查询左区间
    else
        update(rc, pos, val);  // 如果是mid pos r 查询右区间

    // maintain something 往上维护
    tr[rt].mx = max(tr[lc].mx, tr[rc].mx);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    while (cin >> n >> m) {
        build(1, 1, n);
        while (m--) {
            char op[5];
            int L, R;
            cin >> op >> L >> R;
            if (op[0] == 'U')
                update(1, L, R);
            else
                cout << query(1, L, R) << endl;
        }
    }
}