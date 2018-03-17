// 题意: 给出n,k, 表示有长度为n的小写英文串, 构造出长度为k且字典序大于原串的串,输出之中字典序最小的串
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

            if (!flagb && flaga) continue;
            //printf("Pass 1\n");
            if (!((tmpMIN > r && b[i - 1] || tmpMAX < l && !b[i - 1]) && flagb) && flaga) continue;
            //printf("Pass 2\n");
            if (b[i]) {
                int tmp = l;
                l = max(l, tmpMAX);
                l += (l != tmp);
                //printf("Pass 1.1\n");
            } else {
                int tmp = r;
                r = min(r, tmpMIN);
                r -= (r != tmp);
                //printf("Pass 1.2\n");
            }
        }
        printf("%d %d\n", l, r);
    }
}