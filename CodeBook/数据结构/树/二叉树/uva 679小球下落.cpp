#include <bits/stdc++.h>
// 题意：在一棵完全二叉树上，每个点有一个开关初始全为false，小球从根落下，开关状态被改变，当
// 开关为true,小球向左子树移动，否则向右子树移动，问最后一个小球最后落在哪个的叶子上？
// 对于前两次的小球必然一个是落到根的左子树叶子上，一个落到右子树叶子上。
// 以此类推对于落入左子树的小球通过奇偶就能判断下一步往左还是右
// 所以对每层讨论即可
using namespace std;
int main() {
    int t;
    while (scanf("%d", &t), ~t) {
        while (t--) {
            int D, I;
            scanf("%d %d", &D, &I);
            int k = 1;
            for (int i = 1; i <= D - 1; i++) {
                if (I & 1)  // 每一层会被I个球改变 I为奇数向左走
                {
                    k <<= 1;
                    I = (I >> 1) + 1;
                } else {
                    k = (k << 1) + 1;
                    I >>= 1;
                }
            }
            printf("%d\n", k);
        }
    }
    return 0;
}
