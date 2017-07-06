///喜闻乐见
///题意:求和k%(1.2.3....n)
/* a%b=a-(a/b)*b
 *  sum=n*k-∑[(k/i)*i]
 */
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    ll n,k;
    while(cin>>n>>k)
    {
        ll sum=n*k;

        ll tmp=0,left,right,blockNum;
        n = min(n,k);///if k<n all is 0
        for(int i=1; i<=n;i=right+1)
        {
            blockNum = k/i;
            left = i;
            right = k/(k/i);
            //cout<<"right1:"<<right<<endl;
            right = min(n, right);
            #ifdef Loca //Local
            //cout<<"right2:"<<right<<endl<<endl;;
            cout<<left<<' '<<k/(k/i)<<endl;
            #endif // Local
            //ll t1 = (1+right)*right>>1;
            //ll t2 = (left-1)*left>>1;
            //tmp+=blockNum*(t1-t2);
            tmp+=blockNum*(left+right)*(right-left+1)/2;
        }
        printf("%lld\n",sum-tmp);
    }
    return 0;
}
