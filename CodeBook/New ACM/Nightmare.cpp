//BFS解法
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
int dir[4][2]={1,0,0,1,-1,0,0,-1};
int map[10][10],sx,sy,n,m;
struct node
{
	int x,y,steps,cnt;
};
bool jugde(int x,int y)
{
	if(x>0 && x<=n && y>0 && y<=m && map[x][y])
		return true;
	return false;
}
int bfs()
{
	queue<node> Q;
	node start,next;
	start.x=sx,start.y=sy,start.steps=0,start.cnt=6;
	next.steps=0,next.cnt=6;
	Q.push(start);
	map[sx][sy]=0;
	while(!Q.empty())
	{
		start=Q.front();
		Q.pop();
		for(int i=0;i<4;i++)
		{
			next=start;//此处因使用mid挂了
			next.x+=dir[i][0];
			next.y+=dir[i][1];
			if(jugde(next.x,next.y))
			{
				if(map[next.x][next.y]==1)
				{
					next.cnt--;
					if(next.cnt>=1)
					{
						next.steps++;
						Q.push(next);
					}
				}
				if(map[next.x][next.y]==4)
				{
					next.cnt--;
					if(next.cnt>=1)
					{	
						next.steps++;
						next.cnt=6;
						Q.push(next);
					}
					map[next.x][next.y]=0;//剪枝
				}

				if(map[next.x][next.y]==3 && next.cnt>1)
					return next.steps+1;
			}
		}
	}
	return -1;
}

int main()
{
	int t;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
					{
						scanf("%d",&map[i][j]);
						if(map[i][j]==2)
							sx=i,sy=j;
					}
		printf("%d\n",bfs());
	}
	return 0;
}