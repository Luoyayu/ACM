#include <cstdio>
#include <queue>
#include <iostream>
#include <cstring>
#include <algorithm>
const int maxn =2000;
int pri[maxn];
int vis[maxn];
int map[maxn][maxn];
int k,m,n;
using namespace std;
/*原理： 增广路定理，通过找寻增广路交换身份增加匹配边和匹配点。
实现DFS版本，BFS版本
预备知识：二分图，匹配，匈牙利树。
匈牙利树：从一个未匹配点出发运行BFS（交替走）直到不能扩展为止。
要求叶节点为匹配点。
核心问题在于通过枚举寻找增广路径
*/
//入门题：过山车 求最大匹配数
int  find(int x)
{
    for(int i=1;i<=m;i++)
    {
        if(vis[i]==0&&map[i][x])
        {
            vis[i]=1;
            if(pri[i]==-1||find(pri[i]))
            {
                pri[i]=x;
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    while(~scanf("%d",&k))
    {
        if(k==0)break;
        scanf ("%d%d", &m, &n);
        memset (map, 0, sizeof (map));
        memset (pri, -1, sizeof (pri));
        for(int i=0;i<k;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            map[a][b]=1;
        }
        int output=0;
        for(int i=1;i<=n;i++)
        {
            memset(vis,0,sizeof(vis));
            if(find(i))
            output++;
        }
        printf("%d\n",output);
    }
}