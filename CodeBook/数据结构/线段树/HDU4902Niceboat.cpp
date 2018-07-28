#include <bits/stdc++.h>
// TODO: 区间更新,单点查询
// Trick: 暴力查询单点输出
using namespace std;
#define lowbit(x) x&(-x);
#define lc ((rt)<<1)
#define rc ((rt)<<1|1)
#define mid  ((l+r)>>1)
#define clr(a, b) memset(a,b,sizeof(a);
#define debug(a) cout<<#a<<" = "<<a<<endl;
#define push_back pb
typedef long long ll;
typedef long double ld;
const ld pi = acos(-1);
const int inf = 0x3f3f3f3f;
const ll llinf = 0x3f3f3f3f3f3f3f3f;
// 题意: 操作一: 区间set
// 操作二: 区间[L,R]中比x大的数变成和x的gcd, 为了实现这种操作我么需要记录区间最大值
// 两个lazy标记
const int maxn = 1e5 + 7;
struct node {
    int l, r;
    int val;
    int setv; // setv是区间set的延迟更新标记
} tr[maxn << 2];

void pushUp(int rt) { // 区间的~val表示左右区间的值相等
    tr[rt].val = (tr[lc].val == tr[rc].val ? tr[lc].val : -1);
}

void pushDown(int rt) {
    int &lazy = tr[rt].setv;
    if (lazy) {
        tr[lc].setv = tr[rc].setv = 1;
        tr[lc].val = tr[rc].val = tr[rt].val;
        lazy = 0;
    }
}

void build(int rt, int l, int r) {
    tr[rt].l = l, tr[rt].r = r;
    tr[rt].setv = 0;
    if (l == r) {
        cin >> tr[rt].val;
        return;
    }
    build(lc, l, mid);
    build(rc, mid + 1, r);
    //
}


void update1(int rt, int L, int R, int val) { // 区间set+lazy
    int l = tr[rt].l, r = tr[rt].r;
    if (l >= L && r <= R) {
        tr[rt].setv = 1, tr[rt].val = val;
        return;
    }
    pushDown(rt);
    if (L <= mid) update1(lc, L, R, val);
    if (mid < R) update1(rc, L, R, val);
    pushUp(rt);
}

void update2(int rt, int L, int R, int val) { // 操作2
    int l = tr[rt].l, r = tr[rt].r;
    if (l >= L && r <= R && ~tr[rt].val) {// 保证当前左区间和右区间的值相等再做判断
        if (tr[rt].val <= val) return; // 当前区间的值小于给定的x, 不更新
        tr[rt].val = __gcd(tr[rt].val, val);
        tr[rt].setv = 1;
        return;
    }
    pushDown(rt);
    if (L <= mid) update2(lc, L, R, val);
    if (mid < R) update2(rc, L, R, val);
    pushUp(rt);

}

void query(int rt) {
    int l = tr[rt].l, r = tr[rt].r;

    if (l == r) {
        cout << tr[rt].val << " ";
        return;
    }
    pushDown(rt);
    query(lc);
    query(rc);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    for (int kase = 1; kase <= t; kase++) {
        int n;
        cin >> n;
        build(1, 1, n);
        int m;
        cin >> m;
        for (int i = 1; i <= m; i++) {
            int OP, L, R, X;
            cin >> OP >> L >> R >> X;
            if (OP == 1) update1(1, L, R, X);
            else update2(1, L, R, X);
        }
        query(1);
        cout << endl;
    }
}