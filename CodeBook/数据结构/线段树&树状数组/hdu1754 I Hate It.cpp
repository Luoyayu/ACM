#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000 + 500;
struct node {
    int l, r, MAX;
} tree[4 * maxn];
int A[maxn];
void maintain(int i) {
    tree[i].MAX = max(tree[i << 1].MAX, tree[i << 1 | 1].MAX);
}
void build(int i, int L, int R) {
    tree[i].l = L, tree[i].r = R;
    tree[i].MAX = 0;
    if (L == R) {
        scanf("%d", &tree[i].MAX);
        // tree[i].MAX=A[r];
        return;
    }
    int M = (L + R) >> 1;
    build(i << 1, L, M);
    build(i << 1 | 1, M + 1, R);
    maintain(i);
}
void update(int i, int p, int v) {
    int L = tree[i].l;
    int R = tree[i].r;
    int M = (L + R) >> 1;
    if (L == R && L == p) {
        tree[i].MAX = v;
        return;
    }
    if (M >= p)
        update(i << 1, p, v);
    else
        update(i << 1 | 1, p, v);
    maintain(i);
}
int query(int i, int l, int r) {
    int L = tree[i].l;
    int R = tree[i].r;
    if (l <= L && R <= r) return tree[i].MAX;
    int M = (L + R) >> 1;
    int ans = 0;
    if (M < r) ans = query(i << 1 | 1, l, r);
    if (M >= l) ans = max(ans, query(i << 1, l, r));
    return ans;
}
int main() {
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) {
        build(1, 1, n);
        while (m--) {
            char op[5];
            int x, y;
            scanf("%s%d%d", op, &x, &y);
            if (op[0] == 'U')
                update(1, x, y);
            else
                printf("%d\n", query(1, x, y));
        }
    }
    return 0;
}