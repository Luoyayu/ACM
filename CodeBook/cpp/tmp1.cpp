#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
const int inf =0x3f3f3f3f;
const int N=1111;
struct node
{
	int to,cap,rev;
};
bool used[N];
vector <node> v[N];
void addnode(int from,int to,int cap)
{
	v[from].push_back((node){to,cap,v[to].size()});
	v[to].push_back((node){from,0,v[from].size()-1});
}
int bfs(int s,int t,int f)
{
	if(s==t) return f;
	used[s]=true;
	for(int i=0;i<v[s].size();i++)
	{
		node &tmp=v[s][i];
		if(!used[tmp.to]&&tmp.cap>0)
		{
			int d=bfs(tmp.to,t,min(f,tmp.cap));
			if(d>0)
			{
				tmp.cap-=d;
				v[tmp.to][tmp.rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}
int max_flow(int s,int t)
{
	int flow=0;
	while(1)
	{
		memset(used,0,sizeof used);
		int f=bfs(s,t,inf);
		if(f==0) 
			return flow;
		flow+=f;
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int q=1;q<=t;q++)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		{
			memset(v,0,sizeof v);
			for(int i=0;i<m;i++)
			{
				int a,b,c;
				scanf("%d%d%d",&a,&b,&c);
				addnode(a,b,c);
			}
			printf("Case %d: \n",q,max_flow(1,n));
		}
	}
	return 0;
}
