#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
LL stan[23] = {
 1, 8, 49, 288, 1681, 9800, 57121, 332928, 1940449, 11309768, 65918161, 384199200, 2239277041, 13051463048, 76069501249, 443365544448, 2584123765441, 15061377048200, 87784138523761, 511643454094368, 2982076586042449, 17380816062160328, 101302819786919521};
int main()
{
    int t;
    scanf("%d", &t);
    int kase = 1;
    while(t--)
    {
        LL n;
        scanf("%lld", &n);
        for(int i = 0;i <= 22;i++)
            if(stan[i] >= n)
            {
                printf("Case #%d: %lld\n", kase++, stan[i]);
                break;
            }
    }
    return 0;
}