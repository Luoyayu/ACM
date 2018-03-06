#include<bits/stdc++.h>
//8*8 从A搜到B再从B搜到C就过了
using namespace std;
int mp[15][15];
int dir[][4]={1,2,1,-2,-1,2,-1,-2};
struct node
{
    int x;int y;
    int step;
};
bool vis[15][15];
bool check(int x,int y)
{
    if(x<0||x>8||y<0||y>8||vis[x][y])
        return 0;
    return 1;
}

int bfs(node s,node e)
{
   queue<node> q;
   q.push(s);
   s.step=0;
   vis[s.x][s.y]=1;
   while(!q.empty())
    {
        node now=q.front();
        q.pop();
        vis[now.x][now.y]=1;
        for(int i=0;i<4;i++)
        {
            now.x=s.x+dir[i][0];
            now.y=s.y+dir[i][1];
            if(check(now.x,now.y))
            {
                s.step++;
                q.push(s);
            }
        }
    }
    return s.step;
}
void bfs()
{

}
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
       node A,B,C;
       memset(vis,0,sizeof vis);
       scanf("%d%d%d%d%d%d",&A.x,&A.y,&B.x,&B.y,&C.x,&C.y);
       int step1=bfs(A,B);
       memset(vis,0,sizeof vis);
       int step2=bfs(B,C);
       printf("%d\n",step1+step2);
    }
    return 0;
}
