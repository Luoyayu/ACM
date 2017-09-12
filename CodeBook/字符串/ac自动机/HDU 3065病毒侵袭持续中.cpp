#include <bits/stdc++.h>
using namespace std;
//ac自动机kuangbin模板
const int maxn = 1010*50;
const int Size = 128;
char vir[1010][51];
char txt[2000002];
int cnt[1010];
struct Trie
{
    int son[maxn][Size];
    int fail[maxn],end[maxn];
    int root, L;
    int newnode()
    {
        for(int i=0;i<Size;i++) son[L][i]=-1;
        end[L++] = 0;
        return L-1;
    }
    void init()
    {
        L=0;root = newnode();
    }
    void insert(char *buf,int idx)
    {
        int now=root,i=0,w;
        for(;*buf;buf++)
        {
            if(son[now][w=*buf]==-1)
                son[now][w]=newnode();
            now = son[now][w];
        }
        end[now]=idx;
    }
    void build()
    {
        queue<int>Q;
        fail[root]=root;
        for(int i=0;i<Size;i++)
            if(son[root][i]==-1)
                son[root][i]=root;
            else
            {
                fail[son[root][i]]=root;
                Q.push(son[root][i]);
            }
        while(!Q.empty())
        {
            int now  = Q.front();Q.pop();
            for(int i=0;i<Size;i++)
                if(son[now][i]==-1)
                    son[now][i]=son[fail[now]][i];
                else{
                    fail[son[now][i]] = son[fail[now]][i];
                    Q.push(son[now][i]);
                }
        }
    }
    void query(char *buf)
    {
        int now = root;
        for(;*buf;buf++)
        {
            now = son[now][*buf];
            for(int last=now;last!=root;last=fail[last])
                if(end[last]!=-1)
                    cnt[end[last]]++;
        }
    }
}ac;
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        ac.init();
        for(int i=1;i<=n;i++)
            scanf("%s",vir[i]), ac.insert(vir[i],i);
        ac.build();
        for(int i=1;i<=n;i++) cnt[i]=0;
        scanf("%s",txt);ac.query(txt);
        for(int i=1;i<=n;i++)
            if(cnt[i])
                printf("%s: %d\n",vir[i],cnt[i]);
    }
    return 0;
}