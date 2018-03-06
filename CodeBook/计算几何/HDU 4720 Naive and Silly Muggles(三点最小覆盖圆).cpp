//HDU 4720 Naive and Silly Muggles
#include <bits/stdc++.h>
using namespace std;
//三点的最小覆盖圆
//如果有钝角的话最小覆盖圆在钝角对应的边的中点形成的圆上
inline double R(double a,double b,double c,double d)
{
    return (a-c)*(a-c)+(b-d)*(b-d);
}
int main()
{
    int t;scanf("%d",&t);
    for(int kase=1;kase<=t;kase++)
    {
        double x1,x2,x3,y1,y2,y3;
        scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3);
        double x,y;
        scanf("%lf%lf",&x,&y);
        printf("Case #%d: ",kase);

        double e1 = R(x2,y2,x3,y3);
        double e2 = R(x1,y1,x3,y3);
        double e3 = R(x1,y1,x2,y2);

        double x0,y0,r;
        if(e2+e3-e1<0) //(x1,y1)为钝角
        {
            x0=(x2+x3)/2;y0=(y2+y3)/2;
            r=R(x1,y1,x0,y0);
        }
        else if(e1+e3-e2<0)//(x2,y2)为钝角
        {
            x0=(x1+x3)/2;y0=(y1+y3)/2;
            r=R(x1,y1,x0,y0);
        }
        else if(e1+e2-e3<0)//(x3,y3)为钝角
        {
            x0=(x1+x2)/2;y0=(y1+y2)/2;
            r=R(x1,y1,x0,y0);
        }
        else
        {
            double x21=x2-x1,y21=y2-y1,x31=x3-x1,y31=y3-y1;//圆心公式
            double u21=(x2*x2-x1*x1+y2*y2-y1*y1)/2;
            double u31=(x3*x3-x1*x1+y3*y3-y1*y1)/2;
            double div = (x21*y31-x31*y21);
            x0=(u21*y31-u31*y21)/div;
            y0=(u31*x21-u21*x31)/div;

            /*x0=((y2-y1)*(y3*y3-y1*y1+x3*x3-x1*x1)-(y3-y1)*(y2*y2-y1*y1+x2*x2-x1*x1))/(2.0*((x3-x1)*(y2-y1)-(x2-x1)*(y3-y1)));
            y0=((x2-x1)*(x3*x3-x1*x1+y3*y3-y1*y1)-(x3-x1)*(x2*x2-x1*x1+y2*y2-y1*y1))/(2.0*((y3-y1)*(x2-x1)-(y2-y1)*(x3-x1)));
             */
            r=R(x1,y1,x0,y0);
        }

        double dis = R(x0,y0,x,y);
        if(dis>r) printf("Safe\n");
        else printf("Danger\n");
    }
    return 0;
}