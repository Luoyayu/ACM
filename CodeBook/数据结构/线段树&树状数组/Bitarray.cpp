#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+7;
#define lowbit(x) x&(-x)
#define cmax(a,b) a=max(a,b)
struct Bitarray

{
    int c[maxn];
    inline void init()
    {
       memset(c,0, sizeof(c));
    }
    void add(int pos,int value)
    {
        while(pos<maxn)
        {
            cmax(c[pos],value);
            pos += lowbit(pos);
        }
    }

    int sum(int pos)
    {
        int res = 0;
        while(pos)
        {
            cmax(res,c[pos]);
            pos -= lowbit(pos);
        }
        return res;
    }
};
struct node
{
    int l,r,v;
    node(){}
    node(int l,int r,int v) :l(l),r(r),v(v){}
    bool operator<(const node &b) const
    {
        return l<b.l;
    }
}o[maxn];
vector<int> RR;
int main()
{
    int n;
    Bitarray Bit;
    Bit.init();
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int L,R;
        scanf("%d%d",&L,&R);
        o[i]= node(L, R, R-L+1);
        RR.push_back(R);
    }
    sort(RR.begin(),RR.end());
    RR.end()=unique(RR.begin(),RR.end());

    int ans = 0;
    for(int i=1;i<=n;i++)
    {
        int L = o[i].l;
        int R = o[i].r;
        int V = o[i].v;

        int orgi_id = lower_bound(RR.begin(),RR.end(),R)-RR.begin();

        int tmp = Bit.sum(orgi_id);
        ans = max(ans,V+tmp);
        Bit.add(orgi_id+1,V+tmp);
    }
    return !printf("%d\n",ans);
}