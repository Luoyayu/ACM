#include <bits/stdc++.h>
using namespace std;
//树剖专题-03 HDU 5274 Dylans loves tree
//题意：带权树，两种操作(0,x,y) x权变为y; (1,x,y) 在路径 x->y 是否所有元素出现次数为偶数，是输出-1否则输出唯一的出现奇数次的值

//树链剖分+异或+线段树成段更新
//trick：自然想到以前做过的一堆数有只有1个出现奇数，求出这个数使用连续异或就可以了

//此处异或满足区间减的性质，使用线段树维护
//注意如果路径上有3个零的话虽然异或值为0但是0还是出现了奇数次
//通过读入时点权+1输出-1即可
const int maxn = 100000+5;
int ecnt=0,head[maxn];
struct Edge{ int to,next;}e[maxn<<1];
void addedge2(int u,int v)
{
    e[ecnt]=Edge{v,head[u]};head[u]=ecnt++;
    e[ecnt]=Edge{u,head[v]};head[v]=ecnt++;
}
int siz[maxn],dep[maxn],fa[maxn],son[maxn],id[maxn];
int Top[maxn],cnt;//树链数据结构from 1

int Xor[maxn<<2];//区间异或值
int a[maxn], val[maxn];

void BuildRootTree(int u,int pre,int d)
{
    dep[u]=d;fa[u]=pre;siz[u]=1;
    for(int i=head[u];~i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==pre) continue;
        BuildRootTree(v,u,d+1);
        siz[u]+=siz[v];
        if(son[u]==-1 || siz[v]> siz[son[u]]) son[u] = v;
    }
}

void dfs(int u,int sp)
{
    Top[u]=sp;id[u]=cnt++;
    if(son[u]==-1) return ;
    dfs(son[u],sp);
    for(int i=head[u];~i;i=e[i].next)
    {
        int v = e[i].to;
        if(v!=son[u] && v!=fa[u]) dfs(v,v);
    }
}

void buildSegmentTree(int l,int r,int i)
{
    if(l==r) {Xor[i]=a[l];return;}
    int m = (l+r)>>1;
    buildSegmentTree(l,m,i<<1);
    buildSegmentTree(m+1,r,i<<1|1);
    Xor[i] = Xor[i<<1] ^ Xor[i<<1|1];//更新到父节点
}

void Update(int l, int r, int i,int pos,int value)
{
    if(l==r) {Xor[i]=value;return ;}
    int m = (l+r)>>1;
    if(pos<=m) Update(l,m,i<<1,pos,value);
    else Update(m+1,r,i<<1|1,pos,value);
    Xor[i] = Xor[i<<1]^Xor[i<<1|1];
}

int query(int l,int r,int i,int L,int R)
{
    if(L<=l && r<=R) return Xor[i];
    int m=(l+r)>>1, ans=0;
    if(L<=m) ans^=query(l,m,i<<1,L,R);
    if(m<R) ans^=query(m+1,r,i<<1|1,L,R);
    return ans;
}
int ret(int u, int v)
{
    int top_u = Top[u], top_v = Top[v], ans = 0;
    while(top_u!=top_v)
    {
        if(dep[top_u]<dep[top_v]) //保证 u处于较深的位置
            swap(top_u,top_v),swap(u,v);
        ans^=query(1,cnt,1,id[top_u],id[u]);//id[u]在id[top_u] 下面
        u=fa[top_u], top_u=Top[u];
    }
    //if(id[u]>id[v]) swap(id[u],id[v]);
    if(dep[u]>dep[v]) swap(u,v);//u ,v 在同一条连上保持 u在v上方
    ans^=query(1,cnt,1,id[u],id[v]);
    return ans;
}
void init()
{
    cnt = 1, ecnt=0;
    memset(son,-1, sizeof(son));
    memset(head,-1, sizeof(head));
}
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n,q;init();scanf("%d%d",&n,&q);
        for(int i=1;i<n;i++)
        {
            int u,v;scanf("%d%d", &u,&v);
            addedge2(u,v);
        }
        for(int i=1;i<=n;i++) scanf("%d",&val[i]);
        BuildRootTree(1,0,1);dfs(1,1);
        for(int i=1;i<=n;i++) a[id[i]]=val[i]+1;//待处理数组
        buildSegmentTree(1,cnt,1);
        while(q--)
        {
            int op,x,y; scanf("%d%d%d",&op,&x,&y);
            if(op)
                printf("%d\n",ret(x,y)-1);
            else
                Update(1,cnt,1,id[x],y+1);
        }
    }
    return 0;
}