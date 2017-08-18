#include<bits/stdtr1c++.h>
using namespace std;
#define ll long long
int main()
{
    int T;scanf("%d",&T);
    for(int kase=1;kase<=T;kase++)
    {
        ll n;scanf("%I64d",&n);n--;
        int sum=0;
        for(ll i=1;i*i<=n;i++)
        {
            if(!(n%i))
            {
                sum++; if(i*i!=n)sum++;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
