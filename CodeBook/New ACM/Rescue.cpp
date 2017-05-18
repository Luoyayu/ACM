//优先队列出队
#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <string>
using namespace std;
const int maxn = 333;
int dir[4][2]={1,0,-1,0,0,1,0,-1};
int n,m,sx,sy;
bool vis[maxn][maxn];
char map[maxn][maxn];
bool judge(int &a,int &b)
{
    if(a>0 && a<=n && b>0 && b<=m && !vis[a][b]&&map[a][b]!='#')
        return true;
    else
        return false;
}
struct node
{
    int x,y,steps;
    friend bool operator < (node a,node b)
    {
        return a.steps > b.steps;
    }

};
int bfs()
{
    node start,next;
    start.x=sx,start.y=sy,start.steps=0;
    memset(vis,false,sizeof vis);
    vis[sx][sy]=true,map[sx][sy]='#';
    priority_queue<node> q;
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
            next.x+=dir[i][0];next.y+=dir[i][1];next.steps++;
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
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
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