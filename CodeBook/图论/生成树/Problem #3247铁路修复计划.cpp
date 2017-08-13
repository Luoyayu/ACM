//二分答案+最小生成树
#include <cstdio>
#include <algorithm>
#include <cstring>
const int maxn=100000+5;
const double eps=1e-7;
using namespace std;
struct node
{
    bool type;
    int u,v,cost;
    double w;
}edge[maxn];
bool cmp(node &a,node &b)
{return a.w<b.w;}

int n,m,F[maxn];
double M;

inline int find(int x)
{return F[x]==x?x:F[x]=find(F[x]);}
void unite(int x,int y)
{
    x=find(x);y=find(y);
    if(x==y) return ;
    F[y]=x;
}
bool kurskal()
{
    int cnt=0;double sum=0;
    for(int i=1;i<=n;i++)F[i]=i;
    for(int i=1;i<=m;i++)
    {
        int x=find(edge[i].u),y=find(edge[i].v);
        if(x!=y)
        {
            unite(x,y);
            sum+=edge[i].w;
            if(++cnt==n-1) break;
        }
    }
    if(sum>M) return 0;
    return 1;
}
 bool check(double k)
{
    for(int i=1;i<=m;i++)
    {
        if(edge[i].type==1)
            edge[i].w=k*edge[i].cost;
        else
            edge[i].w=1.0*edge[i].cost;
    }
    sort(edge+1,edge+m+1,cmp);
    return kurskal();
}
int main()
{
    scanf("%d%d%lf",&n,&m,&M);
    for(int i=1;i<=m;i++)
        scanf("%d%d%d%d",&edge[i].u,&edge[i].v ,&edge[i].cost ,&edge[i].type);
    double ST=0,ED=1e15+5,Mid;
    while(ED-ST>eps)
    {
        Mid=ST+(ED-ST)/2.0;
        if(check(Mid)) ST=Mid;
        else
            ED=Mid;
    }
    printf("%.6lf\n",ST);
    return 0;
}
