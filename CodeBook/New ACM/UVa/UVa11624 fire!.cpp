//广搜的预处理
//UVa 11624
#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn= 1005;
const int inf=0x3f3f3f3f;
int dir[4][2]={-1,0,0,1,1,0,0,-1};
int map[maxn][maxn];
int vis[maxn][maxn];
int n,m,sx,sy,ex,ey;
struct node
{
	int x,y,steps;
	node(int xx,int yy,int ss){x=xx,y=yy,steps=ss;}
};
int check(int &a,int &b)
{
	if(a<0||a>=n||b<0||b>=m||map[x][y]=='#')
		return false;
	return true;
}
void init()
{
	scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
			{
				scanf("%s",&map[i]);
				if(map[i][j]=='J')
					sx=i,sy=j;
				if(map[i][j]=='F')
					ex=i,ey=j;

			}
}

void bfs()
{

}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		init();
		int ans=escape();
		if(ans=-1) printf("IMPOSSIBLE\n");else printf("%d\n",ans);
	}
	return 0;
}