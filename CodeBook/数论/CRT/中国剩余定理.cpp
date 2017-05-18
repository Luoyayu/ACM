//中国剩余定理(CRT)&&扩展欧几里得算法
//找出正整数解(x,y) 满足ax+by==gcd(a,b)

#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include <algorithm>
using namespace std;
int CRT(int a[],int m[],int n)
{
    int M=1;int ans=0;
    for(int i=1;i<=n;i++)
        M*=m[i];
    for(int i=1;i<=n;i++)
    {
        int x,y;
        int Mi=M/m[i];
        ex_gcd(Mi,m[i],x,y); //x为t1%m1逆元
        ans=(ans+Mi*x*a[i])%M;
    }
    if(ans<0) ans+=M;
    return ans;
}
int ex_gcd(int a,int b,int &x,int &y)
{
    int gcd;
    if(!b)
    {
        x=1,y=0;
        return a;
    }
    else
    {
        gcd = ex_gcd(b,a%b,y,x);
        y-=x*(a/b);
    }
    return gcd;
}
bool modular_liner_equation(int a,int b,int n)//ax==b(mod n) 的充要条件是n|ax-b
{
    int x,y;//设ax-b=yn ax-ny=b  r=gcd(a,n)有r个解
    int gcd=ex_gcd(a,n,x,y);
    if(b%gcd)
        return false;
    int x0=x*(b/gcd)%n;
    for(int i=1;i<=gcd;i++)
        printf("%d\n",(x0+i*(n/gcd)%n));
    return true;
}
