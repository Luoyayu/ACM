//回顾无向连通图的最小生成树
//prim算法实现 G=<V,E> 生成<S,T>
//思想:随机加入s1,再不停的加入一端在S，一端在V集合的最小边直到S集合==V集合
//二叉堆优化复杂度O(E*logV) 不建议使用prim
#include<bits/stdc++.h>
using namespace std;
#define clr(a,b) memset(a,b,sizeof(a));
const int maxn =30;
const int inf = 0x3f3f3f3f;
int g[maxn][maxn];
bool vis[maxn];
int d[maxn];
int main()
{
    int n,m,cost,tmp;
    while(scanf("%d",&n)!=EOF,n)
    {
        int sum = 0;
        clr(d,0);clr(vis,1);clr(g,0x3f);
        for(int i=1;i<n;i++)
        {
            getchar();
            char ori,tmp;
            scanf("%c %d",&ori,&m);
            while(m--)
            {
                scanf("%c %c %d ",&tmp,&tmp,&cost);
                g[tmp-'A'][ori-'A'] = g[ori-'A'][tmp-'A'] = cost;
            }
        }
        for(int i=1;i<n;i++)
            d[i]=g[i][0];
        vis[0]=0;
        for(int i=1;i<n;i++)
        {
            int minn=inf;
            for(int j=1;j<n;j++)
                if(vis[j]&&d[j]<minn)
                {
                    minn = d[j];
                    tmp = j;
                }
            vis[tmp] = false;
            sum += minn;
            for(int j=0;j<n;j++)
            if(vis[j]&&d[j]>g[j][tmp])
                d[j]=g[j][tmp];
        }
    printf("%d\n",sum);
    }
    return 0;
}

//改写Kruskal算法
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<string>
using namespace std;
#define clr(a,b) memset(a,b,sizeof (a))
const int MAXn=110;//最大边数
const int MAXm=1000;//最大边数
int F[MAXn];//并查集
struct Edge
{
    int u,v,w;
} edge[MAXm];
int tot;
void addedge(int u,int v,int w)
{
    edge[tot].u=u;
    edge[tot].v=v;
    edge[tot++].w=w;
}
bool cmp(Edge a,Edge b)
{
    return a.w<b.w;
}
int find(int x)
{
    if(F[x]==-1) return x;
    else return F[x]=find(F[x]);
}
int Kruskal(int n)//顶点 个数
{
    memset(F,-1,sizeof F);
    sort(edge,edge+tot,cmp);
    int cnt=0;//加入边数
    int ans=0;//最小权值
     for(int i=0;i<tot;i++)
    {
         int u=edge[i].u;
         int v=edge[i].v;
         int w=edge[i].w;
         int f1=find(u);
         int f2=find(v);
         if(f1!=f2)
         {
             ans+=w;
             F[f1]=f2;
             cnt++;
         }
         if(cnt==n-1) break;
     }
     if(cnt<n-1) return -1;
     else return ans;
}
int main()
{
    int n,m,cost;
    while(scanf("%d",&n)!=EOF&&n)
    {
        tot=0;
        clr(F,-1);
        for(int i=1;i<n;i++)
        {
            getchar();
            char ori,tmp;
            scanf("%c %d",&ori,&m);
            while(m--)
            {
                scanf("%c %c %d",&tmp,&tmp,&cost);
                addedge(tmp-'A',ori-'A',cost);
                addedge(ori-'A',tmp-'A',cost);
            }
        }
        printf("%d\n",Kruskal(n));
    }
    return 0;
}

