
//并查集中每个元素形成一个节点,每一组对应一棵树,无关每棵树的内部结构,考虑作为整体的树形结构
//合并细节 1)从一棵树的根向另一组树的根连边形成一棵树,记录树的高度rank避免退化,
//合并时从rank小的向大的连边尽量保持小的高度 2)路径压缩 一个节点一旦从下往上找到祖先,
//就把这个点连向父亲的边改为连向祖先的边,还是尽可能的保持小的树的高度,路径压缩后树的rank值也没必要更改
#include <bits/stdc++.h>
using namespace  std;
const int maxn=2333;
int par[maxn];
#define rank RANK
int rank[maxn];
void init(int n)
{
    for(int i=0;i<n;i++)
        par[i]=i,rank[i]=0;
}
int find(int x)
{
    if(par[x]==x) return x;
    else return par[x]=find(par[x]);
}

void unite(int x,int y)
{
    x = find(x), y = find(y);
    if(x==y) return ;
    if(rank[x]<rank[y])
        par[x]=y;
    else
    {
        par[y]=x;
        if(rank[x]==rank[y]) rank[x]++;
    }
}
inline bool sameSet(int x,int y)
{
    return find(x) == find(y);
}
