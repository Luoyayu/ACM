//题意：给出无向图,和一些特点,找出最小代价使得特点们不相连
//划分树 用并查集合并
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include <iostream>

using namespace std;
const int maxn = 1e5+7;
int F[maxn];bool flag[maxn];
int tot=0;
struct Edge
{
    int u,v,w;
}edge[maxn];
void add(int u,int v,int w)
{
    edge[tot].u=u;
    edge[tot].v=v;
    edge[tot++].w=w;
}
bool cmp(Edge &a,Edge &b)
{
    return a.w>b.w;
}
int find(int x)
{
    return F[x] = x == F[x] ? x : find(F[x]);
}
void merge(int a,int b)
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
        tot=0;
        memset(flag,0,sizeof flag);

        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++) F[i]=i;
        for(int i=1;i<n;i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            add(a,b,c);
        }

        for(int i=0;i<m;i++)
        {
            int d;scanf("%d",&d);
            flag[d]=1;
        }
        long long sum = 0;
        sort(edge,edge+tot,cmp);
        for(int i=0;i<tot;i++)
        {
            int u = edge[i].u;
            int v = edge[i].v;
            int w = edge[i].w;
            int fu=find(u);
            int fv=find(v);
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
