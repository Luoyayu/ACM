///如果type==0即是求出整数的约数为K
///如果type==1即是
#include <cstdio>
using namespace std;
int k;
const int maxn = 50000 + 10;
typedef __int64 LL;
LL ans;
int ip[maxn];
const LL INF = ((LL)1 << 62) + 1;
int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
void prim() {
    for (int i = 1; i <= maxn; i++) {
        ip[i] += i;
        for (int j = i; j <= maxn; j += i) ip[j]--;
        if (!ip[ip[i]]) ip[ip[i]] = i;
        ip[i] = 0;
    }
}
void dfs(int num, LL t, int pos) {
    if (num == k && ans > t) ans = t;
    if (num >= k || (pos >= 15)) return;
    for (int i = 1; i <= 62; i++) {
        if (t > ans / p[pos] || num * (i + 1) > k) return;  ///不剪枝会wa
        t *= p[pos];
        if (k % (num * (i + 1)) == 0) dfs(num * (i + 1), t, pos + 1);
    }
}

int main() {
    int t;
    scanf("%d", &t);
    prim();
    for (int kase = 1; kase <= t; kase++) {
        int type;
        scanf("%d %d", &type, &k);
        if (type)
            ans = ip[k];
        else {
            ans = INF;
            dfs(1, 1, 0);
        }
        printf("Case %d: ", kase);
        if (ans == 0)
            printf("Illegal\n");
        else if (ans >= INF)
            printf("INF\n");
        else
            printf("%I64d\n", ans);
    }
    return 0;
}
