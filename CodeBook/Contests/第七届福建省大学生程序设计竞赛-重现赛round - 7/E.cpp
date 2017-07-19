#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 10000+77;
int a[maxn],b[maxn];
int main()
{
    int t;scanf("%d",&t);
    int kase = 1;
    while(t--)
    {
        int n;scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)
            scanf("%d",&b[i]);
        int cnt = 0;
        int i=1,j=1;
        for(int i=1;i<=n;i++)
        {
            if(a[i]+b[i]>10)
                cnt++;
        }
        printf("Case %d: %d\n",kase++,cnt);
    }
    return 0;
}
