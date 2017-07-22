#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
///什么是逆元？？逆元叫做数论倒数，比如a*x=1 x=1/a 在数论终不能瞎除
///那么在数论中有 ax==1(mod p) 把x叫做a关于p的逆元
///比如5x==1(mod 2) x=1, 比如2*3%5==1 3就是2关于5的逆元，也叫做2是3关于5的逆元
///a的逆元记作inv(a)
///应用比如(a/b)%p=(a*inv(b))%p 当a,p互质才有逆元要不然左边恒位0
///求数论的几种方法
///+ 1：费马小定理 a^(p-1)==1(mod p) => a^(p-2)==inv(a) (mod p) !注意1/a 数论中表示方法(,,• ₃ •,,)要求p为质数
///剩下的用快速幂求解 O(logn)(ง •̀_•́)ง


//<*****************费马小定理求解逆元******************>
//有点bug不建议采用
ll pow_mod(ll a, ll b, ll p) //a^(p-2)%p
{
    ll ret = 1;
    while(b)
    {
        if(b&1) ret=(ret*a)%p;
        a=(a*a)%p;
        b>>=1;
    }
    return ret;
}
inline ll Fermat(ll a,ll p)//求a关于p的逆元
{
    return pow_mod(a,p-2,p);
}

//<*****************费马小定理求解逆元******************>

///+2 扩展欧几里得求解逆元 通俗易懂 ax+by=1 (*) 那么x就是a关于b的逆元 ax==1(mod b)
///*式两边同时mod b 的



//<*****************Ex_gcd求解逆元******************>

ll ex_gcd(ll a,ll b,ll &x,ll &y)//x是a关于b的逆元
{
    if(!b)
    {
        x=1;y=0;return a;
    }
    ll ret=ex_gcd(b,a%b,y,x);
    y-=a/b*x;
    x=(x>0?x:(x%b+b)%b);//保证inv>0
    return ret;
}
int main()
{
    ll x,y,a,b;
    ex_gcd(a,b,x,y); //ax==1(mod b)
    printf("%lld\n",x);
}

//<*****************Ex_gcd求解逆元******************>


///+3 通过O(n)递推预处理n以内所有数的逆元 要求p是奇质数

//<*****************Ex_gcd求解逆元******************>





