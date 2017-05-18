//SPFA HDU 1874畅通工程续
#include <cstdio>
#include <queue>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=9999;
const int inf=99999999;
int dis[maxn];
bool vis[maxn];
int n,m,w;
int map[maxn][maxn];
/*SPFA
SPFA是基于B-F的队列改进版，可以通过入队次数是否超过N次判断是否存在负环
邻接表复杂度O(kE)k<=2
B-F证明：每次放入队尾的点都是经过松弛操作达到的，及每次更新d值，故算法执行会使得d值越来越小。
他用：dfs判断负环（较bfs稳定，效率高）
*/
#if 0
void SPFA00(int s) //邻接矩阵
{
	memset(vis,false,sizeof vis);
	for(int i=0;i<n;i++)  //
		dis[i]=inf;
	dis[s]=0,vis[s]=true;//出入队标记
	queue<int> q;
	q.push(s);
	while(!q.empty())
	{
		int cur=q.front();
		q.pop();
		vis[cur]=false;//已出队消除标记，等待更新
		for(int i=0;i<n;i++)//所有与队头相连的点i松弛操作，松弛成功标记入队
			if(dis[cur]+map[cur][i]<dis[i])//relax
			{	
				dis[i]=dis[cur]+map[cur][i];
					if(!vis[i])
					{
						q.push(i);//入队
						vis[i]=true;
					}
			}
	}
} 
int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				map[j][i]=map[i][j]=inf;
	//	fill(map,map+m,inf);
		int sx,ex;
		
		for(int i=1;i<=m;i++)
		{
			scanf("%d %d %d",&n,&v,&w);
			map[n][v]=map[v][n]=min(w,map[n][v]);
		}
		scanf("%d%d",&sx,&ex);
		SPFA00(sx);
		if(dis[ex]==inf)
			printf("-1\n");
		else 
			printf("%d\n",dis[ex]);
	}	
	
} 

#endif


int head[maxn],len;
struct edge
{
	int to,nx,val;
}e[maxn];

void insert(int from,int to,int val)
{
	e[len].to=to;
	e[len].val=val;
	e[len].nx=head[from];
	head[from]=len++;
}

void SPFA01(int s)//邻接表
{
	memset(vis,false,sizeof vis);
	for(int i=0;i<n;i++)
		dis[i]=inf;
	queue<int> q;
	q.push(s);
	vis[s]=true,dis[s]=0;
	while(!q.empty())
	{
		int cur=q.front();
		q.pop();
		vis[cur]=false;
		for(int i=head[cur];i!=-1;i=e[i].nx)//邻接表
		{
			int id=e[i].to;
			if(dis[id]>dis[cur]+e[i].val)
			{
				dis[id]=dis[cur]+e[i].val;
				if(!vis[id])
				{
					vis[id]=true;
					q.push(id);
				}
			}
		}
	}
}
int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		len=0;
		memset(head,-1,sizeof(head));

		for(int i=0;i<m;i++)
			{
				int to,from,val;
				scanf("%d%d%d",&from,&to,&val);
				insert(from,to,val);
				insert(to,from,val);
			}
		int sx,ex;
		scanf("%d%d",&sx,&ex);
		SPFA01(sx);
		if(inf==dis[ex])
			printf("-1\n");
		else
			printf("%d\n",dis[ex]);
	}
	return 0;
}







//spFA 003
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int MAX = 200;
const int inf = -50000;
struct Node
{
    int to;
    int nex;
    int val;
}node[20010];

int len;
int head[MAX];
int value[MAX];
int pre[MAX];
int n;
void addNode(int from, int to )
{
    node[len].to = to;
    node[len].nex = head[from];
    node[len].val = value[to];
    head[from] = len++;
    return;
}
bool vis[MAX];
int dis[MAX];
void spfa()
{
    for(int i = 1; i <= n ;++i)
        vis[i] = false,pre[i] = 0,dis[i] = inf;
        
    dis[1] = 0,vis[1]= true;
    queue<int> q;
    q.push(1);
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        vis[now] = false;
        for(int i = head[now];i;i = node[i].nex)
        {
            int to = node[i].to;
            if(dis[to] < dis[now] + node[i].val)
            {
                dis[to] = dis[now] + node[i].val;
                pre[to] = now;
                if(!vis[to])
                {
                    vis[to] = true;
                    q.push(to);
                }
            }
        }
    }
}
void out(int q)
{
    if(pre[q]!=0)
        out(pre[q]);
    printf("%d->",q);
    return;
    if(pre[q])
        out(pre[q]);
    else
    {
        if(q == n)
            printf("circuit : 1->1");
        else
            printf("circuit : 1");

        return;
    }
    if(q == n)
        q = 1;
    printf("->%d", q);
}
int main()
{
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; t++)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i)
            scanf("%d", &value[i]);
        n++;
        value[n] = 0;
        for(int i = 1; i <= n; i++)
        	head[i] = 0;
	   	len = 1;
        int m;
        scanf("%d", &m);
        int a, b;
        for(int i = 1; i <= m; i++)
        {
            scanf("%d %d", &a, &b);
            addNode(a, b);
        }
     
        spfa();
        printf("CASE %d#\n", t);
        printf("points : %d\n", dis[n]);
        printf("circuit : ");
        out(pre[n]);
        printf("1\n");
        if(t < T)
            printf("\n");
    }
    return 0;
}