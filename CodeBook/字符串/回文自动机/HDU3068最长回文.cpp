#include <bits/stdc++.h>
using namespace std;
#define cmax(a,b) a = max(a,b);
#define cmin(a,b) a = min(a,b);
typedef long long ll;
const int maxn = 110000 + 5;
const int sigma = 26;
int n;
int tot;
char ch[maxn];
int len[maxn];
int fail[maxn];
int cnt[maxn];
int nxt[maxn][sigma];
int num[maxn];
int last;
void pam_add_ch(int x,int pos)
{
    int p = last;
    while(ch[pos-len[p]-1]!=ch[pos]) p=fail[p];
    if(!nxt[p][x])
    {
        int np = ++tot,q = fail[p]; len[np] = len[p] + 2;
        while(ch[pos-len[q]-1]!=ch[pos]) q = fail[q];
        fail[np] = nxt[q][x];nxt[p][x]=np;
    }
    last = nxt[p][x];cnt[last]++;

}
void init()
{
    memset(nxt,0,sizeof(nxt));//注意清空
    memset(len,0,sizeof(len));
    len[0] = 0,len[1] = -1;
    fail[0] = fail[1] = 1;
    last = 0; tot=1;

}
int main()
{
    while(scanf("%s",ch+1)!=EOF)
    {
        n=strlen(ch+1);
        init();
        for(int i=1;i<=n;i++) pam_add_ch(ch[i]-'a',i);
        ll ans = 0;
        for(int i=tot;i;i--)
            cmax(ans,(ll)len[i]);//简单遍历
        printf("%lld\n",ans);
    }
    return 0;
}

