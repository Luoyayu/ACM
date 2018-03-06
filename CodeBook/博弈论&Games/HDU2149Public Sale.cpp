#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m,n;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        if(n>=m)
        {
            for(int i=m;i<n;i++)
                printf("%d ",i);
            printf("%d\n",n);
        }
        else if(m%(n+1)==0)
            printf("none\n");
        else
        {
            int flag=0;
            for(int i=1;i<=n;i++)
            {

                if((m-i)%(n+1)==0)
                {
                    if(flag)
                        printf(" ");
                    flag=1;
                    printf("%d",i);
                }

            }
            printf("\n");
        }
    }
    return 0;
}
