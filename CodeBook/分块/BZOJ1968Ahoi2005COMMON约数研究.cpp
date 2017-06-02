
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+7;
ll a[maxn],n;
int main()
{
    while(scanf("%lld",&n)!=EOF)
    {
        ll left,right;
        ll sum=0;
        for(int i=1;i<=n;i=right+1)
        {
            left=i;
            right=(n)/(n/i);
            right=min(n,right);
            sum+=(n/i)*(right-left+1);
        }
        printf("%lld\n",sum);
    }
    return 0;
}
