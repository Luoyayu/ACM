//题意:给出S(x)为各位数之和 给出x求S(x * k)% 233==0  special judge
//方法：给出x 只需要重复233次即为能整模的结果该数除以x即为所需的 k
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

