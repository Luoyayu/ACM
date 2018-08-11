// Uva 11572 Unique Snowflakes 滑窗.cpp
#include <bits/stdc++.h>
using namespace std;
#define lowbit(x) (x & (-x));
#define lc ((rt) << 1)
#define rc ((rt) << 1 | 1)
#define mid ((l + r) >> 1)
#define clr(a, b) memset(a, b, sizeof(a);
typedef long long ll;
typedef long double ld;
const ld pi = acos(-1);
const int inf = 0x3f3f3f3f;
const ll llinf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 7;
int a[maxn];
set<int> st;
// 题意: 给出一个序列, 让你找到一个最长的区间使得区间内的元素各不相同, 尺取法????

// 思路: 开一个集合动态维护, 当发现要加进来的值在集合中有时,
// 删除集合最先进来的元素一直到他, 更新集合size, 类似尺取法, O(n)扫一遍
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    for (int kase = 1; kase <= t; kase++) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        int ans = 0;
        int l = 0, r = 0;
        st.clear();
        while (r < n) {
            while (r < n && !st.count(a[r])) st.insert(a[r++]);
            ans = max(ans, r - l);
            st.erase(a[l++]);  // 擦除重复元素前面的所有在集合中的值
        }
        cout << ans << endl;
    }
}
/*
Status Accepted
Time 260ms
Length 960
*/