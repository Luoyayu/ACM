#include<bits/stdc++.h>
//签到题
using namespace std;
const int maxn = 10000+5;
struct node{
    int t,p;
}a[maxn];
bool cmp(node a, node b)
{
    return a.t<b.t;
}
int main()
{
    int t;scanf("%d",&t);int kase = 1;
    while(t--)
    {
        int n;scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d %d",&a[i].t, &a[i].p);
        sort(a+1,a+n+1,cmp);
        double ans = 0;
        for(int i=1;i<=n;i++)
            ans = max(ans,fabs((a[i].p-a[i+1].p)*1.0/(a[i].t-a[i+1].t)));
        printf("Case #%d: %.2lf\n",kase++,ans);
    }
    return 0;
}