#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    while(scanf("%d %d",&a,&b)!=EOF)
    {
        int cnt=1;
        while(1)
        {
            a-=cnt++;
            b-=cnt++;
            if(b<=0&&a>0)
            {
                printf("Vladik\n");
                break;
            }
            if(a<=0)
            {
                printf("Valera\n");
                break;
            }
        }
    }
    return 0;
}
