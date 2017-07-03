#include<bits/stdc++.h>
using namespace std;
int main()
{
    __int64 n, a, b, c, d;//所有扶左手的做左边，扶右手的左右边，然后中间扶与不扶的交替做
    while(scanf("%I64d%I64d%I64d%I64d%I64d", &n, &a, &b, &c, &d)!=EOF)
    {
        if(a+b>=n)
            printf("%I64d\n", n);
        else
        {
            __int64 x = n-a-b;
            printf("%I64d\n", min(n, min(  (x+1)/2, c) + d+a+b));
        }
    }
    return 0;
}
