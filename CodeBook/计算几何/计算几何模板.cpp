#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;

const double eps = 1e-8;
const double PI = acos(-1.0);
int sgn(double x) //符号：相等为0 小于0为-1, 大于0为1
{
    if(x<-eps) return -1;
    if(x>eps) return 1;
    return 0;
}
struct Point
{
    double x,y;
    Point(){x=y=0;}
    Point(double _x,double _y):x(_x),y(_y){}
    Point operator -(const Point &b)const{
        return Point(x - b.x,y - b.y);
    }
    Point operator +(const Point b) const {
        return Point(x+b.x,y+b.y);
    }
    double operator * (const Point &b)const{
        return x*b.x + y*b.y;
    }
    Point operator * (double b)const{
        return Point(b*x, y*b);
    }
    Point operator / (double b)const{
        return Point(x/b, y/b);
    }
    double operator ^(const Point b)const { //叉积
        return x*b.y - y*b.x;
    }
    void input(){
        scanf("%lf %lf",&x,&y);
    }
    void output() {
        printf("Point/Vector= (%lf,%lf)\n",x,y);
    }
    double len_sqr(){
        return x*x + y*y;
    }
    double len(){ //向量的模
        return hypot(x,y);
    }
};

double cross(Point a,Point b){ //叉积
    return a.x*b.y-a.y*b.x;
}

struct Line //线段/直线
{
    Point s,e;
    Line(){s=e=Point();}
    Line(Point _s,Point _e):s(_s),e(_e){}
};

//判断点是否在线段上
bool point_on_segment(Point P,Line L)
{
    return
        sgn(cross((L.s-P),(L.e-P))) == 0 &&
        sgn((P.x - L.s.x) * (P.x - L.e.x)) <= 0 &&
        sgn((P.y - L.s.y) * (P.y - L.e.y)) <= 0;
}

double dist_point_to_point(Point a,Point b)//返回两点距离
{
    return sqrt( (a-b) * (a-b) );
}

double dist_point_to_line(Point P, Line L)
{
    Point a = L.s, b = L.e;
    return fabs(cross(P-a,b-a))/(b-a).len();
}

double dist_point_to_segment(Point P,Line L)
{
    Point a = L.s, b = L.e;
    if(sgn( (P-a)*(b-a) )>=0 && sgn( (P-b)*(a-b))>=0)
        return fabs(cross(P-a,b-a))/(b-a).len();
    return min((P-a).len(),(P-b).len());
}

//*判断点在凸多边形内
//点形成一个凸包，而且按逆时针排序（如果是顺时针把里面的<0改为>0）
//点的编号:0~n-1
//返回值：
//-1:点在凸多边形外
//0:点在凸多边形边界上
//1:点在凸多边形内
int point_in_ConvexPoly(Point a,Point p[],int n)
{
    for(int i = 0;i < n;i++)
    {
        if(sgn((p[i]-a)^(p[(i+1)%n]-a)) < 0)return -1;
        else if(OnSeg(a,Line(p[i],p[(i+1)%n])))return 0;
    }
    return 1;
}


//判断线段相交
bool is_line_inter(Line l1,Line l2)
{
    return
            max(l1.s.x,l1.e.x) >= min(l2.s.x,l2.e.x) &&
            max(l2.s.x,l2.e.x) >= min(l1.s.x,l1.e.x) &&
            max(l1.s.y,l1.e.y) >= min(l2.s.y,l2.e.y) &&
            max(l2.s.y,l2.e.y) >= min(l1.s.y,l1.e.y) &&
            sgn((cross((l2.s-l1.e),(l1.s-l1.e))))*sgn(cross((l2.e-l1.e),(l1.s-l1.e))) <= 0 &&
            sgn(cross((l1.s-l2.e),(l2.s-l2.e)))*sgn(cross((l1.e-l2.e),(l2.s-l2.e))) <= 0;
}

//判断凸多边形
//允许共线边
//点可以是顺时针给出也可以是逆时针给出
//点的编号1~n-1
bool is_convex(Point poly[],int n)
{
    bool s[3];
    memset(s,false,sizeof(s));
    for(int i = 0;i < n;i++)
    {
        s[sgn( cross((poly[(i+1)%n]-poly[i]),(poly[(i+2)%n]-poly[i]) ))+1] = true;
        if(s[0] && s[2])return false;
    }
    return true;
}



struct circle{
    double r;
    Point c;
};

double circle_inter_area(circle a, circle b)//求两圆相交的面积
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
    Point p[]={Point(0,0),Point(1,0), Point (0,1)};

    Point D(0.5,0.5);

    printf("%d\n",inConvexPoly(D,p,3));

}
