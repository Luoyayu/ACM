#include <bits/stdtr1c++.h>
using namespace std;
typedef long long LL;
const int N = 100000 + 10;
vector<int> G[N];
int tot;
LL a[N];
LL num[N];

struct ZeroOneTire {
    int root[N];
    int ch[32 * 100000][2], sum[32 * 100000 * 2];

    void pre() {
        memset(ch, 0, sizeof ch);
        memset(sum, 0, sizeof sum);
        memset(root, 0, sizeof root);
    }

    void insert(int &root, int x, LL t) {
        root = ++tot;
        int k;
        sum[k = root] = sum[x] + 1;
        for (int i = 31; ~i; i--) {
            if ((t >> i) & 1) {
                ch[k][0] = ch[x][0];
                k = (ch[k][1] = ++tot);
                x = ch[x][1];
            } else {
                ch[k][1] = ch[x][1];
                k = (ch[k][0] = ++tot);
                x = ch[x][0];
            }
            sum[k] = sum[x] + 1;
        }
    }

    LL query(int l, int r, LL num) {
        LL ans = 0;
        LL d;
        for (int i = 31; ~i; i--) {
            d = (num >> i) & 1;
            if (sum[ch[r][d ^ 1]] - sum[ch[l][d ^ 1]]) {
                ans += ((d ^ 1) << i);
                r = ch[r][d ^ 1];
                l = ch[l][d ^ 1];
            } else {
                ans += (d << i);
                r = ch[r][d];
                l = ch[l][d];
            }
        }
        return ans ^ num;
    }
} __tire;

int main() {
    int n, q;
    while (scanf("%d", &n) != EOF) {
        for (auto &i : G) i.clear();
        tot = 0;
        memset(a, 0, sizeof a);
        memset(num, 0, sizeof num);

        __tire.pre();
        for (int i = 1; i <= n; i++) scanf("%lld", &num[i]);

        for (int i = 1; i <= n; i++)
            __tire.insert(__tire.root[i], __tire.root[i - 1], num[i]);

        scanf("%d", &q);
        while (q--) {
            LL x;
            scanf("%lld", &x);
            int l, r;
            scanf("%d%d", &l, &r);
            LL maxn = 0;
            // for(int j=l;j<=r;j++)maxn=max(maxn,num[j]^x);
            // printf("ans==%lld\n",maxn);
            printf("%lld\n",
                   __tire.query(__tire.root[l - 1], __tire.root[r], x));
        }
    }
}
