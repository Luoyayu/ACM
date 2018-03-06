//HDU 1398 Square Coins
// Created by gavin on 17.5.4.
//生成函数 构造多项式g(x) 使得x的n次方系数为f(n) x的值没有实际意义，
//可以根据级数收敛化简函数 比如f(n)=1的GF:g(x)=1+x+x^2+···+x^n 当-1<x<1时g(x)=1/(1-x)
//1+2x+3x^2+4x^3+5x^4+····=1/(1-x)^2
//1/(1-x)^n=C(n,1)x^1+C(n+1,2)x^2+C(n+2,3)x^3+····+C(n+k-1,k)x^k+···
//fibonacci[1,1,2,3,5,8,13···] gf:g(x)=x+x^2+2x^3+3x^4+5x^5+8x^6+13x^7+···
const int maxn=300+30;
int val[18];
int n, a[maxn], b[maxn];
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    for(int i=1;i<=17;i++)
        val[i]=i*i;
    while(scanf("%d",&n)!=EOF && n>0)
    {
        memset(a,0, sizeof(a));
        a[0]=1;
        for(int i=1;i<=17;i++)
        {
            memset(b,0, sizeof(b));
            for(int j=0;j*val[i]<=n;j++)
                for(int k=0;k+j*val[i]<=n;k++)
                    b[k+j*val[i]]+=a[k];
            memcpy(a, b, sizeof(b));
        }
        cout<<a[n]<<endl;
    }
    return 0;
}
