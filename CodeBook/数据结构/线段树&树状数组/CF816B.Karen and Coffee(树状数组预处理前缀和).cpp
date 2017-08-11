//菜啊,这么基础的前缀打标处理都没想到
#include<bits/stdc++.h>
using namespace std;
const int maxn =200000+7;
int ans[maxn];
int c[maxn];
#define lowbit(x) (x)&(-x)
void add(int pos, int val)
{
    while(pos<maxn)
    {
        c[pos]+=val;
        pos+=lowbit(pos);
    }
}
int sum(int pos)
{
    int res = 0;
    while(pos>0)
    {
        res += c[pos];
        pos-=lowbit(pos);
    }
    return res;
}
int main()
{
    int n,m,k;
    while(scanf("%d%d%d",&n,&m,&k)!=EOF)
    {
        memset(c,0,sizeof(c));
        memset(ans,0,sizeof(ans));
        for(int i=1;i<=n;i++)
        {
            int a,b;scanf("%d%d",&a,&b);
            add(a,1);add(b+1,-1);
        }
        for(int i=1;i<maxn;i++)
        {
            int tmp = sum(i);
            if(tmp>=m) ans[i] = ans[i-1] + 1;
            else ans [i] =ans[i-1];
        }
        while(k--)
        {
            int u,v;scanf("%d%d",&u,&v);
            printf("%d\n",ans[v]-ans[u-1]);
        }
    }
    return 0;
}
