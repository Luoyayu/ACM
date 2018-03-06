#include <bits/stdc++.h>
using namespace std;
//题意：给出一个包含N个数的序列A
//从序列A中将 所有大于K的间隔中的第K大的数 放到序列B，求B序列第M大
//思想： 整体二分
typedef long long ll;
const int maxn = 1e5+7;
int a[maxn], b[maxn];
int n, k;
ll m;
ll get(int x) {
    ll ans = 0;
    int  pos = 1, num = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] >= x) num++;
        if (num == k) {
            ans += n - i + 1;
            while (a[pos] < x) {
                ans += n - i + 1;
                pos++;
            }
            num--, pos++;
        }
    }
    return ans;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%lld", &n, &k, &m);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            b[i] = a[i];
        }
        sort(b + 1, b + n + 1);
        unsigned int num = unique(b + 1, b + n + 1) - (b + 1);
        int L = 1, R = num,mid;
        while (L <= R) {
            mid = (L + R) >> 1;
            ll mv = get(b[mid]);//返回有多少区间第K大的数是b[mid]
            if (mv < m) R = mid - 1;
            else L = mid + 1;//区间数大于M说明小了否则大了
        }
        printf("%d\n", b[L - 1]);
    }
    return 0;
}
