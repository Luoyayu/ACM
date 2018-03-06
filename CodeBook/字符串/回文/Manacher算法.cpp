//马拉车算法 找字符串中的最长回文串
//使用分隔符将原串变为奇数长度的字符串T
//使用len数组表示以字符 T[i]为中心的最长回文串的最右字符到 T[i]的长度; 那么回文串的长度为len*2-1
//例如T[i]为中心的最长回文字串T[tot,r], 则len[i]=r-i+1;
// len[i]-1就是该回文串在原串S中的长度易证
//计算len[i]时利用 len[j] 0<=j<i ,设P为之前计算中最长回文串的右端点的最大值，设取得这个最大值len[i]的i为pos
#include<bits/stdc++.h>
using namespace std;
const int maxn= 500000+55;
char str[maxn<<1];//T串
int Len[maxn<<1];//len数组
int MID = -1;
void Manacher(char s[], int len)
{
    int tot=0;
    str[tot++]='$';
    str[tot++]='#';
    for (int i = 0; i < len; i++)
    {
        str[tot++]=s[i];
        str[tot++]='#';
    }
    str[tot]=0;
    int mx=0,id=0;
    for(int i=0;i<tot;i++)
    {
        Len[i]=mx>i?min(Len[id*2-i],mx-i):1;
        while (str[i+Len[i]]==str[i-Len[i]]) Len[i]++;
        if(i+Len[i]>mx)
        {
            mx=i+Len[i];
            id=i;
        }
    }
}
char s[maxn];
int main()
{
    while(scanf("%s",s)==1)
    {
        int len=strlen(s);
        Manacher(s,len);
        int ans=0;
        for(int i=0;i<len<<1+2;i++)
            ans=max(ans,Len[i]-1);
        printf("%d\n",ans);

    }
    return 0;
}
