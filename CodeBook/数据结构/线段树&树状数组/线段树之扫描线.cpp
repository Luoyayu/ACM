//例HDU 1542 计算矩阵并的和 线段树应用之扫描线
// Scan-Line Filing algorithm
//线段树维护的是区间被覆盖的总长度，乘以两条扫描线间距就是一块面积，update线段树
// note:double
// 离散去重；不能用点来维护线段的长度，因为点此时维护的信息不再是本条线段的长度，而是该点到下个点的长度。注意每次计算长度时X[r+1]-X[l]；
//实现：将矩形的上下边分为上位边，下位边按高度排序得到若干条扫描线
//将横坐标离散化，按扫描线y坐标从小到大读入扫描线
//，维护当前扫描线能有效覆盖的x轴的最大长度sum[i]
// note:设置标记cnt;扫描线碰到下位边cnt++;碰到下位边cnt--;if cnt!=0;
// 表示当前节点控制的区间仍然被覆盖 建立node
//保存每条扫描线l:扫描线左端点x坐标，r:扫描线右端点x坐标,h:扫描线高度,d:标记
//读入矩阵信息,离散x坐标，去重计数k;排序扫描线高度；
//线段树中每个叶节点(控制区间[L,L])表示区间(X[L],X[L+1])
#include <algorithm>
#include <cstdio>
#include <cstring>
#define Ls i << 1
#define Rs i << 1 | 1
#define lson Ls, l, M
#define rson Rs, M + 1, r
#define root 1, 0, k - 1

using namespace std;
const int maxn = 2005;
double X[maxn];  //第i个区域的线段长度，是X[r+1]-X[l];
int cnt
    [maxn
     << 2];  // cnt>=0
             // 表示本节点控制的区域下的下位边个数-上位边的个数，cnt==-1,表示本节点的左右子节点的上下位边数不一致
double sum[maxn << 2];  //本节点控制的区域的面积
struct Node {
    double l, r, h;
    int d;
    Node() {}
    Node(double a, double b, double c, int d) : l(a), r(b), h(c), d(d) {}
    bool operator<(const Node &a) const { return h < a.h; }
} node[maxn];
void maintain(int i, int l, int r)  //向上维护信息
{
    if (cnt[Ls] == -1 || cnt[Rs] == -1)
        cnt[i] = -1;
    else if (cnt[Ls] != cnt[Rs])
        cnt[i] = -1;
    else
        cnt[i] = cnt[Ls] = cnt[Rs];
    sum[i] = sum[Ls] + sum[Rs];
}
void pushdown(int i, int l, int r)  //向下传递信息
{
    int M = (l + r) >> 1;
    int &t = cnt[i];
    if (t != -1)  //下放cnt信息，并更新sum值
    {
        cnt[Ls] = cnt[Rs] = t;
        sum[Ls] = (t ? (X[M + 1] - X[l]) : 0);
        sum[Rs] = (t ? (X[r + 1] - X[M + 1]) : 0);
    }
}
void build(int i, int l, int r) {
    if (l == r)  //找到叶节点
    {
        cnt[i] = 0;
        sum[i] = 0.0;
        return;
    }
    int M = (l + r) >> 1;
    build(lson), build(rson);
    maintain(i, l, r);
}
void update(int ql, int qr, int val, int i, int l, int r) {
    if (ql <= l && qr >= r)
        if (cnt[i] != -1) {
            cnt[i] += val;
            sum[i] = (cnt[i] ? (X[r + 1] - X[l]) : 0);
            return;
        }
    pushdown(i, l, r);  //更新区间被覆盖的总长度
    int M = (l + r) >> 1;
    if (ql <= M) update(ql, qr, val, lson);
    if (qr > M) update(ql, qr, val, rson);
    maintain(i, l, r);
}
int bing(double key, int n, double d[]) {
    int l = 1, r = n;
    while (r >= l) {
        int M = (l + r) >> 1;
        if (d[M] == key)
            return M;
        else if (d[M] > key)
            r = M - 1;
        else
            l = M + 1;
    }
    return -1;
}
int main() {
    int q;
    int kase = 0;
    while (scanf("%d", &q) != EOF && q) {
        int n = 0, m = 0;
        while (q--) {
            double x1, x2, y1, y2;
            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            X[++n] = x1;  //离散化坐标
            node[++m] = Node(x1, x2, y1, 1);
            X[++n] = x2;
            node[++m] = Node(x1, x2, y2, -1);
        }
        sort(X + 1, X + n + 1);
        sort(node + 1, node + m + 1);
        int k = 1;
        for (int i = 2; i <= n; i++)  //手动去重&计数
            if (X[i] != X[i - 1]) X[++k] = X[i];
        build(root);  //离散区间[]
        double ret = 0.0;
        for (int i = 1; i < m; i++) {
            int l = bing(node[i].l, k, X);
            int r = bing(node[i].r, k, X) - 1;
            if (l <= r) update(l, r, node[i].d, root);
            ret += sum[1] *
                   (node[i + 1].h -
                    node[i].h);  // sum[1]所有扫描线能有效覆盖的z轴的最大长度
        }
        printf("Test case #%d\nTotal explored area: %.2lf\n\n", ++kase, ret);
    }
    return 0;
}
