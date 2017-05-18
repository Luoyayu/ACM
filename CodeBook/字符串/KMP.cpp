//KMP算法O(n+m)，预处理失配函数递归Next[]
//Next求解原理假定模式串ABCDABCE 已知Next[j]=k=2;pi=pj=C->Next[j+1]=next[j]+1=3
//if pi!=pj采用模式串自我匹配递归next[next[···]]
//next含义：next[0]=-1模式串第一个字符模式值=-1
//next[j]=-1 模式串T中下标为j的字符，如果与首字符相同且j前面l-k个字符与开头l-k个字符不相等或相等但t[k]==t[j]
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <queue>
using namespace std;
const int maxn = 1000 + 5;
char s[maxn], p[maxn];
int Next[maxn];
//e.g. ABCDABD
void getfailure(const char *x, int len)//失配函数build
{
    int j = -1,i = 0;
    Next[0] = -1;
    while (i < len)
    {
        while (j!= -1 &&  x[i] != x[j])//x[i]表前缀，p[j]表后缀匹配失败
            j = Next[j];
        i++, j++;
        if (x[i] == x[j])
            Next[i] = Next[j];
        else
            Next[i] = j;
    }
}
int KMP(const char *p, int plen, const char *s, int slen)//核心
{
    int ans = 0;
    getfailure(p, plen);
    int i =0,j = 0;
    while (i < slen)
    {
        while (j!= -1 && s[i] != p[j])//j!=-1表示当前字符匹配失败,i不变,j=Next[j];模式串向右移动位数为：
            //已匹配字符数-失配字符的上一个字符对应的最大长度值，此处即;失配字符所在的位置-失配字符对应的Next值即=j-Next[j];
            j = Next[j];
        i++; j++;
        if (j >= plen)
            ans++,j = 0;
    }
    return ans;
}
int main()
{
    while (scanf("%s", s)!=EOF)
    {
        if (s[0] == '#') break;
        scanf("%s", p);
        int ans = KMP(p, strlen(p), s, strlen(s));
       printf("%d\n", ans);
    }
    return 0;
}
