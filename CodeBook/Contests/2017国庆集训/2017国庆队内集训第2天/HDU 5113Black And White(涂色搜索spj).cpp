//题意：给出n×m的矩阵涂色
//k中颜色，i-th ai 必须涂的方格数，给出是否能用已知的颜色情况涂出互不相邻同色的情况，请输出
#include<bits/stdc++.h>
using namespace std;
int n,m,tot;
const int maxn = 55;
int color[maxn];
bool flag;
int g[6][6];
bool check(int x,int y, int cur_color)
{
    bool r = 1, c = 1;
    if(x>=2 && g[x-1][y]==cur_color) c = 0;
    if(y>=2 && g[x][y-1]==cur_color) r = 0;
    return r && c;
}
void dfs(int x,int y,int cnt)
{
    for(int i=1;i<=tot;i++)
        if(color[i]>(cnt+1)/2) return ;

    if(flag) return ;
    if(x == n+1)
    {
        flag = 1;
        puts("YES");
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                printf("%d%c",g[i][j],j==m?'\n':' ');
        return ;
    }
    for(int i=1;i<=tot;i++)
        if(color[i]&&check(x,y,i))
        {
            color[i]--;g[x][y] = i;
            if(y==m) dfs(x+1,1,cnt-1);
            else dfs(x,y+1,cnt-1);
            color[i]++;
        }

}
int main()
{
    int t;scanf("%d",&t);
    for(int kase=1;kase<=t;kase++)
    {
        scanf("%d %d %d",&n,&m,&tot);
        for(int i=1;i<=tot;i++) scanf("%d",&color[i]);
        flag = 0;
        printf("Case #%d:\n",kase);
        dfs(1,1,n*m);
        if(flag==0) puts("NO");
    }
    return 0;
}