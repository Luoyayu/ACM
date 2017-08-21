#include<bits/stdc++.h>
//太菜，不想说了，但是错误的算法过了9个case是什么意思？？？？？？//？？？？？写错的STL竟然过了8个case,汗
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
typedef long long ll;
const int maxn = 1e5 +7;
ll a[maxn];
int main()
{
    int n = read();
    for(int i=1;i<=n;i++) a[i] = read();
    ll ans = 1, flag = 0;
    sort(a+1,a+n+1);
    for(int i=n;i>=1;i--)
    {
        if(a[i]==a[i-1])
            ans *= a[i], flag++,i--;
        if(flag==2) break;
    }
    return !printf("%lld\n",flag==2?ans:0);
}