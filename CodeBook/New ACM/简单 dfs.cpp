#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 222;
int n, ki[maxn], vis[maxn];
int bfs(int a, int b)
{
	queue<int> Q;
	Q.push(a);
	vis[a] = 1;
	if (a == b) return 0;
	else
	{
		while (!Q.empty())
		{
			int u = Q.front();
			Q.pop();
			if (u + ki[u] > 0 && u + ki[u] <= n&&!vis[ki[u]+u] )
			{
				Q.push(u + ki[u]);
				vis[u + ki[u]] = vis[u] + 1;
			}
			if (u - ki[u] > 0 && u - ki[u] <= n && !vis[ u-ki[u] ])
			{
				Q.push(u - ki[u]);
				vis[u - ki[u]] = vis[u] + 1;
			}
			if(u==b)
				return vis[u]-1;
		}
	}

	return -1;
}
int main()
{
	int a, b;
	while (scanf("%d",& n), n)
	{
		scanf("%d%d",& a,&b);
		for (int i=1;i<=n;i++)
			scanf("%d",& ki[i]);
		memset(vis, 0, sizeof(vis));
		printf("%d\n", bfs(a, b));
	}
	return 0;
}