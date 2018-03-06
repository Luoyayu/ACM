#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100+5;
struct point
{
    double x,y;

}M1[maxn],M2[maxn];
double MIN(double x,double y)
{
    return x<y?x:y;
}
double MAX(double x,double y)
{
    return x>y?x:y;
}
double cp(point pi,point pj,point pk)
{
    return (pk.x-pi.x)*(pj.y-pi.y)-(pj.x-pi.x)*(pk.y-pi.y);
}
bool on_seg(point pi,point pj,point pk)
{
   if(pk.x>=MIN(pi.x,pj.x)&&pk.x<=MAX(pi.x,pj.x)&&pk.y>=MIN(pi.y,pj.y)&&pk.y<=MAX(pi.y,pj.y))
        return true;
    return false;
}
bool SI(point p1,point p2,point p3,point p4)
{
    double d1=cp(p3,p4,p1),d2=cp(p3,p4,p2),d3=cp(p1,p2,p3),d4=cp(p1,p2,p4);
    if(d1*d2<0&&d3*d4<0)
        return true;
    else if(!d1&&on_seg(p3,p4,p1))
        return true;
    else if(!d2&&on_seg(p3,p4,p2))
        return true;
    else if(!d3&&on_seg(p1,p2,p3))
        return true;
    else if(!d4&&on_seg(p1,p2,p4))
        return true;
    return false;
}
int main()
{
    int n;
    while(scanf("%d",&n)&&n)
    {
        int SUM=0;
        for(int i=0;i<n;i++)
            scanf("%lf%lf%lf%lf",&M1[i].x,&M1[i].y,&M2[i].x,&M2[i].y);
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                if(SI(M1[i],M2[i],M1[j],M2[j]))
                    SUM++;
        printf("%d\n",SUM);
    }
    return 0;
}
