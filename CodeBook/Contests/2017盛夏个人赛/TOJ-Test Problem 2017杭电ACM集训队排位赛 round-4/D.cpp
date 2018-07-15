#include<bits/stdc++.h>
//模拟路径
using namespace std;
const int maxn = 20000+7;
char str[4][maxn];
char temp[20],location[20];
int main()
{
    int m,cur,j;
    while(scanf("%d",&m)!=EOF)
    {
        cur=0;
        strcpy(str[0],"C:\\users\\godle");
        strcpy(str[1],"D:");strcpy(str[2],"E:");strcpy(str[3],"F:");
        while(m--)
        {
            scanf("%s",temp);
            if(!strcmp(temp,"cd"))
            {
                scanf("%s",location);
                if(!strcmp(location,".."))
                {
                    int Length = strlen(str[cur]);

                    for(j=Length-1;j>=0;j--)
                        if(str[cur][j]=='\\') break;

                    if(j>=0) str[cur][j]=0;
                }
                else
                    strcat(str[cur],"\\"),strcat(str[cur],location);
            }

            if(!strcmp(temp,"C:"))
                cur=0;
            else if(!strcmp(temp,"D:"))
                cur=1;
            else if(!strcmp(temp,"E:"))
                cur=2;
            else if(!strcmp(temp,"F:"))
                cur=3;
            printf("%s\n",str[cur]);
        }
    }
    return 0;
}
