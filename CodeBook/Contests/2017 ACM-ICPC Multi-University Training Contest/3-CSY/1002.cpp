答案分成三份，L左边完整的串，R右边完整的串，以及中间拼凑的串。
S[0][L][i]表示T串的前缀0~L中，有哪些位置能够匹配到P[i]。
而S[1][R][j]表示T串翻转后，后缀R~n-1变为前缀0~n-R-1中，有哪些位置能够匹配到P串翻转后的P[j].
可以在KMP中通过失配函数维护S数组，S[][i][j] = s[][i-1][j]+(s[i]能否刚好匹配到p[j])?1:0，
这样只要枚举一遍P串，求得sum(S[0][L][i]*S[1][R][m-i])为拼凑的串的总和。
剩余的串即sum(S[0][i][m] | 0<=i<=L)+sum(S[1][i][m] | 0<=i<=n-R-1).
#include<bits/stdc++.h>
using namespace std;
#define CLR(A, X) memset(A, X, sizeof(A))
typedef long long LL;
const int N = 5e4+5, M = 1e2+5;

char s[N], P[M];
int kmpnext[2][M];
LL S[2][N][M];

void getFail(int m, int *kmpnext)
{
    kmpnext[0] = 0, kmpnext[1] = 0;
    for(int i = 1; i < m; i++)
    {
        int j = kmpnext[i];
        while(j && P[i]!=P[j]) j = kmpnext[j];
        kmpnext[i+1] = P[i]==P[j]?j+1:0;
    }
}

void KMP(int n, int m, int *kmpnext, LL S[][M])
{
    getFail(m, kmpnext);
    int j = 0;
    for(int i = 0; i < n; i++)
    {
        for(int k = 0; k <= m; k++)
        {
            if(!i) S[i][k] = 0;
            else S[i][k] = S[i-1][k];
        }
        while(j && s[i]!=P[j]) j = kmpnext[j];
        if(s[i] == P[j]) j++;
        int x = j;
        while(x)
        {
            S[i][x]++;
            x = kmpnext[x];
        }
        if(j == m) j = kmpnext[j];
    }
    for(int i = 1; i < n; i++) S[i][m] += S[i-1][m];
}

int main()
{
    int cas;
    scanf("%d", &cas);
    for(int kase=1;kase<=cas;kase++)
    {
        int n, m, q, L, R;
        scanf("%d%d%d %s%s", &n, &m, &q, s, P);
        KMP(n, m, kmpnext[0], S[0]);
        reverse(s, s+n); reverse(P, P+m);
        KMP(n, m, kmpnext[1], S[1]);

        while(q--)
        {
            scanf("%d%d", &L, &R);
            L--, R--;
            LL ans = S[0][L][m]*(n-R)+S[1][n-R-1][m]*(L+1);
            for(int i = 1; i < m; i++)
                ans += S[0][L][i]*S[1][n-R-1][m-i];
            printf("%lld\n", ans);
        }
    }
    return 0;
}
