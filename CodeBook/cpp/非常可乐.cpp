#include <cstdio>
#include <csring>
#include <queue>
using namespace std;
int vis[105][105];
struct node
{
	int x_n,y_m,total,steps;
};
void bfs()
{
	queue<node> q;
	memset(vis,0,sizeof vis);
	node st,nt;
	st.a=st.b=st.s=st.steps=0;
	q.push(st);
	vis[a][b]=1;
	while(!q.empty())
	{
		nt=p.front();
		q.pop();
		if(nt.a==s/2&&nt.s==s/2)
			return nt.steps;
		if(nt.total+nt.x>n) //s->a
		{
			
		}
	}
}
int n,m,s;
int main()
{
	while(scanf("%d %d %d"&s,&n,&m)!=EOF)
	{
		if(s==0&&n==0&&m==0)
			break;

		if(s&1)
		{
			printf("NO\n");
			break;
		}

	}
}