// 题意：有序数列按字典序输出6个数，递归实现
#include <bits/stdc++.h>
using namespace std;
const int maxn = 22;
int a[maxn], b[8], k;
void dfs(int num, int pos) {
	if(num == 7) {
		for (int i = 1; i < num; ++i)
			printf("%d%c", b[i], i==num-1?'\n':' ');
		return ;
	}
	if(pos > k) return; //递归出口
	b[num] = a[pos];
	dfs(num+1, pos+1); //a[pos]选
	dfs(num, pos+1);//a[pos]不选，下次覆盖
}
int main() {
	int flag = 0;
	while(scanf("%d",&k), k) {
		if(flag) puts("");
		flag = 1;
		for(int i=1;i<=k;i++)
			scanf("%d",&a[i]); //给出递增序
		dfs(1,1);
	}
	return 0;
}