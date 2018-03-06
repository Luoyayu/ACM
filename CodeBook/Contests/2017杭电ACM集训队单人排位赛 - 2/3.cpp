#include<bits/stdc++.h>
#define Debug(x) cout<<#x<<"= "<<x<<endl;
using namespace std;
const int maxn=100007;
int ans[maxn];
int a[maxn],b[maxn],c[maxn];
int main()
{
    int t,n,m;scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            scanf("%d",&ans[i]);
        for(int i=1;i<=m;i++)
            scanf("%d%d%d",&a[i],&b[i],&c[i]);//a+b=>c
        int test=222;//设立test数b_f

       while(test--)
            for(int i=1;i<=m;i++)
                ans[c[i]]=min(ans[c[i]],ans[a[i]] + ans[b[i]]);

        for(int i=1;i<n;i++)
            printf("%d ",ans[i]);
        printf("%d\n",ans[n]);
    }
}
