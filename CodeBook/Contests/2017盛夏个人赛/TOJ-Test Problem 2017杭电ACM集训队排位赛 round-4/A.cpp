#include<bits/stdc++.h>
using namespace std;
int vis[110][110],mp[110][110];
int n,m;
int flag;
void dfs(int x,int y)
{
    if(x==100&&y==0)
    {
        flag=1;
        return ;
    }
        vis[x][y]=1;

    if(!mp[x+1][y]&&!vis[x+1][y])
		dfs(x+1,y);

    if(!mp[x+1][y+1]&&!mp[x+2][y+2]&&!mp[x+3][y+1]&&!mp[x+4][y]&&!vis[x+4][y])
		dfs(x+4,y);

}
int main()
{
    while(~scanf("%d",&n))
	{
	    flag=0;
        memset(mp,0,sizeof mp);
        memset(vis,0,sizeof vis);
        for(int i=0;i<n;i++)
		{
		    int x,y;
            scanf("%d%d",&x,&y);
            mp[x][y]=1;
        }
        dfs(0,0);
        printf("%d\n",flag?1:0);
    }
    return 0;
}
