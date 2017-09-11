#include <bits/stdc++.h>
//题意：
using namespace std;
typedef long long  LL;
const int maxn=1e5+10;
const int INF=0x3f3f3f3f;
int main()
{
    LL m,k;
    while(~scanf("%lld %lld",&m,&k))
    {
        LL ans=(m-k)*k+k;
        printf("%lld\n",ans);
    }
    return 0;
}