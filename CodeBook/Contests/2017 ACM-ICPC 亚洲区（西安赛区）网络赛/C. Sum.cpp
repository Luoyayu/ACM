#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=100010;
int main()
{
    int t,x;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&x);
        int cnt=0;
        while(x>=10)
        {
            x=x/10;
            cnt++;
        }
        printf("1");
        for(int i=2;i<=233;i++)
        {
                for(int j=1;j<=cnt;j++)
                    printf("0");
                printf("1");
        }
        printf("\n");

    }
    return 0;
}

