#include<bits/stdc++.h>
//线性算出最小覆盖n个点的圆的圆心坐标和半径
//算法基于的事实有1.最小覆盖圆唯一存在
// 2.在给定的点集中,最多三点在最小覆盖圆上
//随机增量法算法步骤：
//随机化输入点
using namespace std;
const double pi = acos(-1);
const int maxn = 1e5 + 7;
struct Point
{
    double x,y;
    Point(double x=0, double y=0):x(x),y(y){}
}p[maxn],O;
Point center(Point a,Point b,Point c)
{
    double x1 = a.x, y1 = a.y,
     x2 = b.x, y2 = b.y,
     x3 = c.x, y3 = c.y,
     x21=x2-x1,y21=y2-y1,x31=x3-x1,y31=y3-y1,
     u21=(x2*x2-x1*x1+y2*y2-y1*y1)/2,
     u31=(x3*x3-x1*x1+y3*y3-y1*y1)/2,
     div = (x21*y31-x31*y21);
    return Point((u21*y31-u31*y21)/div,(u31*x21-u21*x31)/div);
}
inline double sqr(double x){return x*x;}
inline double dis(Point a,Point b) { return hypot(a.x-b.x,a.y-b.y); }

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF,n)
    {
        for(int i=0;i<n;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        random_shuffle(p,p+n);
        O.x = p[0].x, O.y=p[0].y;
        double r = 0;
        for(int i=1;i<n;i++)
        {
            if(dis(O,p[i])-r>0)
            {
                O = p[i];
                for(int j=0;j<i;j++)
                {
                    if(dis(p[j],O)-r>0)
                    {
                        O.x = (p[i].x+p[j].x)/2;
                        O.y = (p[i].y+p[j].y)/2;
                        r = dis(p[j],O);
                        for(int k=0;k<j;k++)
                        {
                            if(dis(p[k],O)-r>0)
                            {
                                O = center(p[i],p[j],p[k]);
                                r = dis(p[k], O);
                            }
                        }
                    }
                }
            }
        }
        printf("%.2lf %.2lf %.2lf\n",O.x,O.y,r);

    }
    return 0;
}
