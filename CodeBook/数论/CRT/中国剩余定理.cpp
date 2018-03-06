#include<bist/stdc++.h>
using namespace std;
//中国剩余定理(CRT)&&扩展欧几里得算法
//ex_gcd()用来找出正整数解(x,y) 满足ax+by==gcd(a,b)

//CRT 回顾
//1.对于模乘互质的情况
//同余方程组有整数解
/*
    x==a1(mod m1)
    x==a2(mod m2)
    x==a3(mod m3)
    .....
    x==ak(mod mk)
}*/
//并且在% M = m1 * m2 * m3 * m4 * ··· * mk下有唯一解
//解x = (a1*M1*inv(M1)+ ··· + ak*Mk*inv(Mk))%M
//Mi = M / mi, inv(Mi)为Mi%mi的逆元 Mi * inv(Mi) == 1 (mod mi)


//2.对于模乘积不互质的情况
/*
    x==a1(mod m1)
    x==a2(mod m2)
合并方程{
    x==a1+k1*m1
    x==a2+k2*m2
    => a1+k1*m1 = a2+k2*m2 
    =>a2-a1 = k1*m1+k2*m2
    使用ex_gcd()求出k1最小整数解带入 x == a1+k1*m1 求得x
    合并方程组=>  x==m1*K + a1 (mod lcm(m1,m2))
             =>  x==a(mod m)
             a = m1*( c/d *inv(m1/d) )
             m = lcm(m1,m2)

}
*/


int CRT(int a[],int m[],int n)//模互质
{
    int M=1;int ans=0;
    for(int i=1;i<=n;i++)
        M*=m[i];//模做积
    for(int i=1;i<=n;i++)
    {
        int x,y;
        int Mi=M/m[i];
        ex_gcd(Mi,m[i],x,y); //x为t1%m1逆元 解出inv(Mi) mod mi
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

int CRT()
{
    //x == r1(mod m1)
    //x == r2(mod m2)
    //c = r2-r1
    //d =gcd(m1,m2)
    //
    int flag = 0, m1 =a[0], r1 = b[0];
    for(int i=1;i<m;i++)
    {
        int x,y;
        int m2 = a[i],r2 = b[i];
        int d = ex_gcd(m1,m2,x,y);//求出gcd(m1.m2) 解的m1*x + m2*y=gcd(m1,m2)
        int c = r2-r1;
        if(c % d)
        {
            flag = 1;
            break;
        }
        int t = m2 / d;
        x = (c/d*x%t+t)%t;
        r1 += x*m1;//r1为最小解
        m1=m1/d*m2;//合并后的m
    }
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
