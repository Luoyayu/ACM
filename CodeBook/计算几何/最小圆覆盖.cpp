#include<bits/stdc++.h>
//线性算出最小覆盖圆的圆心坐标和半径

using namespace std;
const double pi = acos(-1);
struct Point
{
    double x,y;
}p[maxn];
inline double sqr(double x){return x*x;}
inline double dis(node a,node b)
{
    return hypot(a.x-b.x,a.y-b.y);
}
double  work()
{

}
int main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lf%lf",&o[i].x,&p[i].y);
    
}