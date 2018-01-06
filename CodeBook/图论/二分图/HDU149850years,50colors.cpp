#include <iostream>
#include <cstring>
#include<cstdio>
using namespace std;
const int nMax = 105;
int map[nMax][nMax];
int link[nMax];
int vis[nMax];
int ans[nMax];
int len;
int n, k;

int dfs(int t, int col)
{
    for(int i = 0; i < n; ++ i)
    {
        if(!vis[i] && map[t][i] == col)
        {
            vis[i] = 1;
            if(link[i] == -1 || dfs(link[i], col))
            {
                link[i] = t;
                return 1;
            }
        }
    }
    return 0;
}

int maxMatch(int col)
{
    memset(link, -1, sizeof(link));
    int num = 0;
    for(int i=0;i<n;i++)
    {
        memset(vis, 0, sizeof(vis));
         num +=dfs(i, col);
    }
    return num;
}

int main()
{
    while(scanf("%d %d", &n, &k) != EOF)
    {
        memset(map, 0, sizeof(map));
        len = 0;
        if(!n && !k) break;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                 scanf("%d", &map[i][j]);

        for(int i = 1; i <= 50; ++ i)
        {
            if(maxMatch(i) > k)
                ans[len++] = i;
        }
        if(!len)
            printf("-1\n");
        else
        {
            for(int i=0;i<len-1;i++)
                 printf("%d ", ans[i]);
            printf("%d\n",ans[len - 1]);
        }
    }
    return 0;
}
