#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
using namespace std;
const int maxn=500+10;
struct MMatch
{
	int n;
 	vector<int> g[maxn];
 	bool vis[maxn];
 	int left[maxn];
 	
	void init(int n)
	{
		this->n = n;
		for(int i=0;i<n;i++)
			g[i].clear();
		memset(left,-1,sizeof left);
	}
	bool match(int u)
	{
		for(int i=0;i<g[u].size();i++)
		{
			int v=g[u][i];
			if(!vis[v])
			{
				vis[v]=true;
				if(left[v]==-1||match(left[v])) 
				{
					left[v]=u;
					return true;
				}
			}
		}
		return false;
	}
	
	int solve()
	{
		int ans=0;
		for(int i=0;i<n;i++)
		{
			memset(vis,0,sizeof vis);
			if(match(i)) ans++;
		}
		return ans;
	}
}Match;

int main()
{
	int n,u,v,num;
	while(scanf("%d",&n)==1)
	{
		Match.init(n);
		for(int i=0;i<n;i++)
		{
			scanf("%d: (%d)",&u,&num);
			for(int i=0;i<num;i++)
			{
				scanf("%d",&v);
				Match.g[u].push_back(v);
			}
		}
		printf("%d\n",n-Match.solve()/2);
	}
	return 0;	
}