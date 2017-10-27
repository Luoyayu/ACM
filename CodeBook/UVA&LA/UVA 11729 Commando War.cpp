//贪心，按照完成任务排序，先去完成耗时多的任务，在最长的执行期间可以继续交代和做任务
#include <bits/stdc++.h>
using namespace std;
#define cmax(a,b) a=max(a,b);
const int maxn = 1005;
struct node{
    int j,b;//j完成耗时,b交代耗时
    bool operator<(const node &a)const {
        return j > a.j;
    }
}jb[maxn];
int main()
{
    int n,kase=1;
    while(scanf("%d",&n)!=EOF,n)
    {
        for(int i=0;i<n;i++) scanf("%d%d",&jb[i].b, &jb[i].j);
        sort(jb,jb+n);
        int tmp=0,ans=0;
        for(int i=0;i<n;i++)
        {
            tmp += jb[i].b;
            cmax(ans,tmp+jb[i].j);
        }
        printf("Case %d: %d\n",kase++,ans);
    }
    return 0;
}