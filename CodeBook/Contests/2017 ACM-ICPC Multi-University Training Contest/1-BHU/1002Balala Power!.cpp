#include <bits/stdc++.h>
using namespace std;
const int maxn = int(1e5 + 7);
const int mod = int(1e9 + 7);
typedef long long LL;
char str[maxn];
LL power[maxn];
int num[26][maxn], L;
int sum[maxn];
bool ban[26];
int a[26];
bool cmp(int A, int B) {
    for (int i = L - 1; i >= 0; i--) {
        if (num[A][i] != num[B][i])  //对第一关键词排序
            return num[A][i] < num[B][i];
    }
    return 0;
}
void init() {
    power[0] = 1;
    for (int i = 1; i < maxn; i++) power[i] = (LL)power[i - 1] * 26 % mod;
}
int main() {
    int n, kase = 1;
    init();
    while (scanf("%d", &n) != EOF) {
        memset(ban, 0, sizeof ban);
        memset(sum, 0, sizeof sum);
        memset(num, 0, sizeof num);
        L = 0;
        for (int i = 0; i < n; i++) {
            scanf("%s", str);
            int len = strlen(str);
            if (len > 1) ban[str[0] - 'a'] = 1;

            reverse(str, str + len);
            for (int j = 0; j < len; j++) {
                num[str[j] - 'a'][j]++;
                sum[str[j] - 'a'] += power[j];
                if (sum[str[j] - 'a'] >= mod) sum[str[j] - 'a'] -= mod;
            }
            L = max(L, len);
        }

        for (int i = 0; i < 26; i++)  //进位
        {
            for (int j = 0; j < L; j++) {
                num[i][j + 1] += num[i][j] / 26;
                num[i][j] %= 26;
            }

            while (num[i][L])  //如果最高为不为0但是超了26的话
            {
                num[i][L + 1] += num[i][L] / 26;
                num[i][L++] %= 26;
            }
            a[i] = i;
        }
        sort(a, a + 26, cmp);

        int zero = -1;
        for (int i = 0; i < 26; i++)
            if (ban[a[i]] == 0) {
                zero = a[i];
                break;
            }

        int res = 0, x = 25;
        for (int i = 25; i >= 0; i--) {
            if (a[i] != zero) {
                res += (LL)(x--) * sum[a[i]] % mod;  //比较坑的地方注意LL
                res %= mod;
            }
        }
        printf("Case #%d: %d\n", kase++, res);
    }
    return 0;
}