///蒟蒻×999
#include <bits/stdc++.h>
using namespace std;
int x[101];
int main()
{
    int n,k;scanf("%d %d",&n,&k);
    int xt=0;
    for(int i=1;i<=n;i++)
    {
        int cur;scanf("%d",&cur);
        x[i]=cur+xt;//可以把多余的全都存到下一天里
        if(x[i]>8)
        {
            xt = x[i]-8;
            x[i]=8;
        }
        else xt=0;//！！！忘记归 0 
    }
    for(int i=1;i<=n;i++) {
        k -= x[i];
        if(k<=0) {
            printf("%d\n", i);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}
