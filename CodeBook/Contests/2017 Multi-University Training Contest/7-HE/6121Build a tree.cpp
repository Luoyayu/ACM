#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define home
#define dg(x) cout<<#x<<" = "<<x<<endl;
//从一开始连续异或到 n 的XOR值
//if n % 4==1 XOR= 1
//if n % 4==2 XOR= n+1
//if n % 4==3 XOR= 0
//if n % 4==0 XOR= n
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        ll n,k;scanf("%lld%lld",&n,&k);
        if(k==1)
        {
            ll kase = n%4;
            if(kase==1) printf("1\n");
            else if(kase==2) printf("%lld\n",n+1);
            else if(kase==3) printf("0\n");
            else printf("%lld\n",n);
            continue;
        }

        //n==27 k==3
        ll ans = n;
        //i's par = (i-1)/k
        while(1)
        {
            if(n-1<=k)
            {
                if((n-1)%2) ans ^= 1;
                break;
            }

            ll now = 1, x = 1;//x 全满k叉树当前层的节点总数, now 当前层的最左边节点序号
            while(now + x*k<=n-1)
            {
                x *= k;
                now += x;
            }

            ll last = n - now;//最后一层节点数

            ll l = (last-1)/x;//唯一 一颗不满k叉树左边合法树
            ll r = k-l-1;//右边已合法树
            if(l%2==1) ans ^= now;//
            if(r%2==1) ans ^= (now-x);
            n -= l*now+r*(now-x)+1;
            ans ^= n;
#ifdef home
            dg(x);dg(now);dg(last); dg(l);dg(r);dg(n);
#endif
        }
        printf("%lld\n",ans);
    }
    return 0;
}
