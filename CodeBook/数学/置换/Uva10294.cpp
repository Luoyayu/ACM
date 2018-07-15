#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int MAXN = 1e6 + 7;
// 题意: 给出t种颜色, n颗珠子
// 手镯可以翻转,旋转, 项链只能旋转
// 问能组成多少种手镯和项链
// 思路: 两种置换
// 1) 旋转操作中的每种置换可设逆时针旋转x个珠子(1~n-1),
// 则对于一种旋转它的0号元素的循环分解为(0,i,2i,3i,...): 0->i->2i->...->0
// 根据对称性可知,
// 其他未在循环中出现的元素(1,2,gcd(i,n)-1)经过同样的长度能回到自身,
// 故每种循环的循环节为gcd(i,n), 每个循环的长度为n/gcd(i,n) 2) 翻转操作,
// 对称轴经过珠子则循环长度为1, 不经过珠子长度为2 当n为奇数时,共形成n条对称轴,
// 其中形成1个长度为1的循环和(n-1)/2个长度为2的循环; 共有n*t^{1+(n-1)/2}个不动点
// 当n为偶数时,共形成n条对称轴, 其中如果对称轴穿过珠子:
// 形成2个长度为1的循环和n/2-1个长度为2的长度为2的循环
// 如果对称轴不穿过珠: 形成n/2个长度为2的循环;
// 共有(n/2)*(t^{2+n/2-1}+t^{n/2})
#define pow POW
double pow[55] = {1};
int main(int argc, char const *argv[]) {
    int n, t;
    while (scanf("%d%d", &n, &t) != EOF) {
        ll ansA = 0, ansB = 0;
        for (int i = 1; i <= n; i++) pow[i] = pow[i - 1] * t;
        for (int i = 0; i <= n - 1; i++) ansA += pow[__gcd(i, n)];
        if (n & 1)
            ansB = n * pow[(n + 1) >> 1];
        else
            ansB = (n >> 1) * (pow[(n >> 1) + 1] + pow[n >> 1]);
        printf("%lld %lld\n", ansA / n, ((ansA + ansB) >> 1) / n);
    }
}