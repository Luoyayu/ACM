//题巨难理解
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define  ok ios::sync_with_stdio(false)
int main()
{
    ok;
    char longer[200];
    while(scanf("%s",longer)!=EOF)
    {
        printf("300 420 moveto\n");
        printf("310 420 lineto\n");
        int len=strlen(longer);
        int X=310,Y=420;
        int flag=1;
        for(int i=0;i<len;i++)
        {
            switch (flag)//记录正对方向
            {
                case 1:
                {
                    if(longer[i]=='V')
                        flag=2,Y+=10;
                    else
                        flag=4,Y-=10;
                    break;
                }
                case 2:
                {
                    if(longer[i]=='V')
                        flag=3,X-=10;
                    else
                        flag=1,X+=10;
                    break;
                }
                case 3:
                {
                    if(longer[i]=='V')
                        flag=4,Y-=10;
                    else
                        flag=2,Y+=10;
                    break;
                }
                case 4:
                {
                    if(longer[i]=='V')
                        flag=1,X+=10;
                    else
                        flag=3,X-=10;
                    break;
                }
            }
            printf("%d %d lineto\n",X,Y);
        }
        printf("stroke\nshowpage\n");
    }
    return 0;
}
