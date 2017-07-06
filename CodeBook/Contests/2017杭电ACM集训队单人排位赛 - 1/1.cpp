#include<bits/stdc++.h>
const int maxn=1e6+7;
using namespace std;
int lcm(int a,int b)
{
    return a*b/__gcd(a,b);
}
int main()
{
    int n,m,t;
    //freopen("C:\\Users\\gavin\\Desktop\\input.txt","r",stdin);

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        int LCM=m/__gcd(n,m)*n;
        printf("test1:%d\n",LCM/n);

        printf("test2:%d\n\n",lcm(m%n,m));
    }
    return 0;
}

