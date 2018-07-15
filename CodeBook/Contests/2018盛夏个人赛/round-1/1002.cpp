#include <bits/stdc++.h>
using namespace std;

const int maxn = 2222;
int a[maxn];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        memset(a, 0, sizeof(a));
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            a[i] = x + y; // 记录肉熟的时刻
        }
        sort(a, a + n);
        int cur = a[0], ans = 1;
        for (int i = 1; i < n; i++)
            if (cur + m <= a[i]) {
                cur = a[i];
                ans++;
            }
        printf("%d\n", ans);
    }
}

/*
Problem Description
内蒙的羊由于生长的地域和气候的不同，产出的羊肉区别于其它地区的羊肉，以鲜嫩味美著称。
有一天，莱特跟瑞秋一起去内蒙吃涮羊肉，瑞秋往锅里下羊肉，莱特负责吃。
不同部位的肉要煮不同的时间，才能变得美味。莱特希望吃到最多的美味羊肉，但是莱特的手速不够快，用m代表莱特的手速，每次下手捞羊肉后要过m秒才能再捞（每次只能捞一个）。
那么用最合理的策略，莱特最多能吃到多少美味羊肉？


Input
第一行一个T(1≤T≤120)代表数据组数。
每组数据：
第一行两个整数n,m(1≤n,m≤1000)，其中n代表瑞秋往锅里下的羊肉个数，m代表莱特的手速。
接下来n行，每行两个数x,y(1≤x,y≤1000)代表第x秒下的肉过y秒才能变得美味。


Output
每个询问输出一个整数代表答案。


Sample Input
2
2 1
1 2
2 1
3 1
1 2
1 3
2 3


Sample Output
1
3
*/