// 1004.cpp
#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0);
#define lowbit(x) x &(-x);
#define clr(a, b) memset(a, b, sizeof(a);
typedef long long ll;
typedef long double ld;
const ld pi = acos(-1);
const int inf = 0x3f3f3f3f;
const ll llinf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 7;
// 题意:
// 求一个字典序最小的包含n个元素的数组a,其中有m个事实,每个事实(i,j)要求在[a_i,a_j]的任意子数组元素不相同
// n,m 1e5, sun_n sum_m 1e6
// 思路: 考虑到每个区间加数都是递增加进去的
struct node {
    int l, r;
    bool operator<(node &x) { return l < x.l || (l == x.l && r > x.r); }
} arr[maxn];
int a[maxn];
int main() {
    IO;
    int t;
    cin >> t;
    for (int kase = 1; kase <= t; kase++) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) a[i] = 1;
        for (int i = 1; i <= m; i++) cin >> arr[i].l >> arr[i].r;
        sort(arr + 1, arr + m + 1);
        int top = 1;
        for (int i = 2; i <= m; i++) {
            if (arr[i].l >= arr[top].l && arr[i].r <= arr[top].r)
                continue;  //忽略所有被包含的区间
            arr[++top] = arr[i];
        }
        m = top;
        priority_queue<int, vector<int>, greater<int> > Q;  // 从小到大
        for (int i = 1; i <= n; i++) Q.push(i);
        queue<int> Q2;
        int lst = 0;
        for (int i = 1; i <= m; i++) {
            while (!Q2.empty() && Q2.front() < arr[i].l) {
                Q.push(a[Q2.front()]);
                Q2.pop();
            }
            int now = max(lst + 1, arr[i].l);
            while (now <= arr[i].r) {
                a[now++] = Q.top();
                Q.pop();
                Q2.push(now - 1);
            }
            lst = arr[i].r;
        }
        for (int i = 1; i <= n; i++) printf("%d%c", a[i], " \n"[i == n]);
    }
}