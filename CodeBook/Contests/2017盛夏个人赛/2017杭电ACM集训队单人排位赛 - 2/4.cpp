#include<bits/stdc++.h>
#define Debug(x) cout<<#x<<"= "<<x<<endl;
char s[]=" QWERTYUIOP ASDFGHJKL ZXCVBNM ";
using namespace std;
int main()
{
    int t;scanf("%d",&t);getchar();
    while(t--)
    {
        int len=strlen(s),i;
        char letter,dir[10];
        scanf("%c %s",&letter,dir);getchar();
        for(i=0;i<len;i++)
            if(letter==s[i]) break;
        if(dir[0]=='R') i++;
        else i--;
        if(s[i]==' ')
            printf("No letter.\n");
        else
            printf("%c\n",s[i]);
    }
    return 0;
}
