#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

struct meal{
    int score,cost;
}a[110];
bool ans[110];
int dp[1010];
bool vis[110][1010];
int main()
{
    int T;scanf("%d",&T);
    for(int kase =1;kase<=T;kase++)
    {
        int b,n;scanf("%d%d",&b,&n);
        for(int i=1;i<=n;i++)
            scanf("%d%d",&a[i].score,&a[i].cost);
        memset(dp,0,sizeof(dp));
        memset(vis,false,sizeof(vis));
        memset(ans,0,sizeof(ans));
        for(int i=1;i<=n;i++)
        {
            for(int j=b;j>=0;j--)
            {
                if(j>=a[i].cost)
                {
                    if(dp[j] < dp[j-a[i].cost] + a[i].score)
                    {
                        dp[j] = dp[j-a[i].cost] + a[i].score;
                        vis[i][j] = true;
                    }
                    else vis[i][j] = false;    
                }     
            }
        }

        int p=b,cnt = 0;
        for(int i=n;i>=1;i--)
        {
          if(vis[i][p])
          {
                ans[i]=true;
                p -= a[i].cost;
                cnt++;
            }
        }
        int ANS = 0;
        for(int i=1;i<=n;i++)
            if(ans[i])
                ANS += a[i].cost;
        printf("Case #%d:\n",kase++);
        printf("%d %d\n",dp[b],ANS);
        for (int i = 1; i <= n; i++)
            if (ans[i])
                printf("%d%c", i, (--cnt == 0) ? '\n' : ' ');

    }
    return 0;
}