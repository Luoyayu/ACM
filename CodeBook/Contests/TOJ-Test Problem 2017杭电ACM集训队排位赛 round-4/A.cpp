#include<bits/stdc++.h>
using namespace std;
int g[110][5];
bool vis[110][5];
#define clr(x,v) memset(x,v,sizeof(v));
bool dfs(int x,int y)
{
    vis[x][y] = 1;
    if(x==100&&y==0) return 1;


    if(!g[x+1][y] && !vis[x+1][y])
        dfs(x+1,y);

    if(!g[x+1][y+1]&&!g[x+2][y+2]&&!g[x+3][y+1]&&!g[x+4][y]&&!vis[x+4][y])
        dfs(x+4,y);
    //return 0; 加了就只执行一遍
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int x,y;
        clr(vis,0);clr(g,0);
        for(int i=0;i<n;i++)
            scanf("%d %d",&x,&y),g[x][y] = 1;
        printf("%d\n",dfs(0,0)? 1 : 0);
    }
    return 0;
}
