//ac自动机入门题
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000010;
int tot, son[maxn][27], fail[maxn],val[maxn];
#define clr(a) memset(a,0,sizeof(a));

void insert(char *s,int idx)
{
    int x,nxt,w;
    for(x=0;*s;x=nxt,s++)
    {
        nxt=son[x][w=*s-'a'];
        if(!nxt) {clr(son[tot]);son[x][w]=nxt=tot++;}
    }
    val[x]++;
}
void inline init() {tot =1;clr(son[0]);clr(val); }

void make()
{
    static int q[maxn];
    int bg=0, ed=0,i,x,v;fail[0]=0;
    for(i=0;i<26;i++) if((v=son[0][i])) fail[q[ed++]=v]=0;
    while(bg<ed)
    for(x=q[bg++],i=0;i<26;i++)
    if((v=son[x][i])) fail[q[ed++]=v]=son[fail[x]][i];
    else son[x][i] = son[fail[x]][i];
}

int query(char *buf)
{
    int res = 0;
    static bool vis[maxn];clr(vis);
    for(int now=0;*buf;buf++)
    {
        now = son[now][*buf-'a'];
        for(int last=now;last && !vis[last];last=fail[last])
        {
            res += val[last],vis[last]=1;
        }
        
//        while(last!=root)
//        {
//            res += val[last];
//            val[last]=0; //此处策略较慢设置访问标记
//            last = fail[last];
//        }
    }
    return res;
}
char buf[maxn];
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n;scanf("%d",&n);
        init();
        for(int i=1;i<=n;i++) { scanf("%s",buf);insert(buf,i); }
        make();scanf("%s",buf);
        printf("%d\n",query(buf));
    }
    return 0;
}
