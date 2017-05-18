//暴搜
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char g[5][5];
bool vis[5][5];
int ans,n;
bool check(int &x,int &y)
{
    return !(x < 0 || x >= n || y < 0 || y >= n);
}
 bool recheck(int x,int y)
 {
     if(g[x][y]=='X'||vis[x][y]) return false;
     //up
     for(int i=y;check(x,i);i++)
     {
         if(g[x][i]=='X') break;
         if(vis[x][i]) return false;
     }
     //down
     for(int i=y;check(x,i);i--)
     {
         if(g[x][i]=='X') break;
         if(vis[x][i]) return false;
     }
     //right
     for(int i=x;check(i,y);i++)
     {
         if(g[i][y]=='X') break;
         if(vis[i][y]) return false;
     }
     //left
     for(int i=x;check(i,y);i--)
     {
         if(g[i][y]=='X') break;
         if(vis[i][y]) return false;
     }
     return true;
 }

void dfs(int num)
{
    ans=max(ans,num);
    for(int i=0;i<n;i++) //对每个点深搜
        for(int j=0;j<n;j++)
            if(recheck(i,j))//如果该点的上下左右可行
            {
                vis[i][j]=1;//标记为已访问
                dfs(num+1);//
                vis[i][j]=0;
            }
}
int main()
{
    while (scanf("%d",&n)!=EOF,n)
    {
        ans=0;
        for(int i=0;i<n;i++)
        {
            scanf("%s",g[i]);
            getchar();
        }
        memset(vis,0, sizeof(vis));
        dfs(0);
        printf("%d\n",ans);
    }
    return 0;
}

