#include<bits/stdc++.h>
using namespace std;
const int maxn=100+7;
const double esp = 1e-7;
int p[maxn];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n, v, w;
        int ans=0,cnt=0;//max V
        scanf("%d%d%d",&n,&v,&w);
        for(int i=0; i<n; i++)
            scanf("%d",&p[i]);
        sort(p,p+n);
        for(int i=0;i<n;i++)
        {
            if(1.0*(ans+p[i])/(cnt+1)<=1.0*w)
            {
                ans+=p[i];
                cnt++;
            }
            else
                break;
        }
        if(ans==0)
            printf("0 0.00\n");
        else
            printf("%d %.2f\n",cnt*v,0.01*ans/cnt);
    }
}
