//1000000000 1e9
#include<bits/stdc++.h>
using namespace std;
const int maxn= 1e9+7;
const int inf = 0x3fffffff;

typedef long long ll;
int main()
{
    int n,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int cnt=0;
        int flag=0;
        while(n!=1)
        {
            if(n%2==1)
            {
                flag=1;
                break;
            }
            else
                n/=2;
        }

       if(flag==1)
        printf("Alice\n");
       else
        printf("Bob\n");

    }
}
