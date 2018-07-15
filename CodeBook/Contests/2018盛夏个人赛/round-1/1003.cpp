#include <bits/stdtr1c++.h>

using namespace std;
typedef long long ll;
const int maxn = 2222;
const int inf = 0x3f3f3f3f;

inline int sgn(int x) { return x < 0 ? -1 : x == 0 ? 0 : 1; }

int main() {
    int t;
    while (scanf("%d", &t) != EOF) {
        while (t--) {
            int x1, x2, y1, y2, dx, dy;
            scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &dx, &dy);
            int disX = x2 - x1, disY = y2 - y1;
            if (disX * dy != disY * dx ||
                (sgn(disX) != sgn(dx) || sgn(dy) != sgn(disY))) {
                printf("NO\n");
                continue;
            }
            printf("YES\n");
        }
    }
}

/*
小明有一次运气贼好，跳在一个小野区，突然掉了一个空投，直接砸在他的脸上，可把他乐坏了。走近一打开补给包，AWM+3级头+8倍镜+20发.300马格南，令人窒息！
小明拿着AWM，立即往山上跑，想用这把传说中的枪，爆敌人的头。不一会，小明看到一个挂机仔，躲在一块石头后面。我们将小明的枪口和挂机仔的头看成二维平面上的两个点(x1,y1),(x2,y2)，小明瞄准后开了一枪，子弹按照(dx,dy)的方向运动（即每毫秒子弹的x坐标+dx，y坐标+dy），如果子弹的运动轨迹能经过(x2,y2)，那么子弹就能打中敌人的头，我们来预测一下小明能否用这把AWM一枪爆掉敌人的头，如果能，输出”YES”,否则输出”NO”。


Input
多组测试数据，首先第一行一个整数T(1≤T≤20)，代表测试数据组数。
每组测试数据有 6 个整数 x1,y1,x2,y2,dx,dy，小明的枪口坐标为 (x1,y1),
敌人的坐标为(x2,y2)，子弹的运动方向为 (dx,dy)，保证枪口坐标和敌人的坐标不同，1 ≤
x1,y1,x2,y2 ≤ 1000，1000≤dx,dy≤1000。


Output
如果小明能用这把AWM一枪爆掉敌人的头，输出”YES”,否则输出”NO”。


Sample Input
2
1 1 2 2 2 2
1 1 3 1 0 1


Sample Output
YES
NO

*/
