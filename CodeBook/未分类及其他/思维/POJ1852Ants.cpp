#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
const int maxn = 1000000 +7;
const int inf = 0x3f3f3f3f;
int ant[maxn];
int main()
{
    int t;scanf("%d\n", &t);
    while(t--)
    {
        int L,n;scanf("%d%d",&L,&n);
        for (int i = 1; i <=n; i++)
            scanf("%d",&ant[i]);
        int minT=0, maxT = 0;
        for(int i=1;i<=n;i++)
            minT = max(minT, min(ant[i],L-ant[i]));//每只蚂蚁朝向比较近的端点前进时间最短
        for(int i=1;i<=n;i++)//实质上蚂蚁碰头,仍然可以看成他们穿过而行,这样取决于那只蚂蚁离端点最远
            maxT = max(maxT, max(ant[i],L-ant[i]));
        printf("%d %d\n",minT,maxT);
    }
    return 0;
}
