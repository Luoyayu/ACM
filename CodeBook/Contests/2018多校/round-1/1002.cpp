#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;
// 题意: 定义括号平衡串为1)空串 2）如果A,B平衡则AB平衡，3) 如果A平衡那么(A)平衡
// 现在给出一些字符串，可以重拍这些字符串连接成一个新串，问重排后最长平衡串的长度
// 平衡串不一定要连续 )()(()( 平衡子串长为4

// 思路: 总感觉在哪儿做过，n的范围1e5,字符串长度1e5,
// 括号匹配嘛, 左括号匹配右括号,先自匹配,然后生一堆)(,按一定顺序排好即可
inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
const int maxn = 1e5 + 7;
char s[maxn];
struct node {
    int p, q;  // 左括号数量,右括号数量
} a[maxn];

int cmp(node x, node y) {  //自定义排序比较两个字符串
    if (x.q >= x.p && y.q < y.p)
        return 0;  // [y x] x:))))))(  y:(((()
                   // x串的左括号大于右括号,y的右括号大于左括号
    if (x.q < x.p && y.q >= y.p)
        return 1;  // [x y] x:((((())  y:))))))( 与上相反
    if (x.q >= x.p && y.q >= y.p)
        return x.p > y.p;  // x:)))))(  y:))))))()    x的左括号大于右括号,
                           // y的左括号大于右括号, 按照右括号排序
    return x.q < y.q;  // 与上相反
}
int main() {
    int t = read();
    while (t--) {
        int n = read();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            scanf("%s", s);
            a[i].p = a[i].q = 0;
            int len = strlen(s);
            for (int j = 0; j < len; j++) {  // 先完成本串的自匹配
                if (s[j] == '(') a[i].p++;
                if (s[j] == ')') {
                    if (a[i].p > 0) {
                        a[i].p--;
                        ans += 2;
                    } else
                        a[i].q++;
                }
            }
        }
        sort(a, a + n, cmp);  // 剩下的子串排序
        int notMatchp = 0;    // 记录前面还有多少个(没匹配
        for (int i = 0; i < n; i++) {
            if (a[i].q > notMatchp) a[i].q = notMatchp;
            ans += a[i].q * 2;
            notMatchp = notMatchp - a[i].q + a[i].p;
        }
        printf("%d\n", ans);
    }
}