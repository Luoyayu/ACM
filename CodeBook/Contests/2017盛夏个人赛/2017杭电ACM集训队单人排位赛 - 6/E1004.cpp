#include<bits/stdc++.h>
using namespace std;
int a[110];
int b[110];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
            scanf("%1d",&a[i]);
        for(int i=1;i<=n;i++)
            scanf("%1d",&b[i]);
        sort(a+1,a+n+1);sort(b+1,b+n+1);
        int flag1 = a[1]>b[1]?1:-1;//flag = 1 严格大于序列 a>b

        if(a[1]==b[1])
       {
           printf("NO\n");
            continue;
       }
        if(flag1==1)
        {
            bool flag2 = 1;
            for(int i=2;i<=n;i++)
            {
                if(b[i]>=a[i])
                {
                    flag2 = 0;
                    break;
                }
            }
            if(flag2)
                printf("YES\n");
            else
                printf("NO\n");
        }
        else//a<b
        {
            bool flag2 = 1;
            for(int i=2;i<=n;i++)
            {
                if(b[i]<=a[i])
                {
                    flag2 = 0;
                    break;
                }
            }
            if(flag2)
                printf("YES\n");
            else
                printf("NO\n");
        }

    }
    return 0;
}
