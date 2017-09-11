#include<bits/stdc++.h>
using namespace std;
//艾斯奥特曼第二弹
#define Size 98
const int maxn = 150000;
int son[maxn][Size];
int fail[maxn];
char s[10005];
#define clr(a) memset(a,0,sizeof a);
int tot;
void insert(char *s,int id)
{
    int dep,nxt,w;
    for(dep=0;*s;dep=nxt,s++)
    {
        nxt = son[dep][w=*s-32];
        if(!nxt) {clr(son[tot]);son[dep][w]=nxt= tot++;}
    }
    son[dep][95] = id;
}


void make()
{
    static int q[maxn];
    int bg=0, ed=0, i, x, v;fail[0] = 0;
    for(i=0;i<95;i++) if((v=son[0][i])) fail[q[ed++]=v]=0;
    while(bg<ed)
        for(x=q[bg++],i=0;i<95;i++)
            if((v=son[x][i])) fail[q[ed++]=v]=son[fail[x]][i];
            else son[x][i] = son[fail[x]][i];
}
int vir[4];
void find(char *s)
{
    static bool vis[550];clr(vis);
    int v;clr(vir);
    for(int x=0;*s;s++)
    {
        x = son[x][*s-32];
        for(int j=x;j;j=fail[j])
        {
            if((v=son[j][95])&&!vis[v])
           vir[++vir[0]]=v; vis[v] = 1;
        }
    }
}
inline void init(){tot=1;clr(son[0]);}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        init();
        int ans = 0;
        for(int i=1;i<=n;i++)
            scanf("%s",s),insert(s,i);
        make();
        int m;scanf("%d",&m);
        for(int i=1;i<=m;i++)
        {
            scanf("%s",s);
            find(s);
            if(vir[0])ans++;
            else continue;
            printf("web %d:", i);
            sort(vir+1,vir+vir[0]+1);
            for(int j=1;j<=vir[0];j++)
                printf(" %d",vir[j]);
            puts("");
        }
        printf("total: %d\n", ans);
    }
    return 0;
}