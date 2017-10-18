#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define rep(i, s, t) for(int i = s;i <= t;i++)
#define rap(i, s, t) for(int i = s;i >= t;i--)
using namespace std;
int C[1005], D[1005];
int N, b;
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &N, &b);
        rep(i, 1, N)
            scanf("%d", &C[i]);
        rep(i, 1, N - 1)
            scanf("%d", &D[i]);
        int support = 0;
        int flag = 1;
        rep(i, 1, N - 1)
        {
            support += C[i];
            support -= D[i] * b;
            if(support < 0)
            {
                flag = 0;
                break;
            }
        }
        if(flag == 1)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}