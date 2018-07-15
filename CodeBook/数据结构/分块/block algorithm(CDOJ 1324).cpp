#include <bits/stdc++.h>
// CDOJ 1324 查询区间最值得sqrt(n) 算法
using namespace std;
const int maxn = 1e5 + 7;
int belong[maxn];      //表示这个数在那一块里面
int block, num;        //每块大小; 块的数量
int l[maxn], r[maxn];  //这个数所在的左边界是什么,右边界是什么
long long MAX[maxn], a[maxn];
int n, q;
void build() {
    block = sqrt(n + 0.5);
    num = n / block;
    if (n % block) num++;
    for (int i = 1; i <= num; i++) l[i] = (i - 1) * block + 1, r[i] = i * block;
    r[num] = n;

    for (int i = 1; i <= n; i++) belong[i] = (i - 1) / block + 1;

    for (int i = 1; i <= num; i++)
        for (int j = l[i]; j <= r[i]; j++)  //块内的每一个元素
            MAX[i] = max(MAX[i], a[j]);
}
void update(int x, int y) {
    a[x] += y;
    MAX[belong[x]] = max(MAX[belong[x]], a[x]);
}
long long ask(int x, int y) {
    long long ans = 0;
    if (belong[x] == belong[y])  //再同一块了
    {
        for (int i = x; i <= y; i++) ans = max(a[i], ans);
        return ans;
    }
    //一般操作
    for (int i = x; i <= r[belong[x]]; i++)  //暴力更新块的左边
        ans = max(ans, a[i]);

    for (int i = belong[x] + 1; i < belong[y]; i++)  //更新每一块的信息
        ans = max(ans, MAX[i]);

    for (int i = l[belong[y]]; i <= y; i++)  //更新最右边的信息
        ans = max(a[i], ans);
    return ans;
}
int main() {
    scanf("%d %d\n", &n, &q);
    build();
    for (int i = 0; i < q; i++) {
        int op, l, r;
        scanf("%d %d %d", &op, &l, &r);
        if (op == 1)
            update(l, r);
        else
            printf("%lld\n", ask(l, r));
    }
    return 0;
}
