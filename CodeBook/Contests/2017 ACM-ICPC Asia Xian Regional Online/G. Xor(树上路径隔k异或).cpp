#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
#define clr(a,b)   memset(a,b,sizeof(a));
const int maxn = 5e4+5;
struct Edge{int to,next;}e[maxn<<1];
int head[maxn], ecnt;
int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void addedge2(int u,int v)
{
    e[ecnt]=Edge{v,head[u]};head[u]=ecnt++;
    e[ecnt]=Edge{u,head[v]};head[v]=ecnt++;
}

int dep[maxn],anc[maxn][233];//第k级祖先
int cnt;//new struct
int siz[maxn],son[maxn],top[maxn],tid[maxn],fid[maxn];
int val[maxn],Xor[maxn][233];

void build(int u,int pre,int d)//建立有根树,构造siz,dep,anc,son
{
    int tmpsz=0, maxszid=0;
    siz[u]=1; dep[u]=d; anc[u][1]=pre;
    for(int i=head[u],v;~i;i=e[i].next)
    {
        if((v=e[i].to)==pre) continue;
        build(v, u, d+1);
        siz[u]+=siz[v];
        if(siz[v]>tmpsz)
            tmpsz=siz[maxszid=v];
    }
    son[u]=maxszid;
}
int n,m,q; //m=int(sqrt(n+0.5));
void dfs(int u, int sp)//树剖 构造 id,fid,Top
{
    top[u]=sp;tid[u]=++cnt;
    fid[cnt]=u;
    for(int i=1;i<=m;i++)//从u跳i级步,直到根节点的异或值
        Xor[u][i] = Xor[anc[u][i]][i]^val[u];
    if(son[u]) dfs(son[u], sp);
    for(int i=head[u],v;~i;i=e[i].next)
    {
        if((v=e[i].to)==anc[u][1] || v==son[u]) continue;
        dfs(v,v);
    }
}
int retLCA(int x,int y)//由重链求出推出lca
{
    for(;top[x]!=top[y];dep[top[x]]>dep[top[y]]?x=anc[top[x]][1]:y=anc[top[y]][1]);
    return dep[x]<dep[y]?x:y;
}

int Jump(int x,int k)//从x向上跳k步返回x的k级祖先
{
    if(dep[x]<=k) return 0;//一条链上dep(x)==dis(x,root)
    int y=top[x],DIS;
    while(x && k>=(DIS=(dep[x]-dep[y]+1)))
    {
        k-= DIS;
        x=anc[y][1],y=top[x];
    }
    if(x==0) return 0;
    return fid[tid[x]-k];

}

int RET(int x,int lca,int k)//返回(x,lca,k)的连续异或
{
    int ret = 0;
    if(dep[x]<=dep[lca]) return 0;
    if(k<=m) //直接跳到
    {
        ret ^= Xor[x][k];
        while(dep[x]>dep[lca])
            x = Jump(x, k);
        return ret ^ Xor[x][k];
    }

    ret ^= val[x];
    while(dep[x]>dep[lca]+k)
    {
        x=Jump(x,k);
        ret ^= val[x];
    }
    return ret;
}
inline void init()
{
    clr(head,-1);clr(Xor,0);
    cnt=ecnt=0;
}
int main()
{
    while(scanf("%d%d",&n,&q)!=EOF)
    {
        m = (int)sqrt(n+0.5);
        init();
        for(int i=1;i<n;i++)
            addedge2(read(),read());
        for(int i=1;i<=n;i++) val[i]=read();
        build(1,0,1);

        for(int i=1;i<=n;i++)
            for(int j=2;j<=m;j++)
                anc[i][j] = anc[anc[i][j-1]][1];
        dfs(1,1);
        while(q--)
        {
            int u=read(),v=read(),k=read();
            int LCA = retLCA(u,v);
            int dis = dep[u]+dep[v]-2*dep[LCA];
            int ans = RET(u,LCA,k);//把(u,v)分成两条链(u,LCA,v)
            ans ^= RET(dis%k?Jump(v,dis%k):v, LCA, k);
            printf("%d\n",(dep[u]-dep[LCA])%k==0?ans^val[LCA]:ans);//去掉LCA重复异或
        }
    }
    return 0;
}