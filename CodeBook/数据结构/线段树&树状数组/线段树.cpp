#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
#define lson l, m, rt * 2
#define rson m + 1, r, rt * 2 + 1
int tree[50005 << 2];
void maintain(int rt) { tree[rt] = tree[rt * 2] + tree[rt * 2 + 1]; }

int query(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R)
        return tree[rt];
    else {
        int MAX = -INF;
        int m = (l + r) / 2;
        int ans = 0;
        if (L <= m) ans += query(L, R, lson);
        if (m < R) ans += query(L, R, rson);
        return ans;
    }
}
void build(int l, int r, int rt) {
    if (l == r) {
        scanf("%d", &tree[rt]);
        return;
    } else {
        int m = (l + r) / 2;
        build(lson);
        build(rson);
        maintain(rt);
    }
}
void update(int p, int c, int l, int r, int rt) {
    if (l == r)
        tree[rt] += c;
    else {
        int m = (l + r) / 2;
        if (p <= m)
            update(p, c, lson);
        else
            update(p, c, rson);
        maintain(rt);
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
        build(1, n, 1);
        while (~scanf("%s", s)) {
            if (s[0] == 'E') break;
            scanf("%d%d", &a, &b);
            if (s[0] == 'Q')
                printf("%d\n", query(a, b, 1, n, 1));
            else if (s[0] == 'S')
                update(a, -b, 1, n, 1);
            else
                update(a, b, 1, n, 1);
        }
    }
    return 0;
}