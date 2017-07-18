//实在不行画图
#include<bits/stdc++.h>
using namespace std;
int main()
{

    int a[5][5];
    for(int t=1;t<=4;t++)
    {
        scanf("%d%d%d%d",&a[t][1],&a[t][2] ,&a[t][3] ,&a[t][4]);
    }
    if(a[1][4])
    {
        if(a[1][1]||a[1][2]||a[1][3]|| a[3][2]||a[2][1]||a[4][3])
        {
            printf("YES\n");
            return 0;
        }
    }
    if(a[2][4])
    {
        if(a[2][1]||a[2][2]||a[2][3]||a[1][3]||a[3][1]||a[4][2])
        {

            printf("YES\n");
            return 0;
        }
    }
    if(a[3][4])
    {
        if(a[3][1]||a[3][2]||a[3][3]||a[1][2]||a[2][3]||a[4][1])
        {

            printf("YES\n");
            return 0;
        }

    }
    if(a[4][4])
    {
        if(a[4][1]||a[4][2]||a[4][3]||a[1][1]||a[2][2]||a[3][3])
        {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}
