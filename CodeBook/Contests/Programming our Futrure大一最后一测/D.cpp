#include<bits/stdc++.h>
using namespace std;
char a[20000];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",a);
        int len = strlen(a);
        for(int i=0;i<len;i++)
        {

            if(a[i]=='&'&&a[i+1]=='l')
           {
                printf("%c",'<'),i+=3;
                continue;
           }
            else if(a[i]=='&'&&a[i+1]=='g')
           {
               printf("%c",'>'),i+=3;
               continue;
           }

            else if(a[i]=='&'&&a[i+1]=='q')
            {
                printf("%c",'"'),i+=5;
                continue;
            }

            else if(a[i]=='&'&&a[i+1]=='a')
            {
                printf("%c",'&'),i+=4;
                continue;
            }
            else if(a[i]=='&'&&a[i+1]=='n')
            {
                printf("%c",' '),i+=5;
                continue;
            }
            else
                printf("%c",a[i]);

        }
        printf("\n");
    }
    return 0;
}
