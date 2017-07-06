//温习topoSort
//HDU 5695 2016"百度之星" - 初赛（Astar Round2A）
#include<cstdio>
#include <iostream>
#include<queue>
#define OK ios::sync_with_stdio(false)
using namespace std;
const int maxn=100000+100;
int n,m;
vector <int> V[maxn];
int indeg[maxn],a[maxn];
priority_queue<int> Q;
void init()
{
    for(int i=0;i<maxn;i++)
    {
        indeg[i]= a[i]=0;
        V[i].clear();
    }
    while(!Q.empty())
        Q.pop();
}

void toposort()
{
    for(int i=1;i<=n;i++)
        if(indeg[i]==0)
            Q.push(i);

    int tot=1;
    while(!Q.empty())
    {
        int now=Q.top();Q.pop();
        a[tot++] = now;
        for(int i=0;i<V[now].size();i++)
        {
            int cur=V[now][i];
            indeg[cur]--;
            if(indeg[cur]==0)//c::b方括号匹配@懵@圈@
                Q.push(cur);
        }
    }
    long long ans=0;
    int tmp=0x3f3f3f3f;
    for(int i=1;i<=n;i++)
    {
        tmp = min(tmp,a[i]);
        ans += tmp;
    }
    cout<<ans<<endl;
}
int main()
{
    OK;
    int t;scanf("%d",&t);
    while(t--)
    {
        init();
        scanf("%d%d",&n,&m);
        while(m--)
        {
            int x,y;scanf("%d%d",&x,&y);
            V[x].push_back(y);
            indeg[y]++;//y入度++
        }
        toposort();
    }
    return 0;
}
