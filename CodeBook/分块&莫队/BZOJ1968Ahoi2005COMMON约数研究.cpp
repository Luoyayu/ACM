///sum ∑[(n/i)*i]
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+7;
ll n;
int main()
{
    while(scanf("%lld",&n)!=EOF)
    {
        ll left,right;
        ll sum=0;
        for(int i=1;i<=n;i=right+1)
        {
            ll blockNum=n/i;
            left = i;
            right=min(n,n/(n/i));
            #ifdef Local
            cout<<left<<" "<<right<<endl;
            #endif // Local
            sum+=blockNum*(right-left+1);
        }
        printf("%lld\n",sum);
    }
    return 0;
}
