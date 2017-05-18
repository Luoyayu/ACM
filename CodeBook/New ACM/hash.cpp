#include<stdio.h>
int main () {
    int n,m,i,j,first,a[3003],hash[10010]={0};
    while (scanf("%d%d",&n,&m) != EOF) 
    {
        for (i=0;i<n;i++)
         scanf("%d",&a[i]);

        for (i=0;i<n;i++)
            for (j=i+1;j<n;j++) 
                hash[a[i]+a[j]] ++;
        first = 1;
        for (i=10000;i>=0;i--) 
        {
            if (hash[i])
            {
                if (m>=hash[i]) {
                    for (j=1;j<=hash[i];j++) 
                    {
                        if (first)
                            first = 0;
                         else 
                         	printf(" ");
                        printf("%d",i);
                    }
                    m -= hash[i];
                }
                else 
                {
                    for (j=1;j<=m;j++)
                    {
                        if (first)
                            first = 0;
                        else printf(" ");
                        printf("%d",i);
                    }
                    printf("\n");
                    break;
                }
            }
        }
    }
    return 0;
}