//扩展KMP 可以在O(m+n)时间内求得s1的任意后缀与字符串s2的最长公共前缀(LCP)的长度
//此处的next[]为s2的任意后缀与s2的LCP kmpnext[i]=j 意思是s2的以s2[i]为起始的后缀与s2本身的LCP的长度
//ex[i]就表示以s1[i]为起始的后缀与s2的LCP的长度
#include<bits/stdc++.h>
using namespace std;
int kmpnext[maxn],ex[maxn];
char s1[maxn],s2[maxn];
int exkmp()
{
    int i,j,p;
    int s1len=strlen(s1),s2len=strlen(s2);
    for(i=0,j=0,p=-1,s1<=s1len;i++,j++,p--)
    {
        if(p==-1)
        {
            j = 0;
            do
                p++;
            while(i+p<=s1len&&s1[i+p]==s2[j+p]);
            ex[i]=p;
        }
        else if(kmpnext[j]<p) ex[i]=kmpnext[j];
        else if(kmpnext[j]>p) ex[i]=p;
        else
        {
            j=0;
            while(i+p<=s1len && s1[i+p]==s2[j+p])
                p++;
            ex[i]=p;
        }
    }
    ex[i]=0;
}
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%s%s",s1,s2);
        exkmp(s2,s2,kmpnext,kmpnext+1);//求出s2的kmpnext
        exkmp(s1,s2,kmpnext,ex);//求出ex

    }
}
