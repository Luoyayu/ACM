#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 105;
const int inf = 0x7fffffff;
char a[maxn], b[maxn];

inline int trans(char x, char y) {
    if (x <= y)
        return y - x;
    else
        return y - x + 26;
}

int n, nx, ny, d;
int link[maxn], lx[maxn], ly[maxn];
int visx[maxn], visy[maxn], w[maxn][maxn];

int DFS(int x) {
    visx[x] = 1;
    for (int y = 1; y <= ny; y++) {
        if (visy[y]) continue;
        if (lx[x] + ly[y] == w[x][y]) {
            visy[y] = 1;
            if (!link[y] || DFS(link[y])) {
                link[y] = x;
                return 1;
            }
        } else
            d = min(d, lx[x] + ly[y] - w[x][y]);
    }
    return 0;
}

int KM() {
    memset(link, 0, sizeof(link));
    for (int i = 1; i <= nx; i++) {
        ly[i] = 0, lx[i] = -inf;
        for (int j = 1; j <= ny; j++) lx[i] = max(lx[i], w[i][j]);
    }

    for (int x = 1; x <= nx; x++) {
        while (true) {
            memset(visx, 0, sizeof(visx));
            memset(visy, 0, sizeof(visy));
            d = inf;
            if (DFS(x)) break;
            for (int i = 1; i <= nx; i++)
                if (visx[i]) lx[i] -= d;

            for (int i = 1; i < ny; i++)
                if (visy[i]) ly[i] += d;
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) ans += w[link[i]][i];
    return -ans;
}

int main() {
    while (scanf("%s %s", a, b) != EOF) {
        n = static_cast<int>(strlen(a));
        nx = ny = n;
        for (int i = 1; i <= nx; i++)
            for (int j = 1; j <= ny; j++) w[i][j] = -trans(a[i - 1], b[j - 1]);
        printf("%d\n", KM());
    }
}

/*
Problem Description
Orz has two strings of the same length: A and B. Now she wants to transform A
into an anagram of B (which means, a rearrangement of B) by changing some of its
letters. The only operation the girl can make is to “increase” some (possibly
none or all) characters in A. E.g., she can change an 'A' to a 'B', or a 'K' to
an 'L'. She can increase any character any times. E.g., she can increment an 'A'
three times to get a 'D'. The increment is cyclic: if she increases a 'Z', she
gets an 'A' again. For example, she can transform "ELLY" to "KRIS" character by
character by shifting 'E' to 'K' (6 operations), 'L' to 'R' (again 6
operations), the second 'L' to 'I' (23 operations, going from 'Z' to 'A' on the
15-th operation), and finally 'Y' to 'S' (20 operations, again cyclically going
from 'Z' to 'A' on the 2-nd operation). The total number of operations would be
6 + 6 + 23 + 20 = 55. However, to make "ELLY" an anagram of "KRIS" it would be
better to change it to "IRSK" with only 29 operations. You are given the strings
A and B. Find the minimal number of operations needed to transform A into some
other string X, such that X is an anagram of B.


Input
There will be multiple test cases. For each test case:
There is two strings A and B in one line. |A|=|B|≤50. A and B will contain only
uppercase letters from the English alphabet ('A'-'Z').


Output
For each test case, output the minimal number of operations.


Sample Input
ABCA BACA
ELLY KRIS
AAAA ZZZZ


Sample Output
0
29
100
*/

// #include <bits/stdc++.h>
// using namespace std;
// int main() {
//     char a[55], b[55];
//     while (~scanf("%s%s", a, b)) {
//         int len = strlen(a), vis[55];
//         long long sum = 0;
//         memset(vis, 0, sizeof(vis));
//         for (int i = 0; i < len; i++) {
//             int minn = 30, num;
//             for (int j = 0; j < len; j++) {
//                 if (vis[j]) continue;
//                 int temp;
//                 if (b[j] >= a[i])
//                     temp = b[j] - a[i];
//                 else
//                     temp = (26 - (a[i] - b[j]));
//                 if (temp < minn) {
//                     minn = temp;
//                     num = j;
//                 }
//             }
//             sum += minn;
//             vis[num] = 1;
//         }
//         printf("%lld\n", sum);
//     }
//     return 0;
// }
