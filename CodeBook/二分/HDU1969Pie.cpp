
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=10000+55;
const double pi = acos(-1);
double S[maxn];
int n,f;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&f);
        f++;
        double MAX=-1;
        int R;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&R);
            S[i]=pi*R*R;
            if(S[i]>MAX)
                MAX=S[i];
        }
        double mid,r=MAX,l=0;
        while(r-l>=0.00001)
        {
            mid=(r+l)/2.0;
            int sum=0;
            for(int i=0;i<n;i++)
                sum += int(1.0*S[i]/mid);
            if(sum>=f)
                l=mid;
            else
                r=mid;
        }
        printf("%.4lf\n",(l+r)/2.0);
    }
    return 0;
}
