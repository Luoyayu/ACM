//题意：在保证原有的联通下，求至多可以去掉的边数
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int inf = 0x3f3f3f3f;
#define clr(a,b) memset(a,b,sizeof a)
const int maxn = 100+5;
int d[maxn][maxn];
bool vis[maxn][maxn],v[maxn][maxn];
void floyd(int n)
{
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(d[i][j]>=d[i][k]+d[k][j])
                    d[i][j]=d[i][k]+d[k][j],vis[i][j]=1;
}
int main()
{
    int n,m,t;
    scanf("%d",&t);
    for(int kase=1;kase<=t;kase++)
    {
        scanf("%d%d",&n,&m);
        int ans = 0;
        clr(v,0);clr(vis,0);clr(d,inf);
        for(int i=0;i<m;i++)
        {
            int x,y,s;
            scanf("%d%d%d",&x,&y,&s);
            v[x][y]=v[y][x]=1;//有边相连就打标
            if(d[x][y]<inf) ans++;
            d[x][y]=d[y][x]=min(d[x][y],s);
        }
        floyd(n);
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                if(v[i][j]&&vis[i][j])
                    ans++;
        printf("Case %d: %d\n",kase,ans);
    }
    return 0;
}
