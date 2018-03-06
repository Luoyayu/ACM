#include<bits/stdc++.h>
using namespace std;
const int maxn = 105;
const int inf = 0x3f3f3f3f;
//题意：给出N*M矩阵最多有4个宝藏，从'@'出发问拿到所有宝藏最少步数
int n,m,k;
char maps[105][105];
struct node{
    int x,y;
    node(){}
    node(int x,int y):x(x),y(y){}
}point[8];
int dir[][2]={0,1,0,-1,1,0,1,-1};
int p[5];
bool vis[maxn][maxn];
int dfs(node s, node e)
{
    int ans = 0,cnt1 = 1,cnt2 = 0;
    queue<node>q;
    q.push(s);q.pop();
    memset(vis,0,sizeof(vis));
    vis[s.x][s.y]=1;
    while(!q.empty())
    {
        node now = q.front();q.pop();
        cnt1--;
        for(int i=0;i<4;i++)
        {
            int cur_x = now.x+dir[i][0];
            int cur_y = now.y+dir[i][1];
            if(cur_x==e.x && cur_y==e.y)
                return ans+1;
            else if(maps[cur_x][cur_y]=='.' && vis[cur_x][cur_y]==0)
            {
                vis[cur_x][cur_y] = 1;
                cnt2 ++;
                q.push(node(cur_x,cur_x));
            }
        }
        if(cnt1==0)
        {
            ans ++;
            cnt1=cnt2;
            cnt2=0;
        }
    }
    return 0;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            getchar();
            for(int j=1;j<=m;j++) maps[i][j]='#'; 
            for(int j=1;j<=m;j++)
            {
                scanf("%c",&maps[i][j]);
                if(maps[i][j]=='@') point[5].x=i, point[5].y=j;
            }
        }
        for(int i=1;i<=5;i++) p[i] = i;
        scanf("%d",&k);
        for(int i=1;i<=k;i++) scanf("%d%d",&point[i].x,&point[i].y);
        int ans = inf;

        do{
            int cnt = 0, num = 0;
            num = dfs(point[5],point[p[1]]);
            if(num==0) continue;
            else cnt+=num;

            for(int i=1;i<k;i++)
            {
                num = dfs(point[p[i]],point[p[i+1]]);
                if(num==0) continue;
                else cnt+=num;
            }
            ans = min(ans,cnt);
        }while(next_permutation(p+1,p+k+1));
        if(ans==inf) printf("-1\n");
        else printf("%d\n",ans);
    }
    return 0;
}