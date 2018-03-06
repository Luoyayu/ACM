#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    for(int kase=1;kase<=n;kase++)
    {
        int a,b;scanf("%d%d",&a,&b);
        printf("%d\n",max(a,b)*2+min(a,b));
    }
    return 0;
}