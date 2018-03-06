//2017年6月25日 搜索专项复习
//1st bfs
//例题1:POJ3278 catch that cow (bfs)
//#include<bits/stdc++.h>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;
#define time Time
int n,k;
const int maxn=1e5+7;
int vis[maxn<<1];
int time[maxn<<1];//time[x] :s<=x<=e the cost_time of step x,init value 0
inline bool check(int x)
{
    if(vis[x]==0 && x<maxn && x>=0)
        return 1;
    return 0;
}
void bfs(int s)
{
    int nx;// note next site
    queue<int>q; //init open_table
    vis[s]=true;time[s]=0;
    q.push(s);//push x to make x step into closed_table
    while(!q.empty())//if open_table is not empty,else meaning all node hased been visted
    {
        int now = q.front();q.pop();//take current node in queue front
        for(int i=0;i<3;i++) //try all tests ,make all connected node into open_table 
        {
            if(i==0)
                nx = now + 1;
            else if(i==1)
                nx = now - 1;
            else nx = now * 2;
            //every step do something
            if(check(nx))
            {
                vis[nx]=1;
                q.push(nx);
                time[nx] = time[now] + 1;
            }

            if(nx == k) //arr at end of bfs
            {
                printf("%d\n",time[nx]);
                return ;
            }
        }
    }
    return ;
}
inline void init()
{
    memset(vis,0,sizeof vis);
    memset(time,0,sizeof time);
}
int main()
{
    while(scanf("%d %d",&n,&k)!=EOF)
    {
        init();
        if(n == k)
            printf("0\n");
        else
            bfs(n);
    }
    return 0;
}


//dfs
