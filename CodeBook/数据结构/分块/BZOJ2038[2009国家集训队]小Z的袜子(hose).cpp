#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;
#define y2 Y2
#define next Next;
#define lowbit(x) x &(-x)
#define IOS std::ios::stdio(flase)
#define clr(x, num) memset(x, num, sizeof(x));
#define Debug(x) cout << #x << " = " << x << endl;
typedef long long ll;
const int maxr = 5e4 + 7;
//题意:询问从[l,r]区间中拿出两个颜色相同的袜子的概率
//莫队算法适用于已知[l,r]能在O(1)转移到[l+1,r],[l,r-1]复杂度O(n^1.5)

int color[maxr], belong[maxr];
int n, m, l, r;
ll sum[maxr], ans = 0;  // sum[i]表示第i种颜色在[l,r]出现的次数
struct data {
    int l, r, id;  // id记录原始顺序
    ll a, b;       // ans = a/b
} a[maxr];
bool cmp(const data &a, const data &b) {
    if (belong[a.l] == belong[b.r]) return a.r < a.r;
    return a.l < a.r;
}
bool cmp_id(const data &a, const data &b) { return a.id < b.id; }
void solve() {
    int last_l = 1, last_r = 0;
    for (int i = 1; i <= m; i++) {
        a[i].b = (a[i].r - a[i].l + 1) * (a[i].r - a[i].l);
        if (last_r < a[i].r)
            for (int j = last_r + 1; j <= a[i].r; j++)
                ans += (sum[color[j]] << 1) + 1, sum[color[j]]++;

        if (last_r > a[i].r)
            for (int j = last_r; j > a[i].r; j--)
                ans -= (sum[color[j]] << 1) - 1, sum[color[j]]--;

        if (last_l > a[i].l)
            for (int j = last_l - 1; j >= a[i].l; j--)
                ans += (sum[color[j]] << 1) + 1, sum[color[j]]++;

        if (last_l < a[i].l)
            for (int j = last_l; j < a[i].l; j++)
                ans -= (sum[color[j]] << 1) - 1, sum[color[j]]--;

        a[i].a = ans - (a[i].r - a[i].l + 1);
        last_l = a[i].l, last_r = a[i].r;
        ll k = __gcd(a[i].a, a[i].b);
        a[i].a /= k, a[i].b /= k;
    }
}
int main() {
    scanf("%d%d", &n, &m);
    ans = 0;
    clr(belong, 0);
    clr(sum, 0);
    for (int i = 1; i <= n; i++) scanf("%d", &color[i]);
    belong[0] = int(sqrt(n + 0.5));
    for (int i = 1; i <= n; i++) belong[i] = (i - 1) / belong[0] + 1;
    for (int i = 1; i <= m; i++) scanf("%d%d", &a[i].l, &a[i].r), a[i].id = i;
    sort(a + 1, a + m + 1, cmp);
    solve();

    sort(a + 1, a + m + 1, cmp_id);
    for (int i = 1; i <= m; i++) printf("%lld/%lld\n", a[i].a, a[i].b);
    return 0;
}

#include "bits/stdc++.h"
#define LL long long
using namespace std;
int n, m, last_l = 1, last_r = 0;
const int maxn = maxn;
int color[maxn], belong[maxn];
LL sum[maxn], ans = 0;
struct data {
    LL id, l, r, nume, deno;  // nume指分子，deno指分母
} A[maxn];
bool cmp(const data &a, const data &b)  // faster
{
    if (belong[a.l] < belong[b.l]) return 1;
    if (belong[a.l] > belong[b.l]) return 0;
    return a.r < b.r;
}
bool cmp_id(data a, data b) { return a.id < b.id; }

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &color[i]);
    belong[0] = sqrt(n);
    for (int i = 1; i <= n; i++) belong[i] = (i - 1) / belong[0] + 1;
    for (int i = 1; i <= m; i++) scanf("%d%d", &A[i].l, &A[i].r), A[i].id = i;

    sort(A + 1, A + m + 1, cmp);

    for (int i = 1; i <= m; i++) {
        A[i].deno = (A[i].r - A[i].l + 1) * (A[i].r - A[i].l);
        if (last_r < A[i].r) {
            for (int j = last_r + 1; j <= A[i].r; j++)
                ans += (sum[color[j]] << 1) + 1, sum[color[j]]++;
        }
        if (last_r > A[i].r) {
            for (int j = last_r; j > A[i].r; j--)
                ans -= (sum[color[j]] << 1) - 1, sum[color[j]]--;
        }
        if (last_l > A[i].l) {
            for (int j = last_l - 1; j >= A[i].l; j--)
                ans += (sum[color[j]] << 1) + 1, sum[color[j]]++;
        }
        if (last_l < A[i].l) {
            for (int j = last_l; j < A[i].l; j++)
                ans -= (sum[color[j]] << 1) - 1, sum[color[j]]--;
        }
        A[i].nume = ans - (A[i].r - A[i].l + 1);
        last_l = A[i].l, last_r = A[i].r;
        ll p = __gcd(A[i].num, A[i].deno);
        A[i].nume /= p, A[i].deno /= p;
    }
    sort(A + 1, A + m + 1, cmp_id);
    for (int i = 1; i <= m; i++)
        printf("%lld/%lld\n", A[i].nume / p, A[i].deno / p);
    return 0;
}