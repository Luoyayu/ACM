#include<bits/stdc++.h>
const int maxn=1e6+7;
using namespace std;
int main()
{
    int n,m,t;
    //freopen("C:\\Users\\gavin\\Desktop\\input.txt","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        int lcm=m/__gcd(n,m)*n;
        printf("%d\n",lcm/n);
    }
    return 0;
}

