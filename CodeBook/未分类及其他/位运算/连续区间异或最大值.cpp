#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read32()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
inline ll read64()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int main()
{
    int t = read32();
    while(t--)
    {
        ll L = read64(),R = read64(); 
        ll tmp = L ^ R, k = 0;
        for(k=64;k>=0;k--)
            if(tmp & (1LL<<k)) break;
        printf("%lld\n",1LL<<(k+1)-1);
    }
    return 0;
}