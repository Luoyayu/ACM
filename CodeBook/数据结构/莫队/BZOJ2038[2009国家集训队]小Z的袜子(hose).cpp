/**************************************************************
    Problem: 2038
    User: luoyayu
    Language: C++
    Result: Accepted
    Time:1412 ms
    Memory:4048 kb
****************************************************************/

#include <bits/stdc++.h>
#define LL long long
using namespace std;
typedef long long ll;
int n, m, last_l = 1, last_r;
LL ans, p;
int color[50010], belong[50010];
LL sum[50010];
struct Data {
    LL id, l, r, nume, deno;  // nume分子，deno分母
} q[50010];
int cmp1(const Data &a, const Data &b) {
	return belong[a.l]==belong[b.l] ? a.r<b.r : a.l<b.l;
}
int cmp_id(const Data &a, const Data &b) { return a.id < b.id; }
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &color[i]);
    belong[0] = sqrt(n);
    for (int i = 1; i <= n; i++) belong[i] = (i - 1) / belong[0] + 1;
    for (int i = 1; i <= m; i++) scanf("%lld %lld", &q[i].l, &q[i].r), q[i].id = i;
    sort(q + 1, q + m + 1, cmp1);

    for (int i = 1; i <= m; i++) {
        q[i].deno = (q[i].r - q[i].l + 1) * (q[i].r - q[i].l);

		if (last_r < q[i].r) {
            for (int j = last_r + 1; j <= q[i].r; j++)
                ans += ((sum[color[j]] << 1) + 1), sum[color[j]]++;
        }

		if (last_r > q[i].r) {
            for (int j = last_r; j > q[i].r; j--)
                ans -= ((sum[color[j]] << 1) - 1), sum[color[j]]--;
        }
        if (last_l > q[i].l) {
            for (int j = last_l - 1; j >= q[i].l; j--)
                ans += ((sum[color[j]] << 1) + 1), sum[color[j]]++;

		}
        if (last_l < q[i].l) {
            for (int j = last_l; j < q[i].l; j++)
                ans -= ((sum[color[j]] << 1) - 1), sum[color[j]]--;

		}
        q[i].nume = ans - (q[i].r - q[i].l + 1);
        last_l = q[i].l;
        last_r = q[i].r;
    }
    sort(q + 1, q + m + 1, cmp_id);
    for (int i = 1; i <= m; i++) {
        if (!q[i].nume) {
            printf("0/1\n");
            continue;
		}
        p = __gcd(q[i].nume, q[i].deno);
        printf("%lld/%lld\n", q[i].nume / p, q[i].deno / p);
	}
    return 0;
}
