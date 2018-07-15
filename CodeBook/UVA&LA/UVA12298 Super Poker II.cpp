
#include <bits/stdc++.h>
using namespace std;
//题意：给出超级扑克四种花色(S,H,C,D),点数为合数,需要抽取四种花色各一张组成合数N
//再给出丢失掉的c张牌
//给出区间[a,b] 问搭配成区间中的每一个数各种组合的个数
//思路：拿合数组牌先预处理出所有的合数
const int maxn = 1e6 + 7;
const int N = 5e4 + 7;
typedef long double ld;
const long double PI = acos(-1.0);
const long double pi = acos(-1.0);
bool notprime[maxn];  // notprime[i]==0表示i是质数
int prime[maxn];
struct Complex {
    ld r, i;
    Complex(ld _r = 0, ld _i = 0) : r(_r), i(_i) {}
    Complex operator+(const Complex &b) const {
        return Complex(r + b.r, i + b.i);
    }
    Complex operator-(const Complex &b) const {
        return Complex(r - b.r, i - b.i);
    }
    Complex operator*(const Complex &b) const {
        return Complex(r * b.r - i * b.i, r * b.i + i * b.r);
    }
} xS[maxn], xH[maxn], xC[maxn], xD[maxn];
int cnt = 0;

void pre() {
    for (int i = 2; i <= N; i++) {
        if (!notprime[i]) prime[cnt++] = i;
        for (int j = 0; j < cnt && i * prime[j] <= N; j++) {
            notprime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}
void change(Complex y[], int len) {
    for (int i = 1, j = len >> 1; i < len - 1; i++) {
        if (i < j) swap(y[i], y[j]);
        int k = len >> 1;
        while (j >= k) j -= k, k >>= 1;
        if (j < k) j += k;
    }
}
void fft(Complex y[], int len, int on) {
    change(y, len);
    for (int h = 2; h <= len; h <<= 1) {
        Complex wn(cos(-on * 2 * PI / h), sin(-on * 2 * PI / h));
        for (int j = 0; j < len; j += h) {
            Complex w(1, 0);
            for (int k = j; k < j + h / 2; k++) {
                Complex u = y[k];
                Complex t = w * y[k + h / 2];
                y[k] = u + t;
                y[k + h / 2] = u - t;
                w = w * wn;
            }
        }
    }
    if (on == -1)
        for (int i = 0; i < len; i++) y[i].r /= len;
}
int a, b, c;

int main() {
    pre();
    while (scanf("%d%d%d", &a, &b, &c) != EOF && (a || b || c)) {
        int len = 1;
        while (len <= b) len <<= 1;
        len <<= 2;
        for (int i = 0; i < len; i++)
            xS[i] = xH[i] = xC[i] = xD[i] = Complex(0, 0);
        for (int i = 0; i <= b; i++)
            if (notprime[i])  //是合数
                xS[i] = xH[i] = xC[i] = xD[i] = Complex(1, 0);
        while (c--) {
            char w[20];  // 4S SHCD
            scanf("%s", w);
            int L = strlen(w);
            int num;
            char color = w[L - 1];
            sscanf(w, "%d", &num);

            if (color == 'S')
                xS[num].r = 0;
            else if (color == 'H')
                xH[num].r = 0;
            else if (color == 'C')
                xC[num].r = 0;
            else if (color == 'D')
                xD[num].r = 0;
        }

        fft(xS, len, 1);
        fft(xH, len, 1);
        fft(xC, len, 1);
        fft(xD, len, 1);
        for (int i = 0; i <= len; i++) xS[i] = xS[i] * xH[i] * xC[i] * xD[i];
        fft(xS, len, -1);
        for (int i = a; i <= b; i++) printf("%.0Lf\n", fabs((xS[i].r)));
        puts("");
    }
    return 0;
}