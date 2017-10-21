#include<bits/stdc++.h>
using namespace std;
//簡單構造,由式子lcm(a,b)>=max(a,b) 當且僅當a|b或b|a時取等號，於是我們可以推理出
//MIN ans = max(1,b) b<=n即構造出的最小生成樹是由1放射形成的
int main()
{
    int t;scanf("%d",&t);
    for(int kase=1;kase<=t;kase++)
    {
        int n;scanf("%d",&n);
        printf("Case #%d: %lld\n",1LL*(1+n)*n/2-1);
    }
    return 0;
}