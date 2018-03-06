//POJ
/*
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#include<iostream>
using namespace std;
int N, K;
const int MAXN = 1000010;
int vis[2*MAXN ];//  判重标记,visited[i]=1表示i已经扩展过
struct Step
{
	int x;
	int steps;
	Step(int xx, int s) :x(xx), steps(s) {}
};
queue<Step>q;//Open表
int main()
{
	while (scanf("%d %d",&N,&K)!=EOF)
	{
		memset(vis, 0, sizeof(vis));
		q.push(Step(N, 0));
		vis[N] = 1;
		if (N == K)
		{
			printf("0\n");
			continue;
		}
		while (!q.empty())
		{
			Step s = q.front();
			if (s.x == K)
			{
				cout << s.steps << endl;
				return 0;
			}
			else
			{
				if (s.x - 1 >= 0 && !vis[s.x - 1])
				{
					q.push(Step(s.x - 1, s.steps + 1));
					vis[s.x - 1] = 1;
				}
				if (s.x + 1 >= 0 && !vis[s.x + 1])
				{
					q.push(Step(s.x + 1, s.steps + 1));
					vis[s.x + 1] = 1;
				}
				if (s.x * 2 < MAXN && !vis[s.x * 2])
				{
					q.push(Step(s.x * 2, s.steps + 1));
					vis[s.x * 2] = 1;
				}
				q.pop();
			}
		}
	}
	return 0;
}
*/
//HDU

#include <iostream>
#include <cstdio> 
#include <cstring>
#include <queue>
using namespace std;
const int Max = 100000 + 10;
int vis[Max * 2];
int time[Max * 2];
int n, k;
void bfs(int x)
{
	int nx, s;
	queue<int> p; //open表 
	vis[x] = 1, time[x] = 0, p.push(x); //出队，入closed表 
	while (!p.empty())
	{
		s = p.front();
		p.pop(); //出栈 
		for (int i = 1; i <= 3; i++) //每次可走三种 
		{
			if (i == 1)
				nx = s + 1;
			else if (i == 2)
				nx = s - 1;
			else
				nx = s * 2;

			if (!vis[nx] && nx <= Max && nx >= 0)
			{
				vis[nx] = 1;
				p.push(nx);
				time[nx] = time[s] + 1; //时间+1 
			}
			if (nx == k)
			{
				cout << time[nx] << endl;
				return;
			}
		}
	}
}
int main()
{
	while (scanf("%d %d", &n, &k) != EOF)
	{
		memset(vis, 0, sizeof(vis));
		memset(time, 0, sizeof(time));
		if (n == k)
			cout << "0" << endl;
		else
			bfs(n);
	}
	return 0;
}