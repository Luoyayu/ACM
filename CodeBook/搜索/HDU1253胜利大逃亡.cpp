#include <cstring>
#include <cstdio>
#include <queue>
#include <cmath>
using namespace std;
int map[55][55][55];
bool vis[55][55][55];
int dir[6][3]={{1,0,0},{-1,0,0},{0,0,1},{0,0,-1},{0,1,0},{0,-1,0}};  
int a,b,c,time;
struct node
{
	int x,y,z,steps;
};
int bfs()
{
	node now,next;
	queue<node> q;
	now.x=now.y=now.z=now.steps=0;
	memset(vis,false,sizeof vis);
	vis[0][0][0]=true;
	q.push(now);
	while(!q.empty())
	{
		now=q.front();
		q.pop();
		if(now.steps>time)  
        	return -1; //不剪枝你能过？
		if(now.x==a-1&&now.y==b-1&&now.z==c-1&&now.steps<=time)
			return now.steps;
		for(int i=0;i<6;i++)
		{
			next=now;
			next.x+=dir[i][0],next.y+=dir[i][1],next.z+=dir[i][2];
			if(next.x>=0 && next.x<a && next.y>=0 && next.y<b && next.z>=0 && next.z<c && !vis[next.x][next.y][next.z] && !map[next.x][next.y][next.z]&&next.steps<=time)
			{
				next.steps++;
				vis[next.x][next.y][next.z]=true; 
				if(abs(next.x-a+1)+abs(next.y-b+1)+abs(next.z-c+1)+next.steps>time)  
           		 continue;  //不剪枝你能过？
        		q.push(next);
			}
		}
	}
	return -1;
}
int main()
{
	int k;
	//freopen("input.txt","r",stdin);
	scanf("%d",&k);
	while(k--)
	{
		scanf("%d %d %d %d",&a,&b,&c,&time);
		for(int i=0;i<a;i++)
			for(int j=0;j<b;j++)
				for(int k=0;k<c;k++)
						scanf("%d",&map[i][j][k]);//注意，一不小心挂了
		
		printf("%d\n",bfs());
	}
	return 0;
}