// HDU 1711 Number Sequence
// KMP 的思想用在数字序列上
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000115;
long long s[maxn], p[maxn];
long long Next[maxn], n, m;
void getnext() {
    int i = 0, j = Next[0] = -1;
    while (i < m) {
        if (j == -1 || p[i] == p[j])
            Next[++i] = ++j;
        else
            j = Next[j];
    }
}
int KMP() {
    getnext();
    int i = 0, j = 0;
    while (i < n) {
        while (j != -1 && s[i] != p[j]) j = Next[j];
        i++, j++;
        if (j == m) return i;
    }
    return -1;
}
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%lld %lld", &n, &m);
        for (int i = 0; i < n; i++) scanf("%d", &s[i]);
        for (int i = 0; i < m; i++) scanf("%d", &p[i]);
        int ans = KMP();
        if (ans == -1)
            printf("-1\n");
        else
            printf("%lld\n", ans - m + 1);
    }
    return 0;
}
