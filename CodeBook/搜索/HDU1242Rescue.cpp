#include <cstring>
#include <queue>
#include <iostream>
#include <cstdio>
using namespace std;
int n,m,sx,sy;
char map[205][205];
bool vis[205][205];
int dir[4][2]={1,0,-1,0,0,1,0,-1};
struct node
 {
     int x,y,steps;
    friend bool operator < (node a,node b)
    {
        return a.steps>b.steps;
    }
 }; 
bool judge(int &a,int &b)
{
    if(a>0 && a<=n && b>0 && b<=m && !vis[a][b]&&map[a][b]!='#')
        return true;
    else
        return false;
}
int bfs()
{
    node start,next;
    priority_queue<node> q;
    memset(vis,false,sizeof vis);
    start.x=sx,start.y=sy,start.steps=0;
    map[sx][sy]='#',vis[sx][sy]=true;
    q.push(start);
    while(!q.empty())
    {
        start=q.top();
        q.pop();
        if(map[start.x][start.y]=='r')
            return start.steps;
        for(int i=0;i<4;i++)
        {
            next=start;
            next.x+=dir[i][0],next.y+=dir[i][1],next.steps++;
            if(judge(next.x,next.y))
            {
                vis[next.x][next.y]=true;
                if(map[next.x][next.y]=='x')
                    next.steps++;
                q.push(next);
            }
            if(map[next.x][next.y]=='r')
                return next.steps;
        }
    }
    return 0;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        getchar();
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                scanf("%c",&map[i][j]);
                if(map[i][j]=='a')
                    sx=i,sy=j;
            }
            getchar();
        }
        int ans=bfs();
        if(ans)
            printf("%d\n",ans);    
        else 
            printf("Poor ANGEL has to stay in the prison all his life.\n");
    }
    return 0;
}