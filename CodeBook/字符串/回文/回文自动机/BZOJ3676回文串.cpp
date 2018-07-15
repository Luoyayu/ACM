#include <bits/stdc++.h>
//回文树的再理解
//一开始回文树有2个节点；0表示偶数长度串的根和1表示奇数长度串的根
// len[0]=0;len[1]=-1;tot = 2;//添加了0和1

//回文树的应用
// 1. 求串S前缀(0~i)内本质不同的回文串的个数
// 2. 求串S内每一个本质不同的回文串出现的次数
// 3. 求S内回文串的个数
// 4. 求以下标i结尾的回文串的个数

using namespace std;
#define cmax(a, b) a = max(a, b);
#define cmin(a, b) a = min(a, b);
typedef long long ll;
const int maxn = 300000 + 5;
const int sigma = 26;
int n;          //添加字符的个数
int tot;        //添加的节点的个数
char ch[maxn];  // ch[0]=-1;
int len[maxn];
int fail[maxn];
int cnt[maxn];  // cnt[i]表示本质不同的串的个数
int nxt[maxn][sigma];
int num[maxn];  // num[i]表示:节点i表示的最长回文串后缀是回文串的个数
int last;
void pam_add_ch(int x, int pos) {
    int p = last;
    while (ch[pos - len[p] - 1] != ch[pos]) p = fail[p];
    if (!nxt[p][x]) {
        int np = ++tot, q = fail[p];
        len[np] = len[p] + 2;
        while (ch[pos - len[q] - 1] != ch[pos]) q = fail[q];
        fail[np] = nxt[q][x];
        nxt[p][x] = np;
    }
    last = nxt[p][x];
    cnt[last]++;
}
void init() {
    len[0] = 0;
    len[1] = -1;
    fail[0] = fail[1] = 1;
    last = 0;
    tot = 1;
}
int main() {
    scanf("%s", ch + 1);
    n = strlen(ch + 1);
    init();
    for (int i = 1; i <= n; i++) pam_add_ch(ch[i] - 'a', i);
    ll ans = 0;
    for (int i = tot; i; i--) {
        cnt[fail[i]] += cnt[i];  //此时的cnt不完整，要等全部插完,一路沿fail统计
        cmax(ans, (ll)cnt[i] * len[i]);
    }
    printf("%lld\n", ans);
}
