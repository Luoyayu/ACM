#include <bits/stdc++.h>
#ifdef Local
#include "ACM.h"
#endif
using namespace std;
const int maxn = 1003;
char s[maxn];
bool flag;
struct node {
    int v;
    node *lc, *rc;
    bool f;
    node() : f(false), lc(NULL), rc(NULL) {}
} * root;
node *newnode() { return new node(); }
vector<int> ans;
void addnode(int v, char *ss) {
    int n = strlen(ss);
    node *cur = root;
    for (int i = 0; i < n; i++) {
        if (ss[i] == 'L') {
            if (cur->lc == NULL) cur->lc = newnode();
            cur = cur->lc;
        } else if (ss[i] == 'R') {
            if (cur->rc == NULL) cur->rc = newnode();
            cur = cur->rc;
        }
    }
    if (cur->f) flag = 1;
    cur->v = v;
    cur->f = 1;
}

bool read() {
    while (1) {
        if (scanf("%s", s) != 1) return 0;
        if (strcmp(s, "()") == 0) break;
        int value;
        sscanf(&s[1], "%d", &value);
        addnode(value, strchr(s, ',') + 1);
    }
    return 1;
}
int bfs() {
    queue<node *> q;
    q.push(root);
    while (!q.empty()) {
        node *cur = q.front();
        q.pop();
        if (cur->f == 0) return 0;
        ans.push_back(cur->v);
        if (cur->lc) q.push(cur->lc);
        if (cur->rc) q.push(cur->rc);
    }
    return 1;
}
bool init() {
    flag = 0;
    ans.clear();
    root = new node();
    return 1;
}
int main() {
    while (1) {
        init();
        if (!read()) break;
        int a = bfs();
#ifdef Local
        debug(a);
        debug(flag)
#endif
            if (flag || !a) printf("not complete\n");
        else {
            int s = 0;
            for (auto x : ans)
                if (!s++)
                    printf("%d", x);
                else
                    printf(" %d", x);
            printf("\n");
        }
    }
    return 0;
}
