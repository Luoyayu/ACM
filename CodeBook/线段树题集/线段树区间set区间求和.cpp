//例just a hook,区间重置，区间求和
#include<cstdio>
#include<cstring>
using namespace std;
#define lson (i<<1)
#define rson (i<<1|1)
const int maxn=100100;
int sum[maxn*4];
int setv[maxn*4];

void maintain(int i)
{
    sum[i]=sum[lson]+sum[rson];
}

void pushdown(int i,int num)
{
    int &t=setv[i];
    if(t)
    {
        setv[lson]=setv[rson]=t;
        sum[lson]=(num-(num>>1))*t;
        sum[rson]=(num>>1)*t;
        t = 0;
    }
}

void build(int i,int l,int r)
{
    setv[i]=0;
    sum[i]=1;
    if(l==r) return ;
    int M=(l+r)>>1;
    build(lson,l,M);build(rson,M+1,r);
    maintain(i);
}

void update(int ql,int qr,int val,int i,int l,int r)
{
    if(ql<=l&&qr>=r)
    {
        setv[i]=val;
        sum[i]=val*(r-l+1);
        return ;
    }
    pushdown(i,r-l+1);
    int M=(r+l)>>1;
    if(ql<=M) update(ql,qr,val,lson,l,M);
    if(qr>M) update(ql,qr,val,rson,M+1,r);
    maintain(i);
}

int query(int ql,int qr,int i,int l,int r)
{
    if(ql<=l&&qr>=r) return sum[i];
    pushdown(i,r-l+1);
    int ret=0;
    int M=(l+r)>>1;
    if(ql<=M)  ret+=query(ql,qr,lson,l,M);
    if(qr>M) ret+=query(ql,qr,rson,M+1,r);
    return ret;
}


int main()
{
    int t;
    scanf("%d",&t);
    for(int kase=1;kase<=t;kase++)
    {
        int n,q;
        scanf("%d%d",&n,&q);
        build(1,1,n);
        while(q--)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            update(x,y,z,1,1,n);
        }
        printf("Case %d: The total value of the hook is %d.\n",kase,query(1,n,1,1,n));
    }
    return 0;
}
