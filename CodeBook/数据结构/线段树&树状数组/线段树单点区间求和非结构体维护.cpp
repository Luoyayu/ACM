#include <bits/stdc++.h>
#define lson i << 1, l, M
#define rson i << 1 | 1, M + 1, r
#define Lson i << 1
#define Rson i << 1 | 1
using namespace std;
int tree[50005 << 2];
void pushup(int node) { tree[node] = tree[Lson] | tree[Rson]; }
void build(int node, int l, int r) {
    if (l == r) {
        scanf("%d", &tree[i]);
        return;
    } else {
        int M = (l + r) >> 1;
        build(lson), build(rson);
        pushup(node);
    }
}
void update(int p, int val, int node, int l, int r) {
    if (l == r)
        tree[node] += val;
    else {
        int M = (l + r) / 2;
        if (p <= M)
            update(p, val, lson);
        else
            update(p, val, rson);
        pushup(node);
    }
}
int query(int L, int R, int i, int l, int r) {
    if (L <= l && r <= R)
        return tree[i];
    else {
        int M = (l + r) >> 1;
        int ans = 0;
        if (L <= M) ans += query(L, R, lson);
        if (M < R) ans += query(L, R, rson);
        return ans;
    }
}
int main() {
    int t;
    int kase = 0;
    scanf("%d", &t);
    while (t--) {
        printf("Case %d:\n", ++kase);
        memset(tree, 0, sizeof tree);
        int n, a, b;
        char s[30];
        scanf("%d", &n);
        build(1, 1, n);
        while (~scanf("%s", s)) {
            if (s[0] == 'E') break;
            scanf("%d%d", &a, &b);
            if (s[0] == 'Q')
                printf("%d\n", query(a, b, 1, 1, n));
            else if (s[0] == 'S')
                update(a, -b, 1, 1, n);
            else
                update(a, b, 1, 1, n);
        }
    }
    return 0;
}
