#include<bits/stdc++.h>
using namespac std;
// 题意:每把武器有两个属性且只能使用一次,攻击属性必须从1开始连续递增
//求最大连击数
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
const int maxn = 1000000+7;
int par[maxn];
int rank[maxn];
int vis[maxn];
int find(int x)
{
    if(x==par[x] return x;
    return par[x]=find(par[x]);
}
void unite(int x,int y)
{
    x = find(x), y = find(y);
    if(x==y)return ;
    if(rank[x]<rank[y])
        par[x]=y;
    else{
        par[y]=x;
        if(rank[x]==rank[y]) rank[x]++;
    }
    return ;
}
int main()
{
    int n = read();
    
    for(int i=0;i<n;i++)
    {
        int x=read(),y=read();
        int fx = find(x), fy = find(fy);
        if(fx==fy) 
    }
    int ans = 1;
    for(int i=1;i<=maxn;i++)
        if()
}