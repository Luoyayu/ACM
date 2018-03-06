///Lucky7
///题意:求[l,r]范围内是7的倍数，同时不满足给定的同余式的数的个数
///容斥定理
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
typedef long long ll;
ll ex_gcd(int a,int b,int &x,int &y)
{
    if(!b)
    {
        x=1;y=0;
        return a;
    }
    ll ans=ex_gcd(b,a%b,y,x);
    y-=a/b*x;
    return ans;
}
ll crt(int *a,int *m,int n)
{
    int M=1,ans=0;
    for(int i=0;i<n;i++)
        M*=m[i];
    for(int i=0;i<n;i++)
    {
        int Mi=M/m[i];
        int x,y;
        ex_gcd(Mi,m[i],x,y);
        ans+=((ans%M+(Mi%M)*(a[i]%M)*(x%M))+M)%M;
    }
    return ans;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int kase=1;kase<=T;kase++)
    {
        ll x,y,n;
        scanf("%d%d%d",&n,&x,&y);
        for(int i=0;i<n;i++)
        {

        }

    }
    return 0;
}
