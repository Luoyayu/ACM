#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+100;
int par[maxn],ans[maxn],cnt;
set<int> un[maxn],q;

int find(int x) 
{
    return par[x]==x ? x:par[x]=find(par[x]);
}

void uni(int x,int y)
{
  if (un[x].size()<un[y].size()) swap(x,y);
  for (auto i:un[y])
  {
    un[i].erase(y);
    un[i].insert(x);
    un[x].insert(i);
  }
  par[y]=x;
}

void clear()
{
    for (auto i:q) 
        par[i]=i,un[i].clear();
  q.clear();
}

int main()
{
    int n;
    while (scanf("%d",&n)!=-1)
    {
        for (int i=0;i<maxn;i++)
        {
            par[i]=i;ans[i]=0;
            un[i].clear();
        }
        cnt=1;q.clear();
        
        while (n--)
        {
            int x,y,z;scanf("%d %d %d",&x,&y,&z);

            int f1=find(x), f2=find(y);ans[cnt]++;
            q.insert(x);q.insert(y);

            if (z)
            {       
                if(f1==f2) continue;
                if(!un[f1].count(f2))
                    uni(f1,f2);
                else 
                    cnt++, clear();
            }
            else 

                if (f1==f2) 
                    cnt++, clear();
                else 
                    un[f1].insert(f2), un[f2].insert(f1);
        }

        if (ans[cnt]==0) cnt--;
        printf("%d\n",cnt<0?0:cnt);
        for (int i=1;i<=cnt;i++) 
            printf("%d\n",ans[i]);
    }
    return 0;
}