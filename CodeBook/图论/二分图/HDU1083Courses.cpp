
#include <cstdio>
#include <cstring>
const int maxn = 1005;
int uN, vN, k;
int g[maxn][maxn];
int used[maxn];
int linker[maxn];
using namespace std;
int dfs(int u) {
    for (int v = 1; v <= vN; v++) {
        if (g[u][v] && !used[v]) {
            used[v] = true;
            if (linker[v] == -1 || dfs(linker[v])) {
                linker[v] = u;
                return 1;
            }
        }
    }
    return 0;
}
void match() {
    int ans = 0;
    for (int i = 1; i <= uN; i++) memset(used, 0, sizeof used), ans += dfs(i);
    if (ans == uN)
        printf("YES\n");
    else
        printf("NO\n");
}
int main() {
    scanf("%d", &k);
    while (k--) {
        int a, b;
        memset(g, 0, sizeof g);
        memset(linker, -1, sizeof linker);
        scanf("%d%d", &uN, &vN);
        for (int i = 1; i <= uN; i++) {
            scanf("%d", &a);
            for (int j = 1; j <= a; j++) {
                scanf("%d", &b);
                g[i][b] = 1;
            }
        }

        match();
    }
    return 0;
}
