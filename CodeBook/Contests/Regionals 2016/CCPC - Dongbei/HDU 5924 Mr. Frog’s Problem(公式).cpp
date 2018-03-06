#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//题意很明确给出a,b问(c,d)对数满足c,d在a,b之间且a/b+b/a<=c/d+d/c;
int main()
{
    int t;scanf("%d",&t);
    for(int kase=1;kase<=t;kase++)
    {
        ll a,b;scanf("%lld %lld",&a,&b);
        printf("Case #%d:\n",kase);
        if(a==b) 
        {
            printf("%lld %lld\n",a,b);
            continue;
        }
        
        

    }
}