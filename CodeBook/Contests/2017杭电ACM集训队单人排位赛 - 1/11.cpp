#include<bits/stdc++.h>
using namespace std;
__int64 pow(__int64 x,__int64 y,__int64 mod)
{
    __int64 ans=1;
    while(y)
    {
        if(y&1)
            ans=ans*x%mod;
        x=x%mod*(x%mod)%mod;
        y>>=1;
    }
    return ans;
}
int main()
{
    __int64 T,n,m,x,y;
    while(scanf("%I64d",&T)!=EOF)
    {
        while(T--)
        {
            scanf("%I64d %I64d %I64d %I64d",&n,&m,&x,&y);
            if(x>y) swap(x, y);
            __int64 X=x%n*(pow(2,m,n)%n)%n;
            __int64 Y=n-X;
            if(X<Y) swap(X, Y);
            printf("%I64d %I64d\n", X, Y);
        }
    }
    return 0;
}
