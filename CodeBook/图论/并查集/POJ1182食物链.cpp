//#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
#define rank RANK
const int maxn = 50007;
int par[maxn*3],rank[maxn*3];
int find(int x)
{
    if(par[x]==x) return x;
    return par[x]=find(par[x]);
}
void unite(int x,int y)
{
    x = find(x),  y= find(y);
    if(x==y) return ;
    if(rank[x]<rank[y]){
        par[x]=y;
    } else{
        par[y]=x;
        if(rank[x]==rank[y]) rank[x]++;
    }
}
void init(int n)
{
    for(int i=0;i<=n;i++)
        par[i]=i,rank[i]=0;
}
inline bool sameSet(int x,int y)
{
    return find(x)==find(y);
}
//对于动物i,建立 i-A,i-B,i-C;
//对这 N*3 个元素建立并查集
//并查集里的每一组表示组内元素要么同时发生要么同时不发生
//例如如果 x，y属于同一类,需要合并 x-A和y-A，x-B和y-B,x-C和y-C
//如果 x吃y那么有 x-A和y-B, x-B和y-C ,x-C和y-A;
//上面存的都是一定发生的情况同一组内
//x 表示 x-A , x+N 表示 x-B, x+2*N 表示 x-C
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);//POJ有毒用while ==2 ~ !=EOF 都报WA

    int ans = 0, n2 = n*2;
    init(n*3);

    for(int i=0;i<k;i++)
    {
        int type,x,y;scanf("%d%d%d",&type,&x,&y);
        x--;y--;
        if(x>=n||y>=n||x<0||y<0)
        {
            ans++;
            continue;
        }

        if(type==1) //x和y属于一类
        {
            //check x-A和y-B x-A和y-C
            if(sameSet(x,y+n)||sameSet(x,y+n2)) // 合并写法
                ans++;
            else//合并x-A和y-A ,x-B和y-B, x-C和y-C
            {
                unite(x,y);
                unite(x+n,y+n);
                unite(x+n2,y+n2);
            }
        }

        else//x 吃 y
        {
            //check x-A和 y-A, x-A和y-C
            if(sameSet(x,y)||sameSet(x,y+n2))
                ans++;
            else
            {
                unite(x,y+n);
                unite(x+n,y+n2);
                unite(x+n2,y);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
