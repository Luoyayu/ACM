#include<bits/stdc++.h>
using namespace std;
int n, kase;
const int maxn = 55;
int num[maxn], vis[maxn], isPrime[maxn];
int judge(int d) {
	for(int i=2; i*i<=d; i++)
		if(d % i == 0) return 0;
	return 1;
}
void dfs(int th){

	if(th == n && isPrime[num[n-1]+1]) {
		for(int i=0; i<n-1; i++) printf("%d ", num[i]);
		printf("%d\n", num[n-1]);
		return;
	}

	for (int i=2; i<=n ;i++){
		if(!vis[i] && isPrime[num[th-1]+i]){
			vis[i] = 1;
			num[th] = i;
			dfs(th + 1);
			vis[i] = 0;
		}
	}
}
int main() {
	for(int i=2; i<maxn; i++) isPrime[i] = judge(i);// printf("%d : %d\n", i, isPrime[i]);
	while(scanf("%d", &n)!=EOF) {
		num[0] = 1;
		printf("Case %d:\n", ++ kase);
		memset(vis,0,sizeof(vis));
		dfs(1);
		puts("");
	}
	return 0;
}
