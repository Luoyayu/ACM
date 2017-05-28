#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10000;
const int INF = 100000000;
int n, S, V[MAXN], d[MAXN], vis[MAXN], W[MAXN];

int dpmax(int S)
{
	if(vis[S]) return d[S];
	vis[S] = 1;
	int &ans = d[S];
	ans = -1 << 30;
	for(int i = 1; i <= n; ++i)
		if(S >= V[i]) ans = max(ans, dpmax(S - V[i]) + W[i]);
	return ans;
}

int main()
{
	memset(vis, 0, sizeof(vis));
	cin  >> S;
	for(int i = 1; i <= 2; ++i)
		cin >> V[i] >> W[i];
	cout << dpmax(S) << endl;
	return 0;
}
