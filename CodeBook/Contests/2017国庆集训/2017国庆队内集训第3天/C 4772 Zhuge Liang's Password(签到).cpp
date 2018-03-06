#include <bits/stdc++.h>
using namespace std;
const int maxn = 50;
int a[maxn][maxn],b[maxn][maxn];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF,n)
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                scanf("%d",&a[i][j]);

        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                scanf("%d",&b[i][j]);

        int cnt = 0;
        int ans = 0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(a[i][j]==b[i][j]) cnt++;

        ans = max(cnt,ans);cnt =0 ;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(a[i][j]==b[n-j+1][i]) cnt++;
        ans = max(cnt,ans);cnt =0 ;

        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(a[i][j]==b[n-i+1][n-j+1]) cnt++;
        ans = max(cnt,ans);cnt =0 ;

        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(a[i][j]==b[j][n-i+1]) cnt++;
        ans = max(cnt,ans);
        
        printf("%d\n",ans);
    }
    return 0;
}