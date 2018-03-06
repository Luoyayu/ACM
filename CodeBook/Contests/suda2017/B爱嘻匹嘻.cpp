#include<bits/stdc++.h>
using namespace std;
const int maxn=1000+7;
char str[maxn];
int main()
{
    int t;cin>>t;
    while (t--)
    {

        scanf("%s",str+1);
        int len=strlen(str+1);
        bool flag=0;
        for(int L=4; L<=len; L++)
        {
            if(flag)
                break;
            for(int j=1; j<=len-L+1; j++)
            {
                if(flag)
                    break;

                bool flag1=0,flag2=0;
                int  cnt=0;

                for(int i=j;i<=j+L-1;i++)
                {
                    if(str[i]=='I') flag1=1;
                    else if(str[i]=='P') flag2=1;
                    else if(str[i]=='C') cnt++;

                    if(flag1&&flag2&&cnt>=2)
                    {
                        printf("%d\n",L);
                        //printf("%d--%d\n",j,i);
                        flag=1;
                    }
                    if(flag)
                        break;
                }
            }
        }
        if(flag==0)
            printf("-1\n");
    }
    return  0;
}
