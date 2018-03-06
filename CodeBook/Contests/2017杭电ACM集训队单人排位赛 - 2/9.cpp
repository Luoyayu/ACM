#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
char s1[maxn],s2[maxn];
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        getchar();
        scanf("%s%s",s1,s2);
        int len=strlen(s1),cnt=0;
        int flag=0,cmp[1005]={0};
        for(int i=0;i<len;i++)
            if(++cmp[s1[i]-'a']>1){flag=1;break;}//all 1
        for(int i=0;i<len;i++)
            if(s1[i]!=s2[i]) cnt++;//cnt==2|| flag=1&&cnt==0
        sort(s1,s1+len);sort(s2,s2+len);
        if(!strcmp(s1,s2)&&  !flag  && cnt==2)
            printf("YES\n");
        else if(   !strcmp(s1,s2)&&flag&& !cnt  || cnt==2)//gg ()||()
            printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
