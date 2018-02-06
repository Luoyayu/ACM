#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 22;
typedef long long ll;
#define cmax(a, b) a = max(a, b)
#define cmin(a, b) a = min(a, b)
// 这个小题需要特殊处理，题意：
// 给出10张硬币，问如何凑出P￥且数量最多，无方案输出-1
// 思路：如果面值连续，后一个是前一个的倍数，从大往小凑，可以的话用小因子去凑更多的硬币。
// 但是本题存在50和200的特殊情况
// 特殊处理这两种情况100￥折成2*50￥,200￥拆成100￥*2；
// http://music.163.com/#/m/playlist?id=404297747
int a[maxn];
int b[maxn]={0,1,5,10,20,50,100,200,500,1000,2000};
int ans;
ll sum[maxn];
void solve(ll p, int idx, int cnt) {
	if(p < 0) return ;
	if(!idx && !p) {
		cmax(ans, cnt);
		return ;
	}
	ll rp = max(0LL, p-sum[idx-1]);
	ll nc = rp / b[idx];
	printf("idx: %d,rp: %lld, nc: %lld\n", idx, rp, nc);
	if(rp % b[idx]) nc ++;  
	if(nc <= a[idx]) solve(p- nc * b[idx], idx-1, cnt+nc); // 考虑np奇偶性
	if(nc+1 <= a[idx]) solve(p- (nc+1) * b[idx], idx-1, cnt+nc+1);
}
int main() {
	int t; scanf("%d", &t);
	while(t--) {
		int p;scanf("%d", &p);
		for(int i=1; i<=10; i++) {
			scanf("%d", &a[i]);
			sum[i] = sum[i-1] + 1LL * b[i] * a[i];
		}
		ans = -1;
		solve(p, 10, 0);
		printf("%d\n", ans);
	}
	return 0;
}