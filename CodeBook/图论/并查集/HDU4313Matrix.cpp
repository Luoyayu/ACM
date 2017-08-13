//题意：给出无向图,和一些特点,找出最小代价使得特点们不相连
//划分树 用并查集合并
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include <iostream>
typedef long long ll;
using namespace std;
const int maxn = 1e5+7;
int F[maxn];
bool flag[maxn];
struct Edge
{
    int u,v,w;
}edge[maxn];
bool cmp(Edge &a,Edge &b)
{
    return a.w>b.w;
}

inline int find(int x)
{
    return F[x] = x == F[x] ? x : find(F[x]);
}

inline void merge(int a,int b)
{
    F[a] = b;
    if(flag[a]) flag[b]=1;
}
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n,m;
        memset(flag,0,sizeof flag);

        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++) F[i]=i;
        for(int i=1;i<n;i++)
            scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);

        for(int i=0;i<m;i++)
        {
            int d;scanf("%d",&d);
            flag[d]=1;
        }
        ll sum = 0;
        sort(edge,edge+n-1,cmp);//从大到小排

        for(int i=0;i<n-1;i++)
        {
            int u = edge[i].u, v = edge[i].v, w = edge[i].w;
            int fu=find(u), fv=find(v);
            //cout<<"find:"<<fu<<"  "<<fv<<endl;
            if(flag[fu]&&flag[fv])
            {
                sum+=w;
                continue;
            }
            merge(fu,fv);
        }
        printf("%lld\n",sum);
    }
    return 0;
}
