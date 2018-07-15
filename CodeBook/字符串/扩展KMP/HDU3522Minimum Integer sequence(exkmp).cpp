//字符串好题
#include <bits/stdc++.h>
#define Debug(x) cout << #x << " = " << x << endl;
//题意:给出大数A,B,将B插入A中,求最小的插入后的值
//转换问题为字符串的字典序大小比较 思路:明确ex_KMP对于s1
//s2,可以求出相应kmpnext：s2的任意后缀与s2自身的LCP;ex:s1的任意后缀与s2的LCP(next与s2有关,ex与s1有关,都是与s2的LCP)
using namespace std;
const int maxn = 100000 + 10;
int _next[maxn], ex[maxn];
char s1[maxn], s2[maxn];
int ls1, ls2;
void getnext(char *T)  // _next[i]: 以第i位置开始的子串 与 T的公共前缀
{
    int i, length = strlen(T);
    _next[0] = length;
    for (i = 0; i < length - 1 && T[i] == T[i + 1]; i++)
        ;
    _next[1] = i;
    int a = 1;
    for (int k = 2; k < length; k++) {
        int p = a + _next[a] - 1, L = _next[k - a];
        if ((k - 1) + L >= p) {
            int j = (p - k + 1) > 0 ? (p - k + 1) : 0;
            while (k + j < length && T[k + j] == T[j])
                j++;  // 枚举(p+1，length) 与(p-k+1,length) 区间比较
            _next[k] = j, a = k;
        } else
            _next[k] = L;
    }
}
void getextand(char *S, char *T) {
    memset(_next, 0, sizeof(_next));
    getnext(T);
    int Slen = strlen(S), Tlen = strlen(T), a = 0;
    int MinLen = Slen > Tlen ? Tlen : Slen;
    while (a < MinLen && S[a] == T[a]) a++;
    ex[0] = a, a = 0;
    for (int k = 1; k < Slen; k++) {
        int p = a + ex[a] - 1, L = _next[k - a];
        if ((k - 1) + L >= p) {
            int j = (p - k + 1) > 0 ? (p - k + 1) : 0;
            while (k + j < Slen && j < Tlen && S[k + j] == T[j]) j++;
            ex[k] = j;
            a = k;
        } else
            ex[k] = L;
    }
}
//用最长公共前缀可以O(1)判断第一个不相同的位置
bool smaller(int i, int j)  //判断将s2插入到s1的第i位是否插入到第j位小
{
    if (ex[j] < i - j) return s1[j + ex[j]] < s2[ex[j]];
    if (_next[i - j] < ls2 - (i - j))
        return s2[_next[i - j]] < s2[i - j + _next[i - j]];
    if (_next[ls2 - (i - j)] < (i - j))
        return s2[ls2 - (i - j) + _next[ls2 - (i - j)]] <
               s2[_next[ls2 - (i - j)]];
    return false;
}
int main() {
    while (scanf("%s%s", s1, s2) != EOF) {
        ls1 = strlen(s1), ls2 = strlen(s2);
        getextand(s1, s2);
        int ans = 0;  //插入位置从第0位算起
        for (int i = 0; i < ls1; i++) {
            if (smaller(i + 1, ans))  //如果插入到第i+1位比插入到第ans位小的话
                ans = i + 1;  //新的可行位置
        }
        //占位[ans,ans+ls1]
        for (int i = 0; i < ans; i++) printf("%c", s1[i]);
        printf("%s", s2);
        for (int i = ans; i < ls1; i++) printf("%c", s1[i]);
        printf("\n");
    }
    return 0;
}