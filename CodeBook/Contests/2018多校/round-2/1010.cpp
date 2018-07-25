#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;
inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
const int maxn = 1e5 + 7;
const int inf = 0x3f3f3f3f;
#define lowbit(x) x & (-x)
ll c[maxn];
int n;
struct node {
    ll x;
    int index;
} s[maxn];
bool cmp(node &a, node &b) { return a.x < b.x; }
void add(ll x, ll d) {
    while (x <= n) c[x] += d, x += lowbit(x);
}
ll sum(ll x) {
    ll ret = 0;
    while (x) ret += c[x], x -= lowbit(x);
    return ret;
}
void solve();
int main() {
    ll x, y;
    while (scanf("%d %lld %lld", &n, &x, &y)) {
        memset(c, 0, sizeof c);
        for (ll i = 1; i <= n; i++) {
            scanf("%lld", &s[i].x);
            s[i].index = i;  //记录x对应的索引
        }
        sort(s + 1, s + n + 1, cmp);  //将有序数列索引与原数列索引对比

        ll ret = 0;  //交换次数, 逆序对数
        for (ll i = 1; i <= n; i++) {
            add(s[i].index, 1);
            ret += (i - sum(s[i].index));
        }
        ll allcost = ret * min(x, y);
        printf("%lld\n", allcost);
    }
}
