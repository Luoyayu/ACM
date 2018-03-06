#include<cstdio>
#include<cstring>
#include<map>
#include<set>
#include<cmath>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 1e6 + 7;
typedef long long ll;
int n,m,t;
int main()
{
    int t;scanf("%d",&t);
    int kase  = 1;
    while(t--)
    {
        int n;scanf("%d",&n);
        int cnt = 0, a = 1;
        while(n>=a)
        {
            n-=a;a*=2;
            cnt++;
        }
        if(n!=0) cnt++;
        printf("Case %d: %d\n",kase++,cnt);
    }
    return 0;
}
