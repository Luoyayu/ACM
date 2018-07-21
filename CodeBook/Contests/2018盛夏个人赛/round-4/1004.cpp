
#include <bits/stdtr1c++.h>

using namespace std;
typedef long long LL;
using namespace std;

typedef pair<int, int> pii;
map<pii, int> mp;
int a[8];

pii solve(int a[]) {  // 返回左下顶点
    int rx = min(min(a[0], a[2]), min(a[4], a[6]));
    int ry = min(min(a[1], a[3]), min(a[5], a[7]));
    return make_pair(rx, ry);
}

int main() {
    int T;
    cin >> T;
    for (int _cas = 1; _cas <= T; _cas++) {
        mp.clear();
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            for (int &j : a) scanf("%d", &j);
            pii tmp = solve(a);
            if (!mp[tmp])
                mp[tmp] = 1;
            else
                mp[tmp] ^= 1;  // 重叠奇数次消失
        }
        int res = 0;
        for (auto ex : mp) {
            if (ex.second == 0) continue;
            res += 4;
            auto po = ex.first;
            int nx = po.first;
            int ny = po.second;
            // 如果有重叠面积减1，枚举四个可能相邻的位置
            if (mp[make_pair(nx + 1, ny)]) res--;
            if (mp[make_pair(nx - 1, ny)]) res--;
            if (mp[make_pair(nx, ny + 1)]) res--;
            if (mp[make_pair(nx, ny + 1)]) res--;
        }
        printf("Case #%d: %.1lf\n", _cas, res / 2.0);
    }
}
/*
Problem Description
“When you get two coins, you actually get none”    -MR. Exclusive OR

Many square bricks are placed in a big enough space described with Cartesian coordinate system. It is possible for bricks to overlap each other. Each brick has the same size 2 with a strange property like “Exclusive OR”: when two bricks happen to overlap in some area, the overlapping part will disappear, just like being covered nothing. 

Taoge has just placed such bricks. He only put bricks in a pattern that all vertexes of bricks are at certain integral-point which means if (xi,yi) is the coordinate of a vertex, then both xi and yi are integers. He wants to know what is the area being covered by the bricks.
 

Input
The first line of the input gives the number of test cases, T. T test cases follow.

Each test case begins with an integer N, representing the number of bricks. Next N lines, each line has eight space-separated integers x1, y1, x2, y2, x3, y3, x4, y4, where (x1,y1), (x2,y2), (x3,y3), (x4,y4) represent coordinates of four vertexes of a square brick. Notice that the order of four coordinates is uncertain.
 

Output
For each test case, output one line containing Case #i: S, where i is the test case number
(starting from 1) and S is the covered area as described above with accuracy of 1 decimal digits. 
1 ≤ T ≤ 10.
1 ≤ N ≤ 100000.
0 ≤ x, y ≤ 10^9.
 

Sample Input
3
3
1 0 0 1 1 2 2 1
3 0 2 1 3 2 4 1
5 0 4 1 5 2 6 1
3
1 0 0 1 1 2 2 1
2 0 1 1 2 2 3 1
4 0 3 1 4 2 5 1
4
1 0 0 1 1 2 2 1
3 1 2 2 1 1 2 0
6 5 5 6 6 7 7 6
5 4 4 5 5 6 6 5 
 

Sample Output
Case #1: 6.0
Case #2: 5.0
Case #3: 7.0
*/