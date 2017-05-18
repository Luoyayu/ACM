//数据的离散化/逆序数和==swap次数
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef __int64 ll;
const int maxn=1000005;
ll c[maxn];int n;
struct node {ll x,index;}s[maxn];
bool cmp(node a,node b) {return a.x<b.x;}
ll lowbit(int x) {return x&(-x);}
void add(ll x,ll d) {while(x<=n) c[x]+=d,x+=lowbit(x);}
ll sum(int x) {ll ret=0;while(x) ret+=c[x],x-=lowbit(x);return ret;}
int main()
{
    while(~scanf("%d",&n))
    {
        memset(c,0,sizeof c);
        for(ll i=1;i<=n;i++)
            scanf("%I64d",&s[i].x),s[i].index=i;//记录x对应的索引
        sort(s+1,s+n+1,cmp);//将有序数列索引与原数列索引对比
        ll ret=0;//交换次数
        for(ll i=1;i<=n;i++)
            add(s[i].index,1),ret+=i-sum(s[i].index),printf("%d\n",ret);//sum(i)表示比i小的个数，i-sum(i)即表示比i大的个数
        printf("%I64d\n",ret);
    }
    return 0;
}



















