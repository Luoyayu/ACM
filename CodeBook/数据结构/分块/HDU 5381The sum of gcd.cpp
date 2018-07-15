///莫队：无修改的离线区间查询问题
///复杂度O(n^1.5)
///题意：区间段gcd和
///曼哈顿距离|L-L'|+|R-R'|
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 10000 + 10;
int a[maxn];
int n;
int f(int l, int r) {}
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int Q;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        scanf("%d", &Q);
        while (Q--) {
            int l, r;
            scanf("%d%d", &l, &r);
            printf("%d\n", f(l, r));
        }
    }
    return 0;
}
