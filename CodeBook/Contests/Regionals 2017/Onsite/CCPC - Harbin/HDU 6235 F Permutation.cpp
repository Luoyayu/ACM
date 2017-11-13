#include <bits/stdc++.h>
#ifdef local
#include "ACM.h"
#endif
using namespace std;
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n;scanf("%d",&n);
        for(int i=1;i<=n/2;i++)
        {
            if(i==1) printf("1");
            else printf(" %d",i);
            printf(" %d",n&1?i+n/2+1:n/2+i);
        }
        if(n&1)
            printf(" %d\n",n/2+1);
        else printf("\n");
    }
    return 0;
}
