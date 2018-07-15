#include <bits/stdtr1c++.h>

using namespace std;
const int maxn = 22222;

int fa[maxn];
#define rank RANK
int rank[maxn];
struct node {
    int r, c, idx;
} a[maxn];

bool cmpr(node x, node y) { return x.r < y.r; }
bool cmpc(node x, node y) { return x.c < y.c; }

void init(int n) {
    for (int i = 0; i < n; i++) fa[i] = i, rank[i] = 0;
}

int find(int x) {
    if (fa[x] == x)
        return x;
    else
        return fa[x] = find(fa[x]);
}

void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    if (rank[x] < rank[y])
        fa[x] = y;
    else {
        fa[y] = x;
        if (rank[x] == rank[y]) rank[x]++;
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d %d", &n, &k);
        init(n);
        for (int i = 0; i < n; i++) {
            int r, c;
            scanf("%d %d", &r, &c);
            a[i].c = c, a[i].r = r, a[i].idx = i;
        }
        sort(a, a + n, cmpc);
        for (int i = 1; i < n; i++)
            if (a[i].c - a[i - 1].c <= k) merge(a[i].idx, a[i - 1].idx);

        sort(a, a + n, cmpr);
        for (int i = 1; i < n; i++)
            if (a[i].r - a[i - 1].r <= k) merge(a[i].idx, a[i - 1].idx);
            
        int ans = 0;
        for (int i = 0; i < n; i++) ans += (fa[i] == i);
        printf("%d\n", ans);
    }
}