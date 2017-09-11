#include<bits/stdc++.h>
//题意明确：when given s1 and s2, finds the longest prefix of s1 that is a suffix of s2
//给出串s1,s2找出最长的子串 s1的前缀是s2的后缀
//输出串和长度
//思路把s2串接在s1串后面预处理新串的失配数组
// 记lens3 = lens1 + lens2
//
using namespace std;
const int maxn = (50000<<1)+5; //开小了超时
int Next[maxn];
char s1[maxn],s2[maxn];
int plen;
//next[j]=k 即k是在s2内长度为k的前缀是s2长度为j的前缀的后缀且s2[j]!=s2[i]的最大值
void getnext()
{
    int j = Next[0] = -1, i=0;
    while(i<plen)
    {
        while(~j && s1[i]!=s1[j])
            j = Next[j];
        Next[++i] = ++j;
    }
}

int main()
{
    while(scanf("%s%s",s1,s2)!=EOF)
    {
        int lens2 = strlen(s2);
        int lens1 = strlen(s1);
        strcat(s1,s2);
        plen = strlen(s1);
        getnext();
        int tmp = plen;

        while(Next[tmp]>lens1) tmp = Next[tmp];

        while(Next[tmp]>lens2) tmp = Next[tmp];

        if(Next[tmp])
        {
            for(int i=0;i<Next[tmp];i++)
                printf("%c",s1[i]);
            printf(" %d\n",Next[tmp]);
        }
        else printf("0\n");
    }
    return 0;
}