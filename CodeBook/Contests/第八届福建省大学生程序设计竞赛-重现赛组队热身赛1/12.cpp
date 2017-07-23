#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
char str[4][4];
int main()
{
    int t;scanf("%d",&t);getchar();
    while(t--)
    {
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
               scanf("%c",&str[i][j]),getchar();

        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
                printf("%c",str[i][j]);
            printf("%\n");
        }
    }
    return 0;
}
