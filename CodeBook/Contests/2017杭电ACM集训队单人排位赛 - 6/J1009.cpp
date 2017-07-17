//题意:角色n个,K个怪物 第i个角色不打怪获得经验ci,分配到t个怪物获的经验ai+t*bi
//贪心大法好
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 1e5;
struct node
{
    int a, b, c, d;
}m[maxn+3];

bool cmp(const node &x, const node &y)
{
    return x.d > y.d;
}

ll sum[maxn+3];
int main()
{
    int t, n, k;
    scanf("%d",&t);
    while(t--)
    {
        ll tot = 0;
        scanf("%d%d",&n,&k);
        for(int i=1; i<=n; ++i)
        {
            scanf("%d%d%d",&m[i].a, &m[i].b, &m[i].c);
            m[i].d = m[i].a + m[i].b - m[i].c;
        }
        sort(m+1, m+1+n, cmp);
        for(int i=1; i<=n; ++i)
            tot += m[i].c, sum[i] = sum[i-1] + m[i].d;
        ll ans = 0;
        for(int i=1; i<=n; ++i)
        {
            int l = 1, r = min(n,k-1);//k-1为上限是因为有一个怪已经分配给i了。
            while(l<=r)
            {
                int mid = l+r>>1;
                if(m[mid].d > m[i].b)
                    l = mid+1;
                else
                    r = mid-1;
            }
            if(r < i) ans = max(ans, (ll)tot + sum[r] + m[i].d + (ll)(k-r-1)*m[i].b);
            else ans = max(ans, (ll)tot + sum[r] + (ll)(k-r)*m[i].b);//这里比较巧妙，当r==k-1时这样处理貌似有bug，因为最佳可能是每个人分一个怪，但这里剩下的一个怪强制分给i了，然而枚举到最后一个人时又正确了。
        }
        printf("%lld\n",ans);
    }
    return 0;
}

