#include <bits/stdc++.h>
// W 1 ，T 2
using namespace std;
const int maxn = 2000005;
char str[maxn >> 1];
int ext[maxn], L[maxn], R[maxn];
int main() {
    int n, m, q;
    while (scanf("%d%d", &n, &m) != EOF) {
        int sum = 0;
        scanf("%s", str + 1);
        for (int i = n; i; i--)  //前缀和
        {
            ext[i] = ext[i + 1] + 1;
            if (str[i] == 'W') ext[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            sum += str[i] == 'W' ? 1 : 2;
            L[sum] = 1;
            R[sum] = i;
            if (str[i] == 'T') {
                if (ext[1] < ext[i])
                    L[sum - 1] = ext[1] + 2, R[sum - 1] = i + ext[1];
                else if (i + ext[i] != n + 1)
                    L[sum - 1] = 1 + ext[i], R[sum - 1] = i + ext[i];
            }
        }
        while (m--) {
            scanf("%d", &q);
            if (q > sum || L[q] == 0)
                printf("NIE\n");
            else
                printf("TAK\n");
        }
    }
    return 0;
}
