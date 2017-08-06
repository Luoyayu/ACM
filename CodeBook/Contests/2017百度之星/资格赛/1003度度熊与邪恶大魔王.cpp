#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
int a[1010][11];
ll dp[2030];//造成k伤害的最小花费；
int main()
{
    int n,m;
     while(~scanf("%d%d",&n,&m))
     {
                int maxf=0,maxg=0;
                memset(a,0,sizeof(a));
           for(int i=1;i<=n;i++)
                {
                        int x, y;
                        scanf("%d%d",&x,&y);
                        maxf=max(y,maxf);
                        a[x][y]+=1;
                }
                       int k[1010],p[1010];
                   for(int i=1;i<=m;i++)
                {
                        scanf("%d%d",&k[i],&p[i]);
                        maxg=max(maxg,p[i]);
                }
                ll ans=0;
          if(maxf>=maxg)
          {
                ans=-1;
                goto L;
          }

    for(int f=0;f<=10;f++)
                {
                        memset(dp,inf,sizeof(dp));
                             dp[0]=0;

                                     for(int i=1;i<=m;i++)
                                         if(p[i]-f>0)
                                        for(int v=p[i]-f;v<=2010;v++)
                                              dp[v]=min(dp[v],dp[v-(p[i]-f)]+k[i]);

                        for(int h=1;h<=1000;h++)
                        {
                                ll minx;
                                  if(a[h][f]>0)
                               {
                                         minx=inf;
                                       for(int p=h;p<=2010;p++)
                                        minx=min(minx,dp[p]);
                                }
                                ans+=a[h][f]*minx;
                        }
                }

      L:     cout<<ans<<endl;
     }
    return 0;
}


#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define rep(i, s, t) for(long long i = s;i <= t;i++)
#define rap(i, s, t) for(long long i = s;i >= t;i--)
#define inf 0x3f3f3f3f
typedef long long LL;
using namespace std;
struct Mo
{
    LL heal;
    LL def;
}monster[100004];
struct Spi
{
    LL att;
    LL cost;
}spill[1005];
LL dp[15][1011];
int main()
{
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        memset(dp, inf, sizeof(dp));
        for(int i = 0;i <= 10;i++)
            dp[i][0] = 0;
        int flag = 1;
        rep(i, 1, n)
            scanf("%I64d%I64d", &monster[i].heal, &monster[i].def);
        rep(i, 1, m)
            scanf("%I64d%I64d", &spill[i].cost, &spill[i].att);
        LL ans = 0;
        rep(i, 0, 10)
        {
          rep(j, 1, m)
               {
                    if(spill[j].att <= i)
                        continue;
                    rep(k, 1, spill[j].att - i)
                    {
                        dp[i][k] = min(dp[i][k], spill[j].cost);
                    }
                    rep(k, spill[j].att - i + 1, 1010)
                    {
                        if(dp[i][k - (spill[j].att -i)] != inf)
                            dp[i][k] = min(dp[i][k], dp[i][k - (spill[j].att - i)] + spill[j].cost);
                    }
               }
        }
        rep(i, 1, n){
            LL minn = inf;
            rep(j, monster[i].heal, monster[i].heal + 10)
            {
                if(dp[monster[i].def][j] != inf)
                    minn = min(minn, dp[monster[i].def][j]);
            }
            if(minn == inf)
            {
                flag = 0;
                break;
            }
            ans += minn;
        }
        if(flag == 0)
            printf("-1\n");
        else
            printf("%I64d\n", ans);
    }
    return 0;
}




