#include <bits/stdc++.h>

using namespace std;
int g[22][22];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int cx, cy;
        for (int i = 1; i <= 10; i++) {
            for (int j = 1; j <= 9; j++) {
                scanf("%d", &g[i][j]);  // 1自己 2 对手
                if (g[i][j] == 3) {
                    cx = i, cy = j;
                }
            }
        }
        int cAns;
        scanf("%d", &cAns);
        int ans = 0;
        // 上
        for (int i = 1; i <= cx - 1; i++) {
            if (g[cx - i][cy] == 1) break;
            if (g[cx - i][cy] == 2) {
                ans++;
                break;
            }
        }
        // 下
        for (int i = 1; i <= 10 - cx; i++) {
            if (g[cx + i][cy] == 1) break;
            if (g[cx + i][cy] == 2) {
                ans++;
                break;
            }
        }
        // 左
        for (int i = 1; i <= cy - 1; i++) {
            if (g[cx][cy - i] == 1) break;
            if (g[cx][cy - i] == 2) {
                ans++;
                break;
            }
        }
        // 右
        for (int i = 1; i <= 9 - cy; i++) {
            if (g[cx][cy + i] == 1) break;
            if (g[cx][cy + i] == 2) {
                ans++;
                break;
            }
        }

        if (ans != cAns)
            printf("No\n");
        else
            printf("Yes\n");
    }
}