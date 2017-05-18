#include <bits/stdc++.h>
using namespace std;
const int maxn = 5000+55;
vector<int> G1[maxn],G2[maxn];//G1存图
int low[maxn],dfn[maxn],indeg[maxn];
int vis[maxn],instack[maxn],belong[maxn],ans[maxn],dp[maxn];
int n,tot,sccc,sum;
stack<int> S;

void init(void)
{
    tot = sccc = 0;
    for(int i=0 ;i<=n ;i++){
        G1[i].clear(),G2[i].clear();
        low[i] = dfn[i] = indeg[i] = ans[i] = vis[i] = instack[i] = belong[i] = 0;
        dp[i] = -1;
    }
    while(S.size())
        S.pop();
}

void Tarjan(int x)
{
    low[x] = dfn[x] = tot++;
    vis[x] = instack[x] = 1;
    S.push(x);
    for(int i=0 ;i<G1[x].size();i++)
    {
        int v = G1[x][i];
        if(!dfn[v])
        {
            Tarjan(v);
            low[x] = min(low[x],low[v]);
        }
        else if(instack[v])
            low[x]=min(low[x],low[v]);
    }
    if(low[x] == dfn[x])
    {
        int t,cnt = 0;
        do
        {
            t = S.top();
            S.pop();
            instack[t] = 0;
            cnt++;
            belong[t] = sccc;
        }while(t!=x);
        ans[sccc++] = cnt;
    }
}

void dfs(int x)
{
    vis[x] = 1;
    sum += ans[x];
    for(int i=0 ;i<G2[x].size() ;i++)
        if(!vis[G2[x][i]])
            dfs(G2[x][i]);
}

int main(){
    int T;scanf("%d",&T);
    for(int kase=1;kase<=T;kase++)
    {
        int m;
        scanf("%d%d",&n,&m);
        init();
        while(m--)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            G1[x].push_back(y);
        }
        for(int i=0 ;i<n ;i++)
            if(!dfn[i])
                Tarjan(i);

        for(int i=0 ;i<n ;i++)
            for(int j=0;j<G1[i].size();j++)
                if(belong[i] != belong[G1[i][j]])
                {
                    indeg[belong[i]]++;
                    G2[belong[G1[i][j]]].push_back(belong[i]);
                }

        int MAX = -999;
        for(int i = 0 ;i<sccc ;i++)
        {
            if(!indeg[i])
            {
                sum = 0;
                memset(vis,0,sizeof(vis));
                dfs(i);
                dp[i] = sum;
                MAX = max(MAX,sum);
            }
        }
        bool flag = 1;
        printf("Case %d: %d\n",kase,MAX-1);
        for(int i=0 ;i<n ;i++)
            if(dp[belong[i]] == MAX)
            {
                if(flag)
                    printf("%d",i);
                else
                    printf(" %d",i);
                flag = 0;
            }
        printf("\n");
    }
    return 0;
}
