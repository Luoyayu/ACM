//同余定理应用
/*
 *  给出正整数 n 和 m，统计满足以下条件的正整数对 (a,b) 的数量：
 *1. 1≤a≤n,1≤b≤m;
 *2. a×b 是 2016 的倍数
 *有同余定理得()*()%mod={()%mod*[()%mod]}%mod
 * 那么实际上在2016*2016范围内，举出n%2016对数进行分类,譬如
 * 2016*2017==2016*(2017%2016)(mod 2016) 即对尾数进行分类在看位数 i*j%2016==0
 */
#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn=2020;
ll a[maxn],b[maxn];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        ll ans=0;
        for(int i=0;i<2016;i++)//统计n有多少2016倍数
            a[i]=n/2016,b[i]=m/2016;
        int p=n%2016;
        int q=m%2016;
        for(int i=1;i<=p;i++)
            a[i]++;
        for(int i=1;i<=q;i++)
            b[i]++;
        for(int i=0;i<2016;i++)//对自然数按照mod 2016余数分类
            for(int j=0;j<2016;j++)
                if((i%2016*(j%2016))%2016==0)
                    ans+=a[i]*b[j];
        printf("%lld\n",ans);
    }
    return  0;
}