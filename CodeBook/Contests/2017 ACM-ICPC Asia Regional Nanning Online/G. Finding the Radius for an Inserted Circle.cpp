#include <bits/stdc++.h>
using namespace std;
const double pi = 3.14159;
double ri[15];
double ans[15];
double sqr(double x)
{
    return x*x;
}
double work(double r,double r0)
{
    //余弦定理做
    double t = cos(pi/6);
    return (sqr(r0)+r0*r+sqr(r)-sqr(r)*t-2*r0*r*t)/(r*t-r0);
}
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        memset(ri,0, sizeof(ri));
        memset(ans,0, sizeof(ans));
        double r;scanf("%lf",&r);
        int k;
        while(scanf("%d",&k),~k)
        {
            printf("%d ",k);
            for(int i=1;i<=k;i++)
            {
                ri[i] = work(r,ans[i-1]);
                ans[i] = ans[i-1]+ri[i];
            }
            printf("%d\n",int(ri[k]));//注意截断
        }
    }
    return 0;
}