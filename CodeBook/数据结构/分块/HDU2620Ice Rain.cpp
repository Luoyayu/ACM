//喜闻乐见
/*题意:Σk%(1,2,3....n)
* a%b=a-(a/b)*b
* sum=n*k-∑[(k/i)*i]
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n,k;
    while(cin>>n>>k)
    {
        ll sum=n * k;     
        ll tmp=0,left,right,blockNum;
        n = min(n,k);///if k<n all is 0,
        for(int i=1; i<=n;i=right+1)
        {
            blockNum = k/i;
            left = i;
            right = min(n, k/(k/i));
            tmp+=blockNum*(left+right)*(right-left+1)>>1;
        }
        printf("%lld\n",sum-tmp);
    }
    return 0;
}
