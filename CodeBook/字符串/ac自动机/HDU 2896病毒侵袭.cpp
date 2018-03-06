#include<bits/stdc++.h>
using namespace std;
//艾斯奥特曼第二弹
#define Size 96//ascii中用95个可见字符(32~126)
#define clr(a) memset(a,0,sizeof a);
const int maxn = 150000;
int son[maxn][Size],fail[maxn],val[maxn];
char s[10005];
int tot;
void insert(char *s,int id)
{
    int i,j,w;
    for(i=0;*s;i=j,s++)
    {
        j = son[i][w=*s-32];
        if(!j) {clr(son[tot]);son[i][w]=j=tot++;}
    }
    val[i] = id;
}
void make()
{
    static int q[maxn];
    int bg=0,ed=0,i,x,v;fail[0]=0;
    for(i=0;i<Size;i++) if((v=son[0][i])) fail[q[ed++]=v]=0;
    while(bg<ed)
    for(x=q[bg++],i=0;i<Size;i++)
    if((v=son[x][i])) fail[q[ed++]=v]=son[fail[x]][i];
    else son[x][i] = son[fail[x]][i];
}
int vir[4];
void find(char *s)
{
    static bool vis[550];clr(vis);clr(vir);
    for(int x=0,v;*s;s++)
    {
        x=son[x][*s-32];
        for(int j=x;j;j=fail[j])
            if((v=val[j]) && !vis[v])
                vir[++vir[0]]=v,vis[v] = 1;
    }
}
inline void reset(){tot=1;clr(son[0]);}
int main()
{
    ios::sync_with_stdio(0);
    int n,m;
    while(cin>>n)
    {
        reset();
        for(int i=1;i<=n;i++) cin>>s,insert(s,i);
        make();cin>>m;
        int ans = 0;
        for(int i=1;i<=m;i++)
        {
            cin>>s;find(s);
            if(vir[0])ans++;
            else continue;
            cout<<"web "<<i<<":";
            sort(vir+1,vir+vir[0]+1);
            for(int j=1;j<=vir[0];j++)
                cout<<" "<<vir[j];
            cout<<endl;
        }
        cout<<"total: "<<ans<<endl;
    }
    return 0;
}