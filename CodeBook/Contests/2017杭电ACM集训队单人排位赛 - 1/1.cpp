#include<bits/stdc++.h>
const int maxn=1e6+7;
using namespace std;
int main()
{
    int n,m;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        int GCD=m*n/__gcd(n,m);
        printf("%d\n",GCD/n);
    }
    return 0;
}
