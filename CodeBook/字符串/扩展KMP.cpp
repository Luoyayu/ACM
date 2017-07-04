//扩展KMP 可以在O(m+n)时间内求得s1的任意后缀与字符串s2的最长公共前缀(LCP)的长度
//此处的next[]为s2的任意后缀与s2的LCP kmpnext[i]=j 意思是s2的以s2[i]为起始的后缀与s2本身的LCP的长度
//ex[i]就表示以s1[i]为起始的后缀与s2的LCP的长度
#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10;
int _next[maxn],ex[maxn];
char s1[maxn],s2[maxn];
int ls1,ls2;
void getnext(char *T){// _next[i]: 以第i位置开始的子串 与 T的公共前缀 
    int i,length = strlen(T);
    _next[0] = length;
    for(i = 0;i<length-1 && T[i]==T[i+1]; i++);
    _next[1] = i;
    int a = 1;
    for(int k = 2; k < length; k++)
    {
        int p = a+_next[a]-1, L = _next[k-a];
        if( (k-1)+L >= p ){
            int j = (p-k+1)>0? (p-k+1) : 0;
            while(k+j<length && T[k+j]==T[j]) j++;// 枚举(p+1，length) 与(p-k+1,length) 区间比较
            _next[k] = j, a = k;
        }
        else _next[k] = L;
    }
}
void getextand(char *S,char *T)
{
    memset(_next,0,sizeof(_next));
    getnext(T);
    int Slen = strlen(S), Tlen = strlen(T), a = 0;
    int MinLen = Slen>Tlen?Tlen:Slen;
    while(a<MinLen && S[a]==T[a]) a++;
    ex[0] = a, a = 0;
    for(int k = 1; k < Slen; k++)
    {
        int p = a+ex[a]-1, L = _next[k-a];
        if( (k-1)+L >= p )
        {
            int j = (p-k+1)>0? (p-k+1) : 0;
            while(k+j<Slen && j<Tlen && S[k+j]==T[j] ) j++;
            ex[k] = j;a = k;
        }
        else ex[k] = L;
    }
}
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%s%s",s1,s2);
        ls1=strlen(s1);
        ls2=strlen(s2);
        getextand(s1,s2);

    }
}