//活用并查集处理不相交集合
//题意：给出加权无向图，每次查询给出一个限制删除边权大于该值的边求剩余的点对数注意(a,b)与(b,a)是不同的点对
//思想：离线化操作忍耐值大的包含小的 + 集合贡献思想
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,Q;
const int maxn=20000+7;
struct Edge
{
    int u,v,w;
    bool operator <(const Edge &a)const//对于边权降序排列
    {
        return w<a.w;
    }
}edge[maxn*5];
int num[maxn],F[maxn],ANS[maxn];
struct Query
{
    int x,id;
    bool operator <(const Query& a)const//对于查询降序排列
    {
        return x<a.x;
    }
}q[maxn];

inline int find(int x)
{
    return F[x]==x?x:F[x]=find(F[x]);
}

inline void merge(int x,int y)
{
    if(find(x)!=find(y)) //如果不在同一集合中,挂上去
        F[y]=x,num[x]+=num[y];
}
inline void init()
{
    for(int i=1;i<=n;i++) //f[x]=x 
        F[i]=i,num[i]=1;//初始化每个点孤立为一个包含一个点的集合
}

int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int ans=0;
        scanf("%d%d%d",&n,&m,&Q);
        init();
        for(int i=0;i<m;i++)
            scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
        for(int i=0;i<Q;i++)
            scanf("%d",&q[i].x),q[i].id=i;
        sort(edge,edge+m);
        sort(q,q+Q);
        int j=0;
        for(int i=0;i<Q;i++)//对于有序查询 i ans 只能越来越大因为要扩展这个大集合
        {
            while(j<m&&edge[j].w<=q[i].x)
            {
                int fu = find(edge[j].u);
                int fv = find(edge[j].v);
                j++;
                if(fu==fv) continue;//不是同一集合的纳入
                ans+=(num[fu]+num[fv])*(num[fu]+num[fv]-1)-num[fu]*(num[fu]-1)-num[fv]*(num[fv]-1);//加上新的贡献
                merge(fu,fv);//并查集扩展总体集合
            }
            ANS[q[i].id]=ans;
        }
        for(int i=0;i<Q;i++)
            printf("%d\n",ANS[i]);
    }
    return 0;
}