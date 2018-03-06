#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
#define clr(a,b) memset(a,b,sizeof(a))

//随机化
//题意：给出一系列点，问一点P为圆心R为半径的圆，至少ceil(N/2)的点在圆上
const double eps = 1e-8;
const int maxn = int(1e5+7);
struct node {
    double x,y;
    node():x(0),y(0){}
    node(double x,double y):x(x),y(y){}
    node(const node &o){
        x = o.x;
        y = o.y;
    }
}p[maxn];
struct circle {
    node o;
    double r;
    circle(node o, double r):o(o),r(r){}
};
double getDis(node &a, node &b) {
    return hypot(fabs(a.x - b.x), fabs(a.y - b.y));
}
circle getCircumcircle(node a,node b,node c) { //返回三点的外接圆
    double x1 = a.x, x2 = b.x, x3 = c.x;
    double y1 = a.y, y2 = b.y, y3 = c.y;
    double x0 = ((y2 - y1) * (y3 * y3 - y1 * y1 + x3 * x3 - x1 * x1) -
                 (y3 - y1) * (y2 * y2 - y1 * y1 + x2 * x2 - x1 * x1)) /
                (2.0 * ((x3 - x1) * (y2 - y1) - (x2 - x1) * (y3 - y1)));
    double y0 = ((x2 - x1) * (x3 * x3 - x1 * x1 + y3 * y3 - y1 * y1) -
                 (x3 - x1) * (x2 * x2 - x1 * x1 + y2 * y2 - y1 * y1)) /
                (2.0 * ((y3 - y1) * (x2 - x1) - (y2 - y1) * (x3 - x1)));
    node o = node(x0, y0);
    double r = getDis(a, o);
    return circle(o, r);
}
inline bool judge(circle a, node b) //判断点b是否在圆a上
{
    return fabs(getDis(a.o, b) - a.r) < eps;
}
int cnt[maxn];
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%lf%lf", &p[i].x, &p[i].y);
            cnt[i] = i;
        }
        if (n == 1) {
            printf("%.6f %.6f %.6f\n", p[1].x, p[1].y, double(0));
            continue;
        }
        if (n < 5) { //一定有解,两点定园
            printf("%.6f %.6f %.6f\n", (p[1].x + p[2].x) / 2, (p[1].y + p[2].y) / 2, getDis(p[1], p[2]) / 2);
            continue;
        }
        while (1) {
            random_shuffle(cnt + 1, cnt + n + 1);
            circle now = getCircumcircle(p[cnt[1]], p[cnt[2]], p[cnt[3]]);
            int ans = 0;
            for (int i = 1; i <= n; i++)
                if (judge(now, p[i])) ans++;
            if (ans >= (n + 1) / 2) {
                printf("%.6f %.6f %.6f\n", now.o.x, now.o.y, now.r);
                break;
            }
        }
    }
    return 0;
}