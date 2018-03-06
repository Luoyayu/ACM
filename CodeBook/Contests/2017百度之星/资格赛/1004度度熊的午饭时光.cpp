#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxb = 1000+7;
const int maxn = 100+7;
const ll mod = ll(1e9 + 7);
#define clr(a,v) memset(a,v,sizeof(a))
struct {
    int score,cost;
}it[maxn];
bool ans[maxn];
int dp[maxb];//dp[i]表示i$能获得的MAX_score
bool vis[maxn][maxb];
int main()
{
    int T;scanf("%d",&T);
    for(int kase=1; kase<=T; kase++)
    {
        int b,n;scanf("%d%d", &b,&n);
        for(int i=1; i<=n; i++)
            scanf("%d%d",&it[i].score,&it[i].cost);
        clr(dp,0);clr(vis,false);clr(ans,0);

        for(int i=1; i<=n; i++)
            for(int j=b; j>=0; j--)
                if(j>=it[i].cost)
                {
                    if(dp[j] < dp[j-it[i].cost] + it[i].score)
                    {
                        dp[j] = dp[j-it[i].cost] + it[i].score;
                        vis[i][j] = true;//mark ith in j budget
                    }
                    else vis[i][j] = false;
                }

        int tmp=b,cnt=0,ANS=0;
        for(int i=n; i>=1; i--)
            if(vis[i][tmp])
            {
                ans[i]=true;
                ANS += it[i].cost;
                tmp -= it[i].cost;
                cnt++;
            }

        printf("Case #%d:\n%d %d\n",kase,dp[b],ANS);
        for (int i = 1; i <= n; i++)
            if (ans[i])
                printf("%d%c", i, (--cnt == 0) ? '\n' : ' ');
    }
    return 0;
}
