#include<bits/stdc++.h>
using namespace std;
const int maxn = 300000;
char str[maxn];
char str1[maxn<<1];
//字符串的最小循环表示既字典序最小的表示，两个字符串相等当且仅当最小循环表示相等
int minRe(char s[])//s为扩展一倍的带求字符串,返回最小表示法的下标 O(len)
{
    int len = strlen(str);
    int i=0,j=1,k=0;
    while(i<len&j<len&&k<len)
    {
        if(s[i+k]==s[j+k])k++;
        else
        {
            if(s[i+k]<s[j+k]) j+=k+1;
            else i+=k+1;
            k=0;
            if(i==j) j++;
        }
    }
    return min(i,j);
}
int main()
{
    while(scanf("%s",str)!=EOF)
    {
        int len = strlen(str);
        //for(int i=1;i<=len;i++)
            //str1[i-1]=(str[i%len]-str[i-1]+8)%8+'0';

        for(int i=0;i<=len-2;i++)
            str1[i]=(str[i+1]-str[i]+8)%8+'0';

        str1[len-1]=(str[0]-str[len-1]+8)%8+'0';

        str1[len]='\0';
        int e = minRe(str1);
        for(int i=0;i<len;i++)
            printf("%c",str1[(e+i)%len]);
        printf("\n");
    }
    return 0;
}