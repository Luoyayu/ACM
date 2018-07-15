#include <bits/stdtr1c++.h>
#include "feature.h"

using namespace std;
// 复杂度 logn
struct node {
    node *lc, *rc;
    int v;
};

node *build() {
    int v;
    scanf("%d", &v);
    node *T;
    if (!v)
        T = nullptr;
    else {
        T = new node();
        T->v = v;
        T->lc = build();
        T->rc = build();
    }
    return T;
}

int ret_dept(node *t) {
    if (t == nullptr) return 0;
    int left_dept = ret_dept(t->lc) + 1;
    int right_dept = ret_dept(t->rc) + 1;
    return max(left_dept, right_dept);
}

int main() {
    node *root = build();
    return !printf("二叉树深度: %d\n", ret_dept(root));
}

// 1 2 4 0 6 0 0 5 0 0 3 0 0 ;ans->4
// 6 5 2 0 0 5 0 0 7 0 8 0 0 ;and->3