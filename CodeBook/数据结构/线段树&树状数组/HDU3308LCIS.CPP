/// LCIS 线段树
/// op1: U A B 用B代替第A个数
/// op2: Q A B 查询[A,B]中最长连续上升子序列
///区间合并
#include <bits/stdc++.h>
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
using namespace std;
const int N = int(1e5 + 7);
int n, m, x, y;
int seg[N << 2], ls[N << 2], rs[N << 2];
int a[N];
void pushup(int rt, int l, int r) {
    int mid = l + r >> 1;
    ls[rt] = ls[rt << 1];
    rs[rt] = rs[rt << 1 | 1];
    seg[rt] = max(seg[rt << 1], seg[rt << 1 | 1]);
    if (a[mid] < a[mid + 1]) {
        if (ls[rt] == mid - l + 1) ls[rt] += ls[rt << 1 | 1];
        if (rs[rt] == r - mid) rs[rt] += rs[rt << 1];
        seg[rt] = max(seg[rt], ls[rt << 1 | 1] + rs[rt << 1]);
    }
}
void build(int rt, int l, int r) {
    if (l == r) {
        seg[rt] = ls[rt] = rs[rt] = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(lson);
    build(rson);
    pushup(rt, l, r);
}
void add(int rt, int l, int r) {
    if (l == r) {
        return;
    }
    int mid = l + r >> 1;
    if (x <= mid)
        add(lson);
    else
        add(rson);
    pushup(rt, l, r);
}
int query(int rt, int l, int r) {
    if (x <= l && r <= y) return seg[rt];
    int mid = (l + r) >> 1;

    // cout<<"x: "<<x<<" "<<"y :"<<y<<endl;
    // cout<<"mid : "<<mid<<endl;
    if (y <= mid) return query(lson);  //完整的block
    if (x > mid) return query(rson);

    int t1 = query(lson);
    int t2 = query(rson);
    int ans = max(t1, t2);
    if (a[mid] < a[mid + 1])
        ans = max(ans, (min(ls[rt << 1 | 1], y - mid) +
                        min(rs[rt << 1], mid + 1 - x)));
    return ans;
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        char str[5];
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        build(1, 1, n);
        while (m--) {
            scanf("%s%d%d", str, &x, &y);
            ++x;
            if (str[0] == 'U')
                a[x] = y, add(1, 1, n);
            else
                ++y, printf("%d\n", query(1, 1, n));
        }
    }
    return 0;
}
