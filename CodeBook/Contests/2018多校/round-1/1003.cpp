#include <bits/stdc++.h>

using namespace std;
// 题意:
// 给出n组点，每组有3个不共线的点，且这些点钟中任意三点不共线，求一种分组方式，3个点形成n组三角形，
// 这n个三角形不相交
//思路:
//比较简单按照x轴自左向右选3个点连成三角形，这样一定不会相交的,最长边不会挨着，中间的点保证最长边对应的角向内，所以就不会和其他的相交
const int maxn = 4009;
struct node {
    int x, y, idx;
} arr[maxn];

bool cmp(node a, node b) { return a.x < b.x; }

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

int main() {
    int t = read();
    while (t--) {
        int n = read(), n3 = n * 3;
        for (int i = 1; i <= n3; i++)
            arr[i].x = read(), arr[i].y = read(), arr[i].idx = i;
        sort(arr + 1, arr + n3 + 1, cmp);
        for (int i = 1; i <= n3; i += 3)
            printf("%d %d %d\n", arr[i].idx, arr[i + 1].idx, arr[i + 2].idx);
    }
}