//判断是否成环，经典拓扑排序，找到线性排序即可
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
const int  maxn= 200;
using namespace std;
int n,m,a,b;
int indeg[maxn];
vector<int> v[maxn];
bool flag = true;
inline void init()
{
    flag = true;
    for(int i = 0; i<n;++i)
        indeg[i]=0,v[i].clear();
}
void toposort()
{
    int cnt = 0;
    queue<int> q;
    while(1)
    {
        for(int i = 0; i<n; i++)
            if(!indeg[i])
                q.push(i),cnt++,indeg[i] = -1;
        if(q.empty()) break;

        while(!q.empty())
        {
            int t = q.front();q.pop();
            for(int i = 0; i<v[t].size();i++)
            {
                int VV=v[t][i];
                if(indeg[VV] == -1)
                {
                    flag =false;
                    return;
                }
                else
                    indeg[VV]--;
            }
        }
    }
    if(cnt!=n)
        flag = false;
}
int main()
{
    while(scanf("%d%d",&n,&m),n)
    {
        init();
        for(int i = 0; i<m; ++i)
            scanf("%d%d",&a,&b),indeg[b]++,v[a].push_back(b);
        toposort();
        printf("%s\n",flag?"YES":"NO");
    }
    return 0;
}
