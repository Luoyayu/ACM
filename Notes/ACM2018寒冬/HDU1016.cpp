#include <bits/stdc++.h>
using namespace std;
// 题意：把自然数排成一个环，使得相邻两位数的和是素数
// 第一个数总是为1
// 按字典序输出所有可能的情况
// 思路：dfs深搜

const int maxn = 55; //maxn>=39
bool isprime[maxn];
bool vis[maxn];
int n, kase;
bool judgePrime(int d){
	for(int i=2; i<d; i++)
		if(d%i == 0) return false;
	return true;
}

int num[maxn];

void dfs(int x) { //传入序号
	if(x == n && isprime[num[n-1]+1]) { 
	//如果此时已经排好n个数字，检查num[n-1]和1的和是否也是质数，
	//是则输出这n个质数，不是return到上个帧
		for(int i=0;i<n-1;i++)
			printf("%d ", num[i]);
		printf("%d\n", num[n-1]);
		return ;
	}
	for(int i=2; i<=n; i++){
		if(!vis[i] && isprime[num[x-1]+i]) {
			vis[i] = 1;
			num[x] = i;
			dfs(x + 1);
			vis[i] = 0;
		}
	}
}

int main() {
	for(int i=2; i<=maxn; i++) // 预处理质数，主要要满足maxn>=20+19
		isprime[i] = judgePrime(i);
	while(scanf("%d", &n)!=EOF){
		num[0] = 1; // 第一个数总为1
		memset(vis, false, sizeof(vis));
		printf("Case %d:\n", ++kase);
		dfs(1);
		puts("");
	}
}
