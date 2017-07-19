#include<cstdio>
#include<cstring>
#include<map>
#include<set>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 1e4 + 7;
const int mod = 1e9 + 7;
typedef long long ll;
int a[maxn*2];
int n,m,t;
int main()
{
    scanf("%d",&t);
    for(int kase = 1;kase<=t;kase++)
    {
        int n;scanf("%d",&n);
        int N = n*2;
        for(int i = 1;i<=N;i++)
            scanf("%d",&a[i]);
        printf("Case %d: %.2f\n",kase,1.0*n/2);
    }
    return 0;
}
