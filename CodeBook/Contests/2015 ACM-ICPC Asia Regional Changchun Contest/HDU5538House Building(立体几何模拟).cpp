#include<bits/stdc++.h>
using namespace std;
int g[55][55];
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n, m ,c;
        memset(g,0, sizeof(g));
        scanf("%d %d", &n, &m);
        int ans = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                scanf("%d", &g[i][j]), ans+=g[i][j] > 0;
        for (int i = 1; i <= n; i++) //每块和周围的相减即可
            for (int j = 1; j <= m; j++)
            {
                ans += ((c=g[i][j]-g[i][j+1])>0) ? c : 0;
                ans += ((c=g[i][j]-g[i+1][j])>0) ? c : 0;
                ans += ((c=g[i][j]-g[i][j-1])>0) ? c : 0;
                ans += ((c=g[i][j]-g[i-1][j])>0) ? c : 0;
            }
        printf("%d\n", ans);
    }
    return 0;
}