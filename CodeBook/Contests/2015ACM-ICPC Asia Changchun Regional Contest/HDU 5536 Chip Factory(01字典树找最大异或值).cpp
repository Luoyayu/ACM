#include <bits/stdc++.h>
using namespace std;
//题意：给出长度为n（n<=1000）的序列s，对于不同的i,j,k;
//求出max(i,j,k) (si+sj)^sk
//建立Trie树 O(n^2) = 10^6枚举 (i,j),每次删除(si,sj)查询最大值，在次插入即可
#define clr(a,b)memset(a,b,sizeof(a));
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
const int len=31;
const int maxn = 32*2000;
int a[maxn];
int root,tot;
struct {
    int ch[2],size;
}T[maxn];
void Insert(int x)
{
    int o=root;
    T[o].size++;
    for(int k=len;k>=0;k--)
    {
        int c=1&(x>>k);
        if(!T[o].ch[c]) T[o].ch[c]=++tot;
        o=T[o].ch[c];
        T[o].size++;
    }
}
inline void init()
{
    clr(T,0);tot = 1;root=1;
}

int query(int x)
{
    int o=root;
    for(int k=len;k>=0;k--)
    {
        int c=1&(x>>k);
        if(c==1)
        {
            if(T[o].ch[0]&&T[T[o].ch[0]].size) o=T[o].ch[0];
            else o=T[o].ch[1],x^=(1<<k);
        } else{
            if(T[o].ch[1]&&T[T[o].ch[1]].size) o=T[o].ch[1],x^=(1<<k);
            else o=T[o].ch[0];
        }
    }
    return x;
}
void Delete(int x)
{
    int o=root;
    T[o].size--;
    for(int k=len;k>=0;k--)
    {
        int c=1&(x>>k);
        o=T[o].ch[c];
        T[o].size--;
    }
}
int main()
{
    int t =read();
    while(t--)
    {
        int n=read();//不能前插0!
        init();
        for(int i=1;i<=n;i++)
            a[i] = read(),Insert(a[i]);
        int ans = 0;
        for(int i=1;i<=n;i++)
        {
            Delete(a[i]);
            for(int j=i+1;j<=n;j++)
            {
                Delete(a[j]);
                ans = max(ans,query(a[i]+a[j]));
                Insert(a[j]);
            }
            Insert(a[i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
