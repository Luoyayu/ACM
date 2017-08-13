#include <bits/stdc++.h>
//由叶子节点递推到根节点 走到叶子节点的期望长度为0
using namespace std;
#define clr(a,b) memset(a,b,sizeof(a));
#define lowbit(x) x&(-x)
const int maxn = 100000+1;
const double pi = acos(-1);
const int inf =0x3f3f3f3f;
typedef long long ll;

struct edge{int to,next,w;}e[maxn<<1];
int h[maxn],tot;
double f[maxn];
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
inline void addedge2(int u,int v,int w=0)
{
    e[++tot]=(edge){v,h[u],w};h[u]=tot;
    e[++tot]=(edge){u,h[v],w};h[v]=tot;
}

void dfs(int u,int fa)//深搜难以自拔 每层都维护一个栈存着当前函数的变量
{
    int cnt=0;
    for(int i=h[u];~i;i=e[i].next)
        if(e[i].to!=fa)
        {
            dfs(e[i].to,u);
            cnt++;f[u] += f[e[i].to]+1;//处理父亲节点
        }
    f[u]=cnt?f[u]/cnt:0;//处理u节点无子节点
}
int main()
{
    int n=read();
    clr(h,-1);
    for(int i=1;i<n;i++)addedge2(read(),read());
    dfs(1,-1);
    printf("%.16f",f[1]);
    return 0;
}
