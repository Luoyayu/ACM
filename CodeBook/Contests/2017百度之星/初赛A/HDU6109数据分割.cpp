// 题意看错。。。。
//题意:给出若干条件x==y或x!=y
//但数据之间的分割符丢了,但是对于每一组完整的数据最后一个条件加上导致不成立,问每组数据分别有多少约束条件
//一开始竟然忘记了相等具有传递性,而不等的关系可以用set维护
//那么对于一组相等的约束可以放到并查集中去维护
//对于不等的约束,可以考虑为每一个不等的 a b 使用集合数组维护

// 如有 a != b那么 在b集合中将b全部用a代替 ,
// 在a集合中插入b集合的所有元素，即对于所有的b我们就可以用a作为代替的变元
// 启发式set维护不等关系喵
#include <bits/stdc++.h>
using  namespace std;
#define  rank RANK
const int maxn = 100000+7;
int rank[maxn],par[maxn];
int ans[maxn];
set<int> q, un[maxn];

inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int find(int x)
{
    if(par[x]==x) return x;
    return par[x]=find(par[x]);
}
void unite(int x,int y)//目标是将小的不等集合并到大的不等集合上
{
    // x 对应大集合  , y对应小集合
    // 实现的话就是把y集合的元素全部插入到x集合中,同时对于y集合中的y全用x替代变元
    if(un[x].size()<un[y].size()) swap(x,y);// 保证小集合并到大集合上

    for(auto i : un[y]) //对于小集合的元素他们的不等集合
    {
        un[i].erase(y); //抹除y
        un[i].insert(x);//用大集合x代替
        un[x].insert(i);//y中的元素插入x集合
    }
    if(x==y) return;
    //此处就不能乱该合并顺序了
//    if(rank[x]<rank[y])
//    {
//        par[x]=y;
//    }
//    else
//    {
//        par[y]=x;
//        if(rank[x]==rank[y]) rank[x]++;
//    }
    par[y] = x;//小集合并入大集合
}
void clear()
{
    for(auto i : q)
    {
        par[i]=i;
        un[i].clear();
    }
}
void init(int n=maxn)
{
    q.clear();
    for(int i=0;i<n;i++)
    {
        par[i]=i,rank[i]=0;
        ans[i]=0;
        un[i].clear();
    }
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int cnt = 1;init();
        while(n--)
        {
            int x=read(),y=read();bool z=bool(read());
            int fx = find(x), fy = find(y); ans[cnt]++;
            q.insert(x), q.insert(y);
            if(z)//处理相等约束
            {
                if(fx==fy) continue;

                if(!un[fx].count(fy))
                    unite(fx, fy);//合并两个元素的祖先同时处理相应的不等集合
                else//在fx 的不等关系中找到 fy 发现矛盾点
                    cnt++, clear();

            } else{//处理不等约束

                if(fx==fy)//自己不等于自己此处推出矛盾
                    cnt++, clear();
                else//否则分别加入各自的不等集合
                    un[fx].insert(fy), un[fy].insert(fx);
            }
        }

        if(ans[cnt]==0) cnt--;//最后一组
        printf("%d\n",cnt<0?0:cnt);
        for(int i=1;i<=cnt;i++)
            printf("%d\n",ans[i]);
    }
    return 0;
}
