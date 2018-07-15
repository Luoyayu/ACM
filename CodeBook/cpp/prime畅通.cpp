#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXn = 110;   //������
const int MAXm = 1000;  //������
int F[MAXn];            //���鼯
struct Edge {
    int u, v, w;
} edge[MAXm];
int tol;  //���� ע��addǰ��0
void addedge(int u, int v, int w) {
    edge[tol].u = u;
    edge[tol].v = v;
    edge[tol++].w = w;
}
bool cmp(Edge a, Edge b) { return a.w < b.w; }
int find(int x) {
    if (F[x] == -1)
        return x;
    else
        return F[x] = find(F[x]);
}
int Kruskal(int n)  //���� ����
{
    memset(F, -1, sizeof F);
    sort(edge, edge + tol, cmp);
    int cnt = 0;  //�������
    int ans = 0;  //��СȨֵ
    for (int i = 0; i < tol; i++) {
        int u = edge[i].u;
        int v = edge[i].v;
        int w = edge[i].w;
        int f1 = find(u);
        int f2 = find(v);
        if (f1 != f2) {
            ans += w;
            F[f1] = f2;
            cnt++;
        }
        if (cnt == n - 1) break;
    }
    if (cnt < n - 1)
        return -1;
    else
        return ans;
}
int main() {
    int n, m;
    while (scanf("%d %d", &m, &n) != EOF, m) {
        int a, b, c;
        tol = 0;
        while (m--) {
            scanf("%d%d%d", &a, &b, &c);
            addedge(a, b, c);
        }
        int ANS = Kruskal(n);
        if (-1 == ANS)
            printf("?\n");
        else
            printf("%d\n", ANS);
    }
    return 0;
}