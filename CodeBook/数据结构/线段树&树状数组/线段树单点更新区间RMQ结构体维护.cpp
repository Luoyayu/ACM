//线段树单点更新+RMQ
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=200005;
const int inf=0x3f3f3f3f;
#define lson (i<<1)
#define rson (i<<1|1)
struct node
{
    int l,r,MAX,SUM,MIN;
}tree[4*maxn];//总结点数2^(h+1)-1
int A[maxn];
void maintain(int i)//维护信息
{
    tree[i].MAX=max(tree[lson].MAX,tree[rson].MAX);
    tree[i].MIN=min(tree[lson].MIN,tree[rson].MIN);
    tree[i].SUM=tree[lson].SUM+tree[rson].SUM;
}
void build(int i,int L,int R)
{
    tree[i].l=L,tree[i].r=R;
    tree[i].MAX=tree[i].SUM=tree[i].MIN=0;
    if(L==R)
    {
        int tmp;
        scanf("%d",&tmp);
        tree[i].MAX=tree[i].SUM=tree[i].MIN=tmp;
        return ;
    }
    int M=(L+R)>>1;
    build(lson,L,M);
    build(rson,M+1,R);
    maintain(i);
}
void update(int i,int p,int v)
{
    int L=tree[i].l,R=tree[i].r;
    int M=(L+R)>>1;
    if(L==R && L==p)
    {
        tree[i].MAX=v;
        tree[i].SUM+=v;
        return ;
    }
    if(M>=p)//update left-son
        update(lson,p,v);
    else//update right-son
        update(rson,p,v);
    maintain(i);
}
int query(int i,int l,int r)
{
    int L=tree[i].l,R=tree[i].r;
    if(l<=L && R<=r)
        return tree[i].SUM;
    int M=(L+R)>>1,_max=0,_sum=0,_min=0;
    if(M<r) _max=query(rson,l,r),_sum+=query(rson,l,r);
    if(M>=l) _max=max(_max,query(lson,l,r)),_sum+=query(lson,l,r);
    return _sum;
}
int main()
{
    int n,m,kase=1;;
    scanf("%d",&m);
    while(m--)
    {
        printf("Case %d:\n",kase++);
        scanf("%d",&n);
        char op[10];
        build(1,1,n);
        while(cin>>op)
        {
            if(op[0]=='E') break;
            int x,y;
            scanf("%d%d",&x,&y);
            if(op[0]=='A') update(1,x,y);
            if(op[0]=='S') update(1,x,-y);
            if(op[0]=='Q')printf("%d\n",query(1,x,y));
        }

    }
    return 0;
}
