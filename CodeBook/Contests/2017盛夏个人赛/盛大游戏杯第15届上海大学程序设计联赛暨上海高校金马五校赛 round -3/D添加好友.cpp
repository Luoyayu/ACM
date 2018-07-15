#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,p=1000000007;
LL quick_mod(LL a, LL b)
{
    LL ans = 1;
    a %= p;
    while(b)
    {
        if(b & 1)
        {
            ans = ans * a % p;
            b--;
        }
        b >>= 1;
        a = a * a % p;
    }
    return ans;
}
int main()
{
    while(scanf("%lld",&n)!=EOF)
        printf("%lld\n", quick_mod(2,n)-1);
    return 0;
}

