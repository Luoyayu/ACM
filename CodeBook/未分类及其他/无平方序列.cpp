#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long llu;
const int maxn=100000000;
int ans[maxn];
void init()
{
    llu cnt=1;
    llu  m=sqrt(maxn+0.5);
    for(llu i=1;i<=m;i++)
        ans[cnt++] = i*i;
}
int main()
{
    llu k;
    //init();
    while(scanf("%llu",&k)!=EOF)
    {
        llu sum=0;
        for(int i=1;i<=10000;i++)
            if(k>=ans[i])
                {
                    sum++;
                    break;
                }
        printf("%llu\n",k+sum);

        /*for(llu i=1;i<=k;i++)
            if(ans[i])
                sum++;
        printf("%llu,",i);
        printf("%lld\n",sum);*/

    }
    printf("OK\n");
}
