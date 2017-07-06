#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int maxn = 30005;
vector <int> V[maxn];
int indgree[maxn], output[maxn];
int  n, m, cnt;
void toposort()
{
	priority_queue<int>q;
	for(int i = 1; i <= n; i++)
        if (!indgree[i])
			q.push(i);
	while(!q.empty())
	{
		int now = q.top();q.pop();
		for(int i = 0; i<V[now].size(); i++)
		{
			int v = V[now][i];
			indgree[v]--;
			if (!indgree[v])
				q.push(v);
		}
		output[cnt++] = now;
	}
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &n, &m);
		memset(indgree, 0, sizeof indgree);
		memset(output, 0, sizeof output);
		for(int i = 0; i<=n; i++) V[i].clear();
		for(int i = 0; i < m; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
            indgree[x]++;
			V[y].push_back(x);//反建图，先搞定穷人
		}
		toposort();
		for(int i = cnt - 1; i >=1; i--)//逆向输出
			printf("%d ", output[i]);
        printf("%d\n", output[0]);
	}
	return 0;
}
