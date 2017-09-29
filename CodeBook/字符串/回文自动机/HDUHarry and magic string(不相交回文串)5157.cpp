#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn  = 100000+10;
const int sigma = 26;
int fail[maxn];
int cnt[maxn];
int num[maxn];//num[i]表示:节点i表示的最长回文串后缀是回文串的个数
int nxt[maxn][sigma];
int last;
int len[maxn];
int tot;int n;
ll dp[maxn];//dp[i]表示以[1...i]结尾的回文串有多少
char s[maxn];//在构建自动机时要逐个添加
char str[maxn];
inline int get_fail(int x)
{
    while (s[n-len[x]-1] != s[n] ) x = fail[x] ;
    return x;
}
int add (char c)
{
    s[++n]= c-='a';
    int cur = get_fail(last) ;//通过上一个回文串找这个回文串的匹配位置
    if (!nxt[cur][c])//如果这个回文串没有出现过，说明出现了一个新的本质不同的回文串
    {
        int now = ++tot; len[now]=len[cur]+2;
        fail[now] = nxt[get_fail(fail[cur])][c] ;
        nxt[cur][c] = now ;
        num[now] = num[fail[now]] + 1 ;
    }
    last = nxt[cur][c] ;cnt[last] ++ ;
    return num[last];
}
void init()
{
    memset(nxt,0,sizeof(nxt));
    len[0]=0;len[1]=-1;
    fail[0]=fail[1]=1;s[0]=str[0]='#';
    last=0;tot=1;n=0;
}
int main()
{
    while(scanf("%s",str+1)!=EOF)
    {
        init();
        int len = strlen(str+1);
        dp[1] = add(str[1]);
        for(int i=2;i<=len;i++)
            dp[i] = dp[i-1] + add(str[i]);
        init();ll ans = 0;
        for(int i=len;i>=2;i--)
            ans += dp[i-1]*add(str[i]);
        printf("%lld\n",ans);
    }
    return 0;
}