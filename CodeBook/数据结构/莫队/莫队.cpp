#include <bits/stdc++.h>
using namespace std;
#define clr(a, b) memset(a, b, sizeof(a));
#define debug(x) cout << #x << " = " << x << endl;
#define y2 Y2
/* 莫队算法
 * BZOJ 2038 小Z的袜子
 * 设查询的区间长度为n, ANS = \frac{\sum_{i=0}^{color_n} sum[i]*(sum[i]-1) }{n(n-1)}
 * 莫队算法巧妙的做离线SORT，可以在两个询问之间快速做状态跳转。
 * l指针向左移动一个单位，r指针向右移动一个单位，这些状态都可以在O(1)时间完成跳转
 * 其优化基于分块的双关键词：若l在同块，则以r作为排序关键词；若l不在同块，将l作为排序关键词
 * 思路：
*/
typedef long long ll;
const int maxn = 5e5 + 7;
struct Mo {
	int l, r ,idx;
	ll A, B;
}q[maxn]; // 询问
inline ll S(ll x ) { return x*x; }
int n, m, color[maxn];
int block_size, belong[maxn];
ll sum[maxn], ans;
bool cmp(const Mo &a, const Mo &b) {
	return belong[a.l]==belong[b.l] ? a.r < b.r : a.l < b.l;
}
bool CMP(const Mo &a, const Mo &b) { return a.idx < b.idx; }
inline void revise(int x, int add) { // O(1) 转移
	ans -= S(sum[color[x]]);
	sum[color[x]] += add; // 第x种颜色加上add个
	ans += S(sum[color[x]]);
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m;
	block_size = sqrt(n);
	for(int i=1;i<=n;i++) cin >> color[i], belong[i]=i/block_size+1;
	for(int i=1;i<=m;i++) cin >> q[i].l >> q[i].r, q[i].idx = i;
	sort(q+1, q+m+1, cmp);
	int l=1, r=0;
	for(int i=1;i<=m;i++) {
		while(l<q[i].l) revise(l,  -1), l++;
		while(l>q[i].l) revise(l-1, 1), l--;
		while(r<q[i].r) revise(r+1, 1), r++;
		while(r>q[i].r) revise(r,  -1), r--;
		
		if(q[i].l == q[i].r) {
			q[i].A =0, q[i].B = 1;
			continue;
		}
		int N = q[i].r - q[i].l + 1;
		q[i].A = ans - N;
		q[i].B = 1LL*N*(N-1);
		ll gcd = __gcd(q[i].A, q[i].B);
		q[i].A /= gcd, q[i].B /=gcd;
	}
	sort(q+1, q+m+1, CMP);
	for(int i=1;i<=m;i++) cout << q[i].A << "/" << q[i].B << endl;
}
