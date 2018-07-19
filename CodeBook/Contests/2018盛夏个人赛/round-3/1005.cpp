#include <bits/stdtr1c++.h>

using namespace std;
const int maxn = 1e6 + 7;
const int inf = 2e7 + 7;
int sum[maxn];
#define lowbit(x) x &(-(x))

struct Bitarray {
    int c[maxn];
    int n;

    void init(int n) {
        this->n = n;
        memset(c, 0, sizeof(c));
    }

    void add(int pos, int value) {
        while (pos <= n) {
            c[pos] += value;
            pos += lowbit(pos);
        }
    }

    int sum(int pos) {
        int res = 0;
        while (pos) {
            res += c[pos];
            pos -= lowbit(pos);
        }
        return res;
    }
} _;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        _.init(n);
        memset(sum, 0, sizeof(sum));
        int MIN = inf;
        for (int i = 1; i <= n; i++) {
            int x;
            scanf("%d", &x);
            if (_.sum(x) == 1) sum[MIN]++;

            _.add(x, 1);
            if (x > MIN) sum[x]++;
            else MIN = x;
        }

        int pos = inf, MINN = inf;
        for (int i = 1; i <= n; i++) {
            if (sum[i] < MINN) {
                MINN = sum[i];
                pos = i;
            }
        }
        printf("%d\n", pos);
    }
}