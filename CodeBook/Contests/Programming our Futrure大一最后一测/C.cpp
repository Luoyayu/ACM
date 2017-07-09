
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
const int maxn= 2000;
typedef long long ll;
int a[maxn],b[maxn],c[maxn];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(int i=0;i<n;i++)
            scanf("%d",&b[i]);
        sort(a,a+n);
        sort(b,b+n,cmp);
        for(int i=0;i<n;i++)
        {
            c[i]=a[i]+b[i];
        }
        sort(c,c+n);
        printf("%d\n",c[n-1]);

    }
    return 0;

}
