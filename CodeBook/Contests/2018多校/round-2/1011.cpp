#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;
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
//题意: 高效维护floor(a_i/b_i)区间和
const int maxn = 1e5 + 7;
const int inf = 0x3f3f3f3f;
int a[maxn];
int b[maxn];
struct node {
    int ans, bi, remaining;
    void update() {
        if (remaining == 0) {
            remaining = bi;
            ans++;
        }
    }
} arr[maxn];

int main() {
    int t = read();
    for (int kase = 1; kase <= t; kase++) {
        int n = read(), q = read();
        for (int i = 1; i <= n; i++) {
            arr[i].bi = read();
            arr[i].remaining = arr[i].bi;
            arr[i].ans = 0;
        }
        int ret = 0;
        while (q--) {
            char s[10];
            scanf("%s", s);
            int l, r; scanf("%d %d", &l, &r);
            if (s[0] == 'q') {
                for (int i = l; i <= r; i++) ret += arr[i].ans;
                printf("%d\n", ret);
            } else {
                for (int i = l; i <= r; i++) {
                    arr[i].remaining--;
                    arr[i].update();
                    printf("%d ", arr[i].ans);
                }
                printf("\n");
            }
        }
    }
}