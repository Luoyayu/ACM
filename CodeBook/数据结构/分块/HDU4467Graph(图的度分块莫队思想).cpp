#include<bits/stdc++.h> //for G++
using namespace std;
#define y2 Y2
#define next Next;
#define lowbit(x) x&(-x)
#define IOS std::ios::stdio(flase)
#define clr(x,num) memset(x,num,sizeof(x));
#define Debug(x) cout<<#x<<" = "<<x<<endl;
typedef long long ll;
typedef __int64 LL;
const int maxn = 1e5 + 7;
const int maxc = 1e3 + 5;
const int maxr = 1e5 + 5;
const int MOD  = 1e9 + 7;
const int inf  = 0x3f3f3f3f;
const double esp = 1e-6;
const double pi = acos(-1);
/*op1:change(i) op2:getsum(i,j) 获取两个终点为(i,j)色的所有可能路径权和
* 朴素做法O(n*m) ans[0,1,2]维护00 01 11这样的边 单点修改一次修改与之相邻的点的ans
* 莫队改进复杂度(0.5*n*sqrt(m))
* 思想:设lim=sqrt(m)如果一个点的度大于lim的设为重点,小于为轻点,轻点暴力维护,重点将他周围的权值用sum[i][j]维护
* 表示i这个重点yu他周围的j这个颜色的权值和,每次修改重点时,直接再三个ans上对sum数组操作,当修改轻点时注意维护重点.
*/
int deg[maxn],sp[maxn],type[maxn],g[maxn][2],v[maxn<<2],nxt[maxn],ed,sqr;
ll ans[3],w[maxn<<2],sum[maxn][2];//sp为重点,type为当前类型,w边权
struct Edge
{
    int u,v;
    ll w;
    bool operator<(const Edge &b)const //将所有的边按起点<=>终点大小排序
    {
        if(u==b.u) return v<b.v;
        return u<b.u;
    }
}edge[maxn];
inline void add(int type,int x,int y,ll z)
{
    v[++ed]=y,w[ed]=z,nxt[ed]=g[x][type],g[x][type]=ed;
}
int main()
{
    int kase=1,n,m,x;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=1;i<=n;i++)
            scanf("%d",&x),type[i]=x;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%lld",&edge[i].u,&edge[i].v,&edge[i].w);
            if(edge[i].u>edge[i].v) swap(edge[i].u,edge[i].v);//确保从小指向大点
        }
        sort(edge,edge+m);

        int cnt=0;//去重合并
        for(int i=0,j;i<m;i=j)
        {
            for(j=i+1;j<m && edge[i].u==edge[j].u && edge[i].v==edge[j].v; j++)
                edge[i].w += edge[j].w;
            edge[cnt++]=edge[i];
        }

        sqr = int (sqrt(cnt<<1));
        memset(deg,0,sizeof deg);
        for(int i=0;i<cnt;i++)
            deg[edge[i].u]++,deg[edge[i].v]++;

        for(int i=1;i<=n;i++)
            sp[i]=(deg[i]>=sqr);

        memset(g,0,sizeof g);
        ed = 0;
        for(int i=0;i<cnt;i++)
        {
            int x = edge[i].u, y = edge[i].v;ll w = edge[i].w;
            if(sp[x]) add(1,y,x,w);else add(0,x,y,w);
            if(sp[y]) add(1,x,y,w);else add(0,y,x,w);
        }
        memset(ans,0,sizeof ans);
        memset(sum,0,sizeof sum);
        for(int i=0;i<cnt;i++)
        {
            int x = edge[i].u, y = edge[i].v;ll w = edge[i].w;
            if(sp[x]) sum[x][type[y]]+=w;
            if(sp[y]) sum[y][type[x]]+=w;
            ans[type[x]+type[y]]+=w;
        }
        int q;scanf("%d",&q);
        printf("Case %d:\n",kase++);
        while(q--)
        {
            int a,b;char s[20];
            scanf("%s",s);
            if(s[0]=='A') scanf("%d%d",&a,&b),printf("%lld\n",ans[a+b]);
            else//modify
            {
                scanf("%d",&x);
                type[x]^=1;
                if(sp[x])//修改重点
                {
                    for(int i=0;i<=1;i++)
                    {
                        ans[(type[x]^1)+i]-=sum[x][i];
                        ans[type[x]+i]+=sum[x][i];
                    }
                }
                else//暴力修改轻点
                {
                    for(int i=g[x][0];i;i=nxt[i])
                    {
                        ans[(type[x]^1)+type[v[i]]]-=w[i];
                        ans[type[x]+type[v[i]]]+=w[i];
                    }
                }
                for(int i=g[x][1];i;i=nxt[i])//更新重点的sum
                {
                    sum[v[i]][type[x]^1]-=w[i];
                    sum[v[i]][type[x]]+=w[i];
                }
            }
        }
    }
    return 0;
}
