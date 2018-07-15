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
        sort(a+1,a+n+1);
        int cnt = 0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&b[i]);
            for(int j=1;j<=n;j++)
            if(a[j]>b[i])
            {
                cnt++;
                a[j]=0;
                break;
            }
        }
        printf("Case %d: %.2f\n",kase++,cnt*1.0/2);
    }
    return 0;
}
