#include<set>
#include<map>
#include<stack>
#include<cmath>
#include<queue>
#include<vector>
#include<cctype>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<sstream>
#include<iostream>
#include<algorithm>
#define rep(i,a,b) for(i=a;i<=b;i++)
#define rec(i,a)   for(i=0;i< a;i++)
#define N 50000  +  10
#define Q 1000   +  10
#define P 100    +  1
#define lson left,mid,i<<1
#define rson mid+1,right,i<<1|1
using namespace std;
int a[N]={0};
struct point
{
    int left;
    int right;
    int sum;
};
point tree[N<<2];
void build (int left,int right,int i)
{
	tree[i].left=left;
	tree[i].right=right;
	if(left==right)
	{
		tree[i].sum = a[left];return ;
	}
	int mid  = (left+right)>>1;
	build(lson);
	build(rson);
	tree[i].sum = tree[i<<1].sum+tree[i<<1|1].sum;
}
void update(int x,int number,int i)
{
	if(tree[i].left==tree[i].right)
	{
		tree[i].sum += number;return ;
	}
	int mid   = (tree[i].left+tree[i].right)>>1;
	if(x<=mid)update(x,number,i<<1);
	else update(x,number,i<<1|1);
	tree[i].sum = tree[i<<1].sum + tree[i<<1|1].sum;
}
int query(int left,int right,int i)
{
	if(left==tree[i].left&&right==tree[i].right)
	{
		return tree[i].sum;
	}
	int mid  = (tree[i].left+tree[i].right)>>1;
	if(mid<left)return query(left,right,i<<1|1);
	else if(right<=mid)return query(left,right,i<<1);
	else return (query(left,mid,i<<1)+query(mid+1,right,i<<1|1));
}
int main()
{
    int T;
    int n;
    int i,j;
    int x,y;
    char uc[P]={0};
    scanf("%d",&T);
    for(int cnt=1;cnt<=T;cnt++)
    {
        printf("Case %d:\n",cnt);
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        scanf("%d",&a[i]);

        build(1,n,1);
        while(scanf("%s",uc)==1)
        {
            if(strcmp(uc,"End")==0)break;
            scanf("%d%d",&x,&y);
            if(uc[0]=='Q')printf("%d\n",query(x,y,1));
            else if(uc[0]=='A')update(x,y,1);
            else if(uc[0]=='S')update(x,-y,1);
            memset(uc,0,sizeof uc);
        }

        memset(a,0,sizeof a);
        memset(tree,0,sizeof tree);

    }
return 0;
}
