#include<bits/stdc++.h>
using namespace std;
//打表找规律,硬是没看出杨辉三角
inline int read()
{
    int x=0,f=1;char ch = getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
const int maxn = 2e5+7;
int a[maxn],b[maxn];
int main()
{
    int t = read();
    while(t--)
    {
        memset(b,0,sizeof(b));
        int n = read(), m = read();
        //对于第x次变换的第y个数,他的1~y的各项的系数为C(x+y-2,y-1)
        for(int i=1;i<=n;i++) a[i] = read();
        for(int i=1;i<=n;i++)//对于第m次变换的倒数第i个数而言
        {
            int mm = i-1, nn = i + m - 2;
            if((nn&mm)==mm) //每位数的倒数第i个数的二项式系数为奇数
                for(int j=i;j<=n;j++)
                    b[j] ^= a[j-i+1];
        }
        
        for(int i=1;i<=n;i++)
            printf("%d%c",b[i],i==n?'\n':' ');
    }
    return 0;
}