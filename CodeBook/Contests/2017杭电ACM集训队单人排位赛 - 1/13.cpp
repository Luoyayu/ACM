#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n&1||n==2)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
