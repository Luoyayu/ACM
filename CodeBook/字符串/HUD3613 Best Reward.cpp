//扩展KMP/Manacher算法 回文串判定
//扩展KMP算法：应用与给定文本串S，模式串P，对于每个S[i]求出S[i...Slen-1]与T的最长公共前缀长度，
//记作extend[i]，如果S在某个位置i有entend[i]=m，则可知在S中好到了匹配串T，并且匹配的首位置为i,匹配了模式串extend[i]个位置
//
#include<bits/stdc++.h>
using namespace std;
const int maxn= 500005;
int val[27];
char p[maxn],s2[maxn];
int len;
int Next[maxn];
int sum[maxn];
int pre
void getnext()
{
    int i=0,j=-1;
    Next[0]=-1;
    while(i<len-1)
    {
        if(j==-1||p[j==p[i])
            Next[++i]=++j;
        else
            j=Next[j];
    }
}
int KMP()
{
    int i=0,j=0;
    while(i<len)
    {
        if(j==-1||p[i]==p[j])
            i++,j++;
        else
            j=Next[j];
    }
    return i;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        for(int i=1;i<=26;i++)
            scanf("%d",&val[i]);
        scanf("%s",p);
        len=strlen(p);
        for(int i=0;i<len;i++)



    }
}
