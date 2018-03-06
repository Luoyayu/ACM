//队友好强
#include <bits/stdc++.h>
using namespace std;
bool vis[1010];
vector<int> a[1010];
void dfs(int s)
{
    vis[s]=1;
    for(int i=0;i<a[s].size();i++)
        if(vis[a[s][i]]==0) dfs(a[s][i]);
}
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        int x,y;
        for(int i=1;i<=n;i++)
            a[i].clear();
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&x,&y);
            a[x].push_back(y);
        }
        bool flag=1;
        for(int i=1;i<n;i++)
        {
            memset(vis,0,sizeof(vis));
            dfs(i);
            vector<int>v;
            for(int j=i+1;j<=n;j++) //这里应该存下那些正向出发不通的点，然后进行反向检查
                if(vis[j]==0) v.push_back(j);
            for(int j=0;j<v.size();j++)
            {
                memset(vis,0,sizeof(vis));
                dfs(v[j]);
                if(vis[i]==0)
                {
                    flag=0;
                    break;
                }
            }
            if(flag==0) break;
        }
        if(flag==1) printf("I love you my love and our love save us!\n");
        else printf("Light my fire!\n");
    }
    return 0;
}