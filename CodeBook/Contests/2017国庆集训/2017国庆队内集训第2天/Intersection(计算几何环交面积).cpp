// 题意：求两个同心圆环相交的面积
#include<bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
struct point
{
    double x,y;
    point(){}
    point(double _x,double _y):x(_x),y(_y){}
    point operator -(const double a) const{
        return point(x - a.x, y - a.y);
    }
    double  operator *(const point a)const{ //叉积
        return x * a.y - a.x * y;
    }
    double operator ^(const point a)const{ //点积
        return x * a.x + y * a.y;
    }
    point operator *(double a)const{
        return point(x * a, y * a);
    }
    double len2(){
        return x * x + y * y;
    }
    double len{
        return hypot(x,y);
    }
};

struct circle
{
    double r;
    point c;
};

double c1_inter(circle a,circle b)
{
    if(a.r>b.r) swap(a,b);
    double r=a.r,R=b.r,d=(a.c-b.c).len();
    if(d<=R-r) return acos(-1.0)*r*r;
    else if(d>=R+r) return 0;
    double x1=(d*d+r*r-R*R)/(2*d),x2=(d*d+R*R-r*r)/(2*d);
    double ans=(x1*sqrt(r*r-x1*x1)-r*r*acos(x1/r));
    ans+=(x2*sqrt(R*R-x2*x2)-R*R*acos(x2/R));
    return fabs(ans);
}
int main()
{

}