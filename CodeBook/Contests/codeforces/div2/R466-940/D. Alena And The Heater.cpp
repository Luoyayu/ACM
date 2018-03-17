// 题意: 无,略坑点:如果最值不产生在这5个数之中,l和r要变化1
#include <bits/stdtr1c++.h>

using namespace std;
typedef long long ll;
const int inf = 1000000000;
const int maxn = 1e5 + 7;
int n, a[maxn], b[maxn];

int main() {
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; i++)scanf("%d", &a[i]);
        for (int i = 1; i <= n; i++)scanf("%1d", &b[i]);
        int l = -inf, r = inf;
        for (int i = 5; i <= n; i++) {

            int tmpMAX = max(max(max(max(max(-inf, a[i - 4]), a[i - 3]), a[i - 2]), a[i - 1]), a[i]);
            int tmpMIN = min(min(min(min(min(inf, a[i - 4]), a[i - 3]), a[i - 2]), a[i - 1]), a[i]);
            //printf("b[i] = %d MIN = %d MAX = %d\n", a[i],tmpMIN, tmpMAX);
            bool flagb = b[i - 1] == b[i - 2] && b[i - 2] == b[i - 3] && b[i - 3] == b[i - 4];
            bool flaga = b[i] == b[i - 1];
            //printf("flagb = %d flaga = %d\n", flagb, flaga);

            if (!flagb && flaga) continue; // other情况
            if (!((tmpMIN > r && b[i - 1] || tmpMAX < l && !b[i - 1]) && flagb) && flaga) continue; //other 情况
            // 按题意有解处理
            if (b[i]) {
                int tmp = l; //!!!
                l = max(l, tmpMAX);
                l += (l != tmp);
            } else {
                int tmp = r; //!!!
                r = min(r, tmpMIN);
                r -= (r != tmp);
            }
        }
        printf("%d %d\n", l, r);
    }
}