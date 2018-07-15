#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<sstream>
#include<cstring>
#include<cstdio>
#include<string>
#include<deque>
#include<stack>
#include<cmath>
#include<queue>
#include<set>
#include<map>
#define INF 0x3f3f3f3f
#define MM(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

const int N=100000/2.0;
int t,s,D;
vector<pii>vec[N];
int d[N];
vector<int>des;
vector<int>start;

void init()
{
	for (int i=0; i<N; i++)
		vec[i].clear();
	memset(d,INF,sizeof(d));
	start.clear();
	des.clear();
}
void dij(int x,int y)
{
	int i;
	d[x]=0;
	priority_queue<pii>Q;
	Q.push(pii(-d[x],x));
	while (!Q.empty())
	{
		int now=Q.top().second;
		Q.pop();
		for (i=0; i<vec[now].size(); i++)
		{
			int v=vec[now][i].first;
			if(d[v]>d[now]+vec[now][i].second)
			{
				d[v]=d[now]+vec[now][i].second;
				Q.push(pii(-d[v],v));
			}
		}
	}
}
int main(void)
{
	int i,j;
	int tmp;
	while (~scanf("%d%d",&tmp,&t))
	{
		init();
		int a,b,time;
		for (i=0; i<t; i++)
		{
			scanf("%d%d%d",&a,&b,&time);
			vec[a].push_back(pii(b,time));
		}
		int st,sd;
		scanf("%d",&s);
		for (i=0; i<s; i++)
		{
			scanf("%d",&st);
			start.push_back(st);
		}
		scanf("%d",&D);
		for (i=0; i<D; i++)
		{
			scanf("%d",&sd);
			des.push_back(sd);
		}
		int mt=INF;
		for (i=0; i<s; i++)
		{
			int S=start[i];
			for (j=0; j<D; j++)
			{
				int e=des[j];
				dij(S,e);
				mt=min(mt,d[e]);
			}
		}
		printf("%d\n",mt);
	}
	return 0;
}
