#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
// 打表推公式
int a[]={1,9,41,109,205,325,473};
int main() {
	int t;scanf("%d", &t);
	for(int kase=1; kase<=t; kase++){
		ll n;scanf("%lld", &n);
		printf("Case #%d: ", kase);
		if(n<=6) {
			printf("%d\n",a[n]);
			continue;
		}
		ull ans = 176 * (n-6) + (n-6)*(n-7)*14 + 473;
		printf("%llu\n",ans);		
	}
	return 0;
}

/*
int dir[][2]={{-2,1},{-1,2},{1,2},{2,1},{1,-2},{2,-1},{-2,-1},{-1,-2}};
struct node{
	int x,y;
	int steps;
};
const int maxn = 1111;
int ans[maxn];
bool vis[maxn][maxn];
void bfs() {
	queue<node> q;
	q.push(node{500,500,0});
	ans[0] = 1;
	vis[500][500] = 1;
	while(!q.empty()){
		node cur = q.front();
		q.pop();
		if(cur.steps == 20) continue;
		for(int i=0; i<8; i++){
			node nxt = cur;
			nxt.steps ++;
			nxt.x += dir[i][0];
			nxt.y += dir[i][1];
			if(vis[nxt.x][nxt.y]) continue;
			vis[nxt.x][nxt.y] = 1;
			ans[nxt.steps] ++;
			q.push(nxt);
		}
	}
}

int main() {
	bfs();
	int ret = 0;
	for(int i=0;i<=20;i++) printf("%d ", ans[i]);puts("");
	for(int i=0;i<20;i++) printf("%d ", (ret+=ans[i])); puts("");
	//for(int i=1;i<20;i++) printf("%d ",ans[i]-ans[i-1]);
	for(int i=7;i<=20;i++) printf("%d ",176*(i-6)+(i-6)*(i-7)/2*28+473);
}
*/
