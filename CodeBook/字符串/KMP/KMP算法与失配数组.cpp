// KMP算法O(n+m)，O(m)预处理失配函数递归Next[]
// O(n)得到匹配个数,第一次匹配位置,循环节 Next求解原理假定模式串ABCDABCE
// 已知Next[j]=k=2;pi=pj=C->Next[j+1]=next[j]+1=3 if
// pi!=pj采用模式串自我匹配递归next[next[···]] next含义：next[j]==k,
// 表示s2[0...k-1] == s2[j-k...j-1] && s2[j]!=s2[k]
// 即k是在s2内长度为k的前缀是s2长度为j的前缀的后缀且s2[j]!=s2[i]的最大值
// next[j]=-1
// 模式串T中下标为j的字符，如果与首字符相同且j前面l-k个字符与开头l-k个字符不相等或相等但t[k]==t[j]
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 5;
char s[maxn], p[maxn];
int Next[maxn];
void getfailure(const char *x, int len)  //失配函数build
{
    int j = Next[0] = -1, i = 0;
    while (i < len) {
        while (~j && x[i] != x[j])  // x[i]表前缀，p[j]表后缀匹配失败
            j = Next[j];
        //此处有问题 ：应该是 Next[++i] = ++j;一行代码
        if (x[++i] ==
            x[++j])  //***************************************************
            Next[i] = Next[j];  //**去掉注释该此行位 Next[++i] =
                                //++j可用来求最小循环节**
        else
            Next[i] = j;  //***************************************************
    }
}
int KMP(int plen, int slen) {
    int ans = 0;
    getfailure(p, plen);
    int i = 0, j = 0;
    while (i < slen) {
        while (
            j != -1 &&
            s[i] !=
                p[j])  // j!=-1表示当前字符匹配失败,i不变,j=Next[j];模式串向右移动位数为：
            //已匹配字符数-失配字符的上一个字符对应的最大长度值,即=j-Next[j];
            j = Next[j];
        i++;
        j++;               //成功i,j都移动1位
        if (j >= plen)     //匹配到达模式串末尾
            ans++, j = 0;  // j=0
                           // 不允许重叠的匹配,否则j会继续根据next[j]跳转,模式串匹配j重新移到串首,ans++
                           // 匹配数++
    }
    return ans;
}
int main()  //求模式串不重叠在原串中出现了几次
{
    while (scanf("%s", s) != EOF) {
        if (s[0] == '#') break;
        scanf("%s", p);
        int plen = strlen(p);
        int slen = strlen(s);
        int ans = KMP(plen, slen);
        printf("%d\n", ans);
    }
    return 0;
}
// KMP 算法的再理解
// S：a b a c a a b a c a b a c a b a a b b
// T：a b a c a b
//原串和模式串匹配时,一旦失陪模式串根据失配数组尽可能的向右跳转，
//找出最长 相同的前缀和后缀使得移动的位置重叠
// 失配数组的意义是 若Next[i] = k 则 k是在T 中长度为k
//第一次匹配时S[5]!=T[5]