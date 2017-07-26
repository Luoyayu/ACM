//数据的离散化/逆序数和==swap次数
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
#define lowbit(x) x&(-x)
const int maxn=1000005;
ll c[maxn];
int n;
struct node
{
    ll x,index;
}s[maxn];
bool cmp(node &a, node &b)
{
    return a.x<b.x;
}
inline void add(ll x,ll d)
{
    while(x<=n)
        c[x]+=d,x+=lowbit(x);
}
ll sum(ll x)
{
    ll ret=0;
    while(x)
         ret+=c[x],x-=lowbit(x);
    return ret;
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        //ll k;scanf("%lld",&k);
        memset(c,0,sizeof c);
        for(ll i=1;i<=n;i++)
        {
            scanf("%lld",&s[i].x);
            s[i].index=i;//记录x对应的索引
        }
        sort(s+1,s+n+1,cmp);//将有序数列索引与原数列索引对比

        ll ret=0;//交换次数
        for(ll i=1;i<=n;i++)
        {
            add(s[i].index,1);
            ret+=i-sum(s[i].index);//sum(i)表示比i小的个数，i-sum(i)即表示比i大的个数
        }
        //if(ret==k) ret=k;
        printf("%lld\n",ret);
    }
    return 0;
}



















