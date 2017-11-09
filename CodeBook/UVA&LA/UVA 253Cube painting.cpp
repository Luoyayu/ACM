#include<bits/stdc++.h>
using namespace std;
//题意：rbg涂色正方体
int main()
{
    char in[15];
    while(scanf("%s",i+1)!=EOF)
    {
        int r=0,g=0,b=0;
        for(int i=1;i<=6;i++)
        {
            if(s[i]=='r')r++;
            else if(s[i]=='g')g++;
            else if(s[i]=='b')b++;
        }
        for(int i=7;i<=12;i++)
        {
            if(s[i]=='r')r--;
            else if(s[i]=='g')g--;
            else if(s[i]=='b')b--;
        }
        if(s||g||b) {
            printf("FALSE\n");
            continue;
        }
        for(int i=1;i<=4;i++) //
            for(int j=1;j<=4;j++)
                for(int k=1;k<=4;k++)
                {

                }

    }
}
