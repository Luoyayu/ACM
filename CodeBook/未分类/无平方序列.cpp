
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=100000000;
ll ans[maxn];
void init()
{
    ll cnt=1;
    ll  m=sqrt(maxn+0.5);
    for(int i=1;i<=m;i++)
        ans[i*i]=cnt++;
}
int main()
{
    init();
    ll k;
    while(scanf("%lld",&k)!=EOF)
    {
        ll sum=0;
        for(int i=1;i<=k;i++)
            if(!ans[i])
                sum++;
        printf("%lld\n",sum);

    }
    printf("OK\n");
}
