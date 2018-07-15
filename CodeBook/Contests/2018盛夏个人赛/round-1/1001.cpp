#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 7;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        char s[22];
        scanf("%s", s);
        int len = strlen(s);
        if (s[0] != 'L' || s[1] != 'Q' || len != 10) {
            printf("NO\n");
            continue;
        }
        for (int i = 2; i < 10; i++) {
            if (s[i] < '0' || s[i] > '9') {
                printf("NO\n");
                goto L;
            }
        }
        printf("YES\n");
    L:
        continue;
    }
}

/*
Problem Description
莱特与瑞秋毕业了，他们决定在内蒙创业成立一家畜牧业公司，创业第一步：他们希望给公司里的每一只羊一个编号。
编号的命名规则如下：
1.长度为10位；
2.前两位必须为”LQ”；
3.后八位必须为数字；
现在有若干个字符串，希望你写一个程序判断它是不是一个合法编号。


Input
第一行一个T(1≤T≤20)代表数据组数。
每组测试数据有一个字符串s(1≤|s|≤20)，s只包含数字和大写英文字母，代表等待判断的字符串。


Output
如果编号合法输出”YES”，否则输出”NO”。


Sample Input
3
LQ12345678
LQ123
QL12345678


Sample Output
YES
NO
NO


Source
陈都测试2
*/