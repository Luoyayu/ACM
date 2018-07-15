#include <bits/stdc++.h>
//两个字符串的加法,输出长的最小的,如果一样输出字典序小的,注意字符串加法的可重叠
#define Debug(x) cout << #x << "= " << x << endl;
using namespace std;
const int maxn = 100005;
char s[maxn], p[maxn];
int Next[maxn];
void getnext(const char *x, int xlen) {
    int i = 0, j = Next[0] = -1;
    while (i < xlen) {
        if (j != -1 && x[i] != x[j])
            j = Next[j];
        else
            Next[++i] = ++j;
    }
}
int KMP(const char *s, int slen, const char *p, int plen) {
    int ans = 0;
    getnext(p, plen);
    int i = 0, j = 0;
    while (i < slen) {
        while (j != -1 && s[i] != p[j]) j = Next[j];
        i++, j++;
    }
    return (j == -1) ? 0 : j;  // j是匹配完时仍指向模式串(未进行j=0操作)的位置
}
int main() {
    while (scanf("%s %s", s, p) != EOF) {
        int slen = strlen(s), plen = strlen(p);
        int lsp = KMP(s, slen, p, plen);  //返回s在p串中可以接上的位置
        int lps = KMP(p, plen, s, slen);  //返回p在s串中可以接上的位置
        if (lsp > lps)                    // sp 好于 ps
        {
            s[slen - lsp] = '\0';  //截断s串
            printf("%s%s\n", s, p);
        } else if (lsp < lps) {
            p[plen - lps] = '\0';
            printf("%s%s\n", p, s);
        } else if (lsp == 0 || lps == 0) {
            string str1(s);
            str1 += p;
            string str2(p);
            str2 += s;
            cout << min(str1, str2) << endl;
        } else if (lsp == lps) {
            char t1;
            t1 = s[slen - lsp];
            s[slen - lsp] = '\0';
            string str1(s);
            str1 += p;
            s[slen - lsp] = t1;
            p[plen - lps] = '\0';
            string str2(p);
            str2 += s;
            cout << min(str1, str2) << endl;  //用cout都比转指针快!!!!
        }
    }
    return 0;
}
