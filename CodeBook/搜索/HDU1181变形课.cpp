// DFS
#include <bits/stdc++.h>
int len = 0, flag = 0;
struct Node {
    char head, end;
} c[10000];
bool vis[10000];
void dfs(char ch) {
    if (ch == 'm') flag = 1;
    if (flag) return;
    for (int i = 0; i < len; i++) {
        if (vis[i]) continue;
        if (c[i].head == ch) {
            vis[i] = 1;
            dfs(c[i].end);
            vis[i] = 0;
        }
    }
}

int main() {
    char s[100];
    while (~scanf("%s", s)) {
        if (!strcmp(s, "0")) continue;
        len = 0;
        c[len].head = s[0];
        c[len].end = s[strlen(s) - 1];
        len++;
        while (scanf("%s", s), strcmp(s, "0")) {
            c[len].head = s[0];
            c[len].end = s[strlen(s) - 1];
            len++;
        }
        flag = 0;
        for (int i = 0; i < len; i++) {
            if (c[i].head == 'b') {
                memset(vis, 0, sizeof(vis));
                vis[i] = 1;
                dfs(c[i].head);
            }
            if (flag) break;
        }
        if (flag)
            printf("Yes.\n");
        else
            printf("No.\n");
    }

    return 0;
}