//染色
#include<cstdio>
#include<queue>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 100000+10;
vector<int> G[maxn];
int acnt,bcnt,n,m;
int col[maxn];

void init(int n)
{
	for(int i=1;i<n;i++)
		G[i].clear();
}

int bi_bfs(int st)
{
	queue<int> q;
	q.push(st);
	col[st]=1;//染色开始 
	while(!q.empty())
	{
		st=q.front();
		q.pop();
		if(col[st]==1) acnt++;
			else bcnt++; 
		for(int i=0;i<G[st].size();i++)
		{
			if(col[G[st][i]]==-1)
			{
				col[G[st][i]]=!col[st];
				q.push(G[st][i]);
				continue;
			}
		 if(col[G[st][i]]==col[st]) 
		 	return false;
		}
	}
	return true;
}
void solve()
{
	memset(col,-1,sizeof col);//全部染-1色 
	bool flag=false; 
	int Max=0;
	for(int i=1;i<=n;i++)
	{
		acnt = bcnt=0;
		if(col[i]==-1&&!bi_bfs(i))
		{
			flag=true;
			break;
		}
		Max+=max(acnt,bcnt);//贪心，每次加入最多的	
	}
	if(!flag)
		printf("%d %d\n",Max,n-Max);
	else
		printf("Poor wyh\n");
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b;
		scanf("%d%d",&n,&m);
		init(n);
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&a,&b);
			G[a].push_back(b);
			G[b].push_back(a);
		}
		if(n<2) //特例 
		{
			printf("Poor wyh\n");
			continue;
		}
		if(m==0) 
		{
			printf("%d 1\n",n-1);
			continue;
		}	
		solve();	 
	}
	return 0;
} 