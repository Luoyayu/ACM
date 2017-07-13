#include<bits/stdc++.h>
//又SB了
using namespace std;
int main()
{
    int n;// H 先 每次拿n%x==0 x个
    while(scanf("%d",&n)!=EOF)
    {
        if(n&1)
            printf("G\n");
        else
            printf("H\n");
    }
    return 0;
}
