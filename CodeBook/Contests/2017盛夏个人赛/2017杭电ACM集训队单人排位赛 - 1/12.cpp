#include<bits/stdc++.h>
using namespace std;
const int maxn = 100 + 10;
int a[maxn],b[maxn],vis[maxn];
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        memset(vis,0,sizeof vis);
        for( int i = 1; i <= n; i++ )scanf("%d",&a[i]);
        for( int i = 1; i <= m; i++ )scanf("%d",&b[i]);
        int ans = 0;

        for( int i = 1; i <= n; i++ )
        {
            for( int j = 1; j <= m; j++ )
            {
                if(vis[j]==0 && b[j] == a[i])//对于行列控制的先打标记
                {
                    vis[j] = 1;
                    break;
                }
            }
          ans += a[i];
        }
        for( int i = 1; i <= m; i++ )
          if(!vis[i])
            ans += b[i];
        printf("%d\n",ans);
    }
    return 0;
}
