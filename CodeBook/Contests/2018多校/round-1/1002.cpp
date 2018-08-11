#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;
// 题意: 定义括号平衡串为 1)空串 2）如果A,B平衡则AB平衡，3) 如果A平衡那么(A)平衡
// 现在给出一些字符串，可以重排这些字符串拼接成一个新串，问重排后最长平衡串的长度
// hint：平衡串不一定要连续 )()(()( 的最长平衡子串长度为4

// 思路: n的范围1e5, 字符串长度1e5,
// 括号匹配, 左括号匹配右括号,先完成自匹配, 然后剩余一堆未匹配的)(, 按一定顺序排序，尽可能多的消掉未匹配
const int maxn = 1e5 + 7;
char s[maxn];
struct node {
    int p, q;  // 左括号数量,右括号数量
} a[maxn];

int cmp(const node &x, const node &y) {  // 自定义排序比较两个字符串
    if (x.q >= x.p && y.q < y.p)
        return 0;  // [y x] x:))))))(  y:(((() x串的左括号大于右括号,y的右括号大于左括号
    if (x.q < x.p && y.q >= y.p)
        return 1;  // [x y] x:((((())  y:))))))( 与上相反
    if (x.q >= x.p && y.q >= y.p)
        return x.p > y.p;  // x:)))))(  y:))))))()    x的左括号大于右括号,
                           // y的左括号大于右括号, 按照右括号排序
    return x.q < y.q;  // 与上相反
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            scanf("%s", s);
            a[i].p = a[i].q = 0;
            int len = strlen(s);
            for (int j = 0; j < len; j++) {  // 先完成本串的自匹配
                if (s[j] == '(') a[i].p++;
                if (s[j] == ')') {
                    if (a[i].p > 0) {
                        a[i].p--, ans += 2;
                    } else a[i].q++;
                }
            }
        }

        sort(a, a + n, cmp);  // 排序剩下的子串
        int notMatchp = 0;    // 记录前面还有多少个(没匹配
        for (int i = 0; i < n; i++) {
            if (a[i].q > notMatchp) a[i].q = notMatchp;
            ans += a[i].q * 2;
            notMatchp = notMatchp - a[i].q + a[i].p;
        }
		cout << ans << endl;
    }
}
