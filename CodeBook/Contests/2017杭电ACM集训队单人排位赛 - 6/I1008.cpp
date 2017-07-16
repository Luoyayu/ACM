#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n,m;
const int maxn = 1e5+77;
int a[maxn],ans[maxn];
int vis[maxn];
struct node
{
    int b,c;
    operator <(const node &B)
    {
        if(b!=B.b) return b<B.b;
        return c>B.c;
    }
}p[maxn];
//ai-bj+cj
void solve()
{
    priority_queue<int> q;
    int cnt = 1, id = 1;
    for(int i = 1; i <= n; i++)
    {
        while(a[i] > p[cnt].b && cnt <= m)
            q.push(p[cnt].c - p[cnt++].b);//a[i]能打的村庄后面的都可以打

        if(!q.empty())
        {
            int top = q.top(); q.pop();
            vis[i] = 1; ans[i] = a[i] + top;
        }
        else//replace
        {
            while(vis[id] ==0 && id++ < i) ;

            if(vis[id])
            {
                ans[i] = ans[id] - a[id] + a[i];
                vis[i] = 1, vis[id] = 0;
                ans[id++] = 0;
            }
        }
    }

    LL res = 0;
    for(int i = 1; i <= n; i++)
        if(vis[i]&&ans[i]>0) res += ans[i];
    printf("%lld\n", res);
}

int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        memset(vis,0,sizeof vis);
        memset(ans,0,sizeof ans);
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<=m;i++)
            scanf("%d%d",&p[i].b,&p[i].c);
        sort(a,a+n+1);sort(p,p+m+1);
        solve();
    }
    return 0;
}
