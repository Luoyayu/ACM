#include<cstdio>
#include<cstring>
using namespace  std;
const int maxn=2333;
int father[maxn];
int Rank[maxn];
int n,m;
inline void init()
{
    for(int i=0;i<n;i++)
        father[i]=i,Rank[i]=1;
}
int find(int x)
{
    if(father[x]!=x)
        father[x]=find(father[x]);
    return father[x];
}
void merge(int x,int y)
{
    int fx=find(x);
    int fy=find(y);
    if(Rank[fx]>=Rank[fy])
        father[fy]=fx,Rank[fx]+=Rank[fy];
    else
        father[fx]=fy,Rank[fy]+=Rank[fx];
}
