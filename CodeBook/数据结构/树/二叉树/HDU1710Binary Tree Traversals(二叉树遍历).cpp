#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000+7;
/* 二叉树的三种遍历方式：preorder, inorder, postorder
 * 左子树T1, 右子树T2, 根 r
 * 题意：给出preorder和inorder,求postorder
 * 思想：先根据先序遍历和中序遍历建二叉树树，然后求后序遍历即可, 注意若只给出前序和后序则是无法建树的
 *  9
    1 2 4 7 3 5 8 9 6
    4 7 2 1 8 5 9 3 6
*/
struct node {
    int id;
    node *lc, *rc;
    node(int id = 0, node *lc = NULL, node *rc = NULL) : 
        id(id), lc(lc), rc(rc) {}
};
int pre[maxn], in[maxn], post[maxn], cnt;

void build(int l, int r, int &t, node * &root) {
    int flag = -1;
    for (int i = l; i <= r; i++)
        if (in[i] == pre[t]) {
            flag = i;
            break;
        }
    if(flag == -1) return ;
    root = new node(in[flag]); t++;
    if(flag > l) build(l, flag-1, t, root->lc);
    if(flag < r) build(flag + 1, r, t ,root->rc);
}

void dfs(node *root) {
    if (root) {
        dfs(root->lc);
        dfs(root->rc);
        post[cnt++] = root->id;
    }
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        cnt = 0;
        for (int i = 1; i <= n; i++) scanf("%d", &pre[i]);
        for (int i = 1; i <= n; i++) scanf("%d", &in[i]);
        node *root;
        int t = 1;
        build(1, n, t, root);
        dfs(root);
        for (int i = 0; i < cnt; i++) printf("%d%c", post[i], i == cnt-1 ? '\n' : ' ');
    }
    return 0;
}