//HDU 2647 Reward a>b
//反向拓扑，分层记和
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 10000 + 5;
int N, M;
int indeg[maxn], tmp[maxn],head[maxn];
struct node
{
	int to, next;
}edge[maxn<<1];

void add(int a, int b, int tol)
{
	edge[tol].to = b;
	edge[tol].next = head[a];
	head[a] = tol;
}

int toposort()
{
	int rw = 888, ans = 0,tol=0;
	for (int i = 0; i<N; i+=tol)
	{
		int j;tol = 0;
		for (j = 1; j<=N; j++)//将入度为0的点提取出来
			if (indeg[j] == 0)
				tmp[tol++] = j,indeg[j] = -1;//标记已访问过

		if (tol == 0) return -1;//所有点都有前驱，则不存在拓扑序

		ans += rw*tol; rw++;
		for (int j = 0; j<tol; j++)
			for (int k = head[tmp[j]]; k + 1; k = edge[k].next)
				indeg[edge[k].to]--;
	}
	return ans;
}
int main()
{
	while (scanf("%d%d", &N, &M) != EOF)
	{
		memset(head, -1, sizeof head);
		memset(indeg, 0, sizeof indeg);
		for (int i = 0; i<M; i++)
		{
			int a, b;
			scanf("%d %d", &a, &b);//b->a是一种关系
			add(b, a, i);
			indeg[a]++;
		}
		printf("%d\n", toposort());
	}
	return 0;
}
