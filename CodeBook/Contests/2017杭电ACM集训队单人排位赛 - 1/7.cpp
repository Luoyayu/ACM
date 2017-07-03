//吃巧克力 计算几何
/*Problem Description
只记得正多边形上三个点的坐标。
正多边形的边数不会超过100。
想知道正多边形到底有多少条边

Output
输出正多边形最少有多少个角

Sample Input
0.000000 0.000000
1.000000 1.000000
0.000000 1.000000

Sample Output
4
*/
#include<bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
const double esp=1e-6;
struct node
{
    double x,y;
}a,b,c;
inline double retLen(node aa,node bb)
{
    return sqrt((aa.x-bb.x)*(aa.x-bb.x)+(aa.y-bb.y)*(aa.y-bb.y)) ;
}
double fgcd(double aa,double bb)
{
    if(bb<esp)
        return aa;
    return fgcd(bb,fmod(aa,bb));
}
inline void solve(double ra,double rb,double rc)
{
    double gcd=fgcd(ra,rb);
    gcd = fgcd(gcd,rc);
    printf("%.0f\n",pi/gcd);
}
int main()
{
    while(scanf("%lf%lf%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y)!=EOF)
    {
        double aa=retLen(b,c);
        double bb=retLen(a,c);
        double cc=retLen(a,b);

        double A = acos((bb*bb+cc*cc-aa*aa) / (2*bb*cc));
        double B = acos((aa*aa+cc*cc-bb*bb) / (2*aa*cc));
        double C = acos((bb*bb+aa*aa-cc*cc) / (2*bb*aa));
        solve(A,B,C);
    }
    return 0;
}
