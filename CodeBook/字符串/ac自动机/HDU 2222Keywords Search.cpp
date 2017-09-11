//ac自动机入门题
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1111111;
int tot, son[maxn][27], fail[maxn];
int n;char s[maxn];
#define clr(a) memset(a,0,sizeof(a));
void insert(char *s)
{
    int dep,nxt,w;
    for(dep=0;*s;dep=nxt,s++)
    {
        nxt = son[dep][w=*s-'a'];
        if(!nxt) {clr(son[tot]);son[dep][w]=nxt= tot++;}
    }
    son[dep][26]++;
}
void make()
{
    static int q[maxn];
    int bg=0, ed=0, i, x, v;fail[0] = 0;
    for(i=0;i<26;i++) if((v=son[0][i])) fail[q[ed++]=v]=0;
    while(bg<ed)
    for(x=q[bg++],i=0;i<26;i++)
    if((v=son[x][i])) fail[q[ed++]=v]=son[fail[x]][i];
    else son[x][i] = son[fail[x]][i];
}

int find(char *s)
{
    static bool vis[maxn];clr(vis);
    int ans = 0;
    for(int x=0;*s;s++)
    {
        x = son[x][*s-'a'];
        for(int j=x;j&&!vis[j];j=fail[j]) ans+=son[j][26],vis[j]=1;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);
    int t;cin>>t;
    while(t--)
    {
        tot = 1;clr(son[0]);
        cin>>n;
        while(n--) cin>>s,insert(s);
        make();cin>>s;cout<<find(s)<<endl;
    }
    return 0;
}