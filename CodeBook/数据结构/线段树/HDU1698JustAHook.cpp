#include <bits/stdc++.h>
// TODO: 区间重置, 区间求和
using namespace std;
#define lowbit(x) x&(-x);
#define lc ((rt) << 1)
#define rc ((rt) << 1 | 1)
#define mid ((l + r) >> 1)
#define clr(a, b) memset(a,b,sizeof(a);
#define debug(a) cout << #a << " = " << a << endl;
#define push_back pb
typedef long long ll;
typedef long double ld;
const ld pi = acos(-1);
const int inf = 0x3f3f3f3f;
const ll llinf = 0x3f3f3f3f3f3f3f3f;

const int maxn = 1e5 + 7;
struct node {
    int l, r;
    int setv, sum;
} tr[maxn << 2];

void pushUp(int rt) { tr[rt].sum = tr[lc].sum + tr[rc].sum; }

void pushDown(int rt, int len) {
    int lazy = tr[rt].setv;
    if (lazy) {
        tr[lc].sum = lazy * (len - (len >> 1));
        tr[rc].sum = lazy * (len >> 1);
        tr[lc].setv = tr[rc].setv = lazy;
        tr[rt].setv = 0;
    }
}

void build(int rt, int l, int r) {
    tr[rt].l = l, tr[rt].r = r;
    tr[rt].setv = 0;
    if (l == r) {
        tr[rt].sum = 1;
        return;
    }
    build(lc, l, mid);
    build(rc, mid + 1, r);
    pushUp(rt);
}

int query(int rt, int L, int R) {
    int l = tr[rt].l, r = tr[rt].r;
    if (l >= L && r <= R) {
        return tr[rt].sum;
    }
    pushDown(rt, r - l + 1);
    int ans = 0;
    if (L <= mid) ans += query(lc, L, R);
    if (mid < R) ans += query(rc, L, R);
    return ans;
}

void update(int rt, int L, int R, int val) {
    int l = tr[rt].l, r = tr[rt].r;
    if (l >= L && r <= R) {
        tr[rt].setv = val;
        tr[rt].sum = val * (r - l + 1);  // 重置区间值
        return;
    }
    pushDown(rt, r - l + 1);
    if (L <= mid) update(lc, L, R, val);
    if (mid < R) update(rc, L, R, val);
    pushUp(rt);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt","w", stdout);
    int t;  // scanf("%d", &t);
    cin >> t;
    for (int kase = 1; kase <= t; kase++) {
        int n, q;
        cin >> n >> q;
        build(1, 1, n);
        cout << "Case " << kase << ": The total value of the hook is ";
        while (q--) {
            int x, y, z;
            cin >> x >> y >> z;
            update(1, x, y, z);
        }
        cout << query(1, 1, n) << ".\n";
    }
}