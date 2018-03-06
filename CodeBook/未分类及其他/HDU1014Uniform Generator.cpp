
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int step,mod;
    while(scanf("%d%d",&step,&mod)!=EOF)
    {
        if(__gcd(step,mod)==1)
        {
            printf("%10d%10d    Good Choice\n\n",step,mod);
        }
        else
            printf("%10d%10d    Bad Choice\n\n",step,mod);
    }
    return 0;
}
