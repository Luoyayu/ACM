#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
typedef long long LL;
vector<int>GG[maxn];
map<int,int>Mp,mp;
int F[maxn<<1];
int G[3010][3010];
int Find(int x)
{
    if(x==F[x]) return x;
    return F[x]=Find(F[x]);
}
void U(int x,int y)
{
    int fx=Find(x),fy=Find(y);
    if(fx!=fy)
    F[fx]=fy;
}
int n,m;
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        memset(G,0,sizeof(G));
        Mp.clear();mp.clear();
        for(int i=1;i<=n;i++)
            GG[i].clear(),F[i]=i;
        for(int i=1,s,t,w;i<=m;i++)
        {
            scanf("%d %d %d",&s,&t,&w);
            if(G[s][t])
                G[s][t]+=w, G[t][s]+=w;
            else
            G[s][t]=w,G[t][s]=w;
            U(s,t);
        }

        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                if(i==j) continue;
                Mp[i]+=(G[i][j]);
            }
        for(int i=1;i<=n;i++)
        {
            if(mp[Find(i)])
                mp[Find(i)]=min(mp[Find(i)],Mp[i]);
            else
                mp[Find(i)]=Mp[i];
            GG[Find(i)].push_back(i);
        }
        LL sum=0;
        for(int i=1;i<=n;i++)
            if(Find(i)==i)
                if(GG[i].size()>1) sum+=mp[i];
        printf("%lld\n",sum);
    }
return 0;
}