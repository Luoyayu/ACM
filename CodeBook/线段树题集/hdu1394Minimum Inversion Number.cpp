#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=5005;
//最小反转数：序列中ai,aj(i<j&&ai<aj)的对数
//描述：对于一个数列，可以把第n个数按需要移到序列末尾
//输入做小反转数值
//利用线段树求逆序数
#define Ls i<<1
#define Rs i<<1|1
#define lson Ls,l,M
#define rson Rs,M+1,r
int s[maxn<<2];
int tree[maxn<<2];
void maintain(int i)
{
    tree[i]=tree[Ls]+tree[Rs];
}
void build(int i,int l,int r)
{
    if(l==r)
    {
        tree[i]=0;
        return;
    }

    int M=(l+r)>>1;
    build(lson),build(rson),maintain(i);
}
void update(int pos,int i,int l,int r)
{
    if(l==r)
    {
        tree[i]=1;
        return;
    }
    int M=(l+r)>>1;
    if(pos<=M) update(pos,lson);
    else update(pos,rson);
    maintain(i);
}
int query(int ql,int qr,int i,int l,int r)
{
    if(ql<=l&&qr>=r)
        return tree[i];
    int M=(l+r)>>1;
    int ans=0;
    if(ql<=M) ans+=query(ql,qr,lson);
    if(qr>r) ans+=query(ql,qr,rson);
    return ans;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        build(1,1,n);
        int sum=0;

        for(int i=0;i<n;i++)
        {
            scanf("%d",&s[i]);
            sum+=query(s[i]+1,n,1,1,n);
            update(s[i]+1,1,1,n);
        }
        int MIN=sum;
        for(int i=0;i<n;i++)
        {
            sum=sum-2*s[i]+n-1;
            MIN=min(MIN,sum);
        }
        printf("%d\n",MIN);
    }
    return 0;
}
