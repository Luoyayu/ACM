// 题意：input-> n,d  
// 有n个元素的数组，问删除最少几个数使得 max-min<=d
// trick:O(n)尺取法
// code:
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 105;
int s[maxn];
const int inf = 0x3f3f3f3f;

int main() {
    int n, d, ans = inf;
    scanf("%d %d", &n, &d);
    for (int i = 1; i <= n; i++) scanf("%d", &s[i]);
    sort(s + 1, s + n + 1);
    if (!n) puts("0");
    else {
        int l = 1, r = 1;//从头
        while (1) {
            while (r <= n && s[r] - s[l] <= d)
                r++; //　右推
            //printf("l = %d r = %d\n", l, r);
            ans = min(ans, l + n - r);
            if(r == n + 1) break;
            l ++; // 左推
            //　无更新影响
        }
        printf("%d\n", ans);
    }
}

