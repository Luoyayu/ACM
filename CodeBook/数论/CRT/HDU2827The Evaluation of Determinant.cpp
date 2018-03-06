//求矩阵行列式mod m = p_1*p_2*····p_n
//思想：高消
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define clr(a,b) memset(a,b,sizeof(a))
const int maxn = 105;
int n;
ll p;
ll a[maxn][maxn];
ll Gauss()//高斯消元化为上三角形
{
    ll ret = 1;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            while(a[j][i])
            {
                ll d = a[i][i] / a[j][i];
                for(int k=i;k<n;k++)
                {
                    a[i][k]=( (a[i][k]-d*a[j][k])%p+p )%p;
                    swap(a[i][k],a[j][k]);
                }
                ret *= -1;
            }
            if(!a[i][i]) return 0;
        }
    }
    for(int i=0;i<n;i++)
        ret=(ret*a[i][j]%p+p)%p;
    return ret;
}
int main()
{
   while(scanf("%d%lld",&n,&p)!=EOF)
   {
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                scanf("%lld",&a[i][j]);
                a[i][j]=(a[i][j]%p+p)%p;
            }
        printf("%lld\n",Gauss());
   }
   return 0;
}
