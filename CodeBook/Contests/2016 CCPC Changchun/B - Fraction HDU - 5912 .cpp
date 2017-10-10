
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii; //<fenzi,fenmu>
#define CE std::ios::sync_with_stdio(false);
#define WA return make_pair(fenzi/gcd,fenmu/gcd);
#define TLE int gcd =__gcd(fenzi,fenmu);
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
pii jiafenshu(int an_1, pii in) //cal(an-1 + bn/an)
{
    int bn=in.first, an=in.second;
    int fenzi = an_1*an+bn, fenmu = an;
    TLE WA
}
pii chufenshu(int b, pii in) //cal(   b/ (c/a)  )
{
    int c=in.first, a=in.second;
    int fenzi = a*b, fenmu = c;
    TLE WA
}
int main()
{
    CE int t = read();
    for(int kase=1;kase<=t;kase++)
    {
        int n = read();
        int a[12]={0}, b[12]={0};
        for(int i=1;i<=n;i++) a[i] = read();
        for(int i=1;i<=n;i++) b[i] = read();
        pii ori;
        if(n==1)
        {
            int gcd = __gcd(a[1],b[1]);
            ori.first = b[1] / gcd;
            ori.second = a[1] / gcd;
        }
        else {
            int gcd = __gcd(b[n], a[n]);

            ori = make_pair(b[n] / gcd, a[n] / gcd);
            for (int i = 1; i <= n - 1; i++) {
                pii tmp = jiafenshu(a[n - i], ori);
                ori = chufenshu(b[n - i], tmp);
            }
        }
        printf("Case #%d: %d %d\n",kase,ori.first,ori.second);
    }
}