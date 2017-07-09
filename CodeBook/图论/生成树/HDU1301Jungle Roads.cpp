//回顾无向连通图的最小生成树
//prim算法实现 G=<V,E> 生成<S,T>3
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

                scanf("%c %d ",&tmp,&cost);
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
