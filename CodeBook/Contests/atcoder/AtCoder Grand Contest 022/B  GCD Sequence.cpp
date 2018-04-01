#include <bits/stdtr1c++.h>

using namespace std;
// 我们称一个集合是独特的当对集合的每一个元素a_i, 有gcd(a_i, sum of aexpect a_i)!=1
// 并且gcd(a_i) = 1 元素的大小不超过30000
// N最大不超过20000
// 构造题
// 2 4 6 8 10 ... 20000*2
// 由题设可知，对于最大的N，我们要选择2/3的数
// 注意到为了选择那么多的数，我们应尽量选能被2,3整除的数
// 同时为了gcd all = 1, 不妨2,3交替选择， 比如6k+2, 6k+3, 6k+4, 6k+6
// N<6特殊处理
// 对于N>=6 唯一的问题是sum
// 注意有 gcd(ai, S) = gcd(ai,S-ai)(*) 从S中减去ai效果不变
const int maxn = 1e5 + 7;
vector<int> v;

int main() {
    int add[] = {0, 2, 3, 4, 0};
    int n;
    scanf("%d", &n);
    int tot = 0;
    if (n == 3) return !printf("2 5 63\n");// 70
    else if (n == 4) return !printf("2 5 20 63\n"); //90
    else if (n == 5) return !printf("2 5 20 30 63\n"); //120
    else {
        int cnt = 0, sum = 0;
        int a, b;
        for (int i = 2; i <= 30001; i++) { //从2开始构造
            if (cnt < n && (i % 2 == 0 || i % 3 == 0)) {
                sum += i;
                cnt++;
                v.push_back(i);
            }
            if (i % 6 == 0) a = i;
            if (i % 6 == 4) b = i;
        }
        int X = sum % 6;
        if(X == 2) v[4] = a;
        else if(X == 3) v[5] = a;
        else if(X == 5) v[5] = b;
        for(int i = 0; i < n; i++) printf("%d%c", v[i], i==n-1?'\n':' ');
    }
}
