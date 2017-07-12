/*
#include<bits/stdc++.h>
const double eps = 0.00000001;
using namespace std;
struct Point
{
    double x,y;
}A,B,C,O,D,E;
double r;
double DIFF(const Point &a,const Point &b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {

    if(r<0)
    {
        printf("All out\n");
        continue;
    }
    if(A.x==B.x&&B.y==A.y)
    {
        printf("All out\n");
        continue;
    }
    if(r==0)
    {

    }

        scanf("%lf%lf%lf%lf%lf%lf%lf",&O.x,&O.y,&r,&A.x,&A.y,&B.x,&B.y);
        double diffA,diffB,diffC;
        diffA = DIFF(O,A);diffB = DIFF(O,B);
        C.x=(A.x+B.x)/2.0;C.y=(A.y+B.y)/2.0;

        double k= (B.y-A.y)/(B.x-A.x);
        double d= fabs(O.x*k-O.y+A.y-A.x*k)/sqrt(k*k+1);
        diffC = DIFF(O,C);

        if(diffA>=r&&diffB>=r&&diffC>=r&&d>=r)//！！！
            printf("All out\n");
        else if(diffA<=r && diffB<=r && diffC<r)
            printf("All in\n");
        else
            printf("Part in\n");
    }
    return 0;
}


*/


#include<bits/stdc++.h>
using namespace std;
struct Point
{
    double x,y;
}A,B,O;
double R;
double getdis(double a, double b, double c, double d)
{
    return sqrt((a - c) * (a - c) + (b - d) * (b - d));
}
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%lf%lf%lf%lf%lf%lf%lf", &O.x, &O.y, &R, &A.x, &A.y, &B.x, &B.y);
        double k = (A.y - B.y) / (A.x - B.x);
        if(B.y == A.y&&B.x == A.x)
        {
            printf("All out\n");
            continue;
        }
        if(R < 0)
        {
            printf("All out\n");
            continue;
        }
        if(R == 0)
        {
            if((O.x == A.x&&O.y == A.y)||(O.x == B.x&&O.y == B.y))
                printf("All out\n");
            else if(O.y - A.y == k * (O.x - A.x))
                printf("Part in\n");
            else
                printf("All out\n");

            continue;
        }
        double lsx = (O.x / k + O.y + k * A.x - A.y) / (k + 1.0 / k);
        double lsy = k * (lsx - A.x) + A.y;
        if(lsx >= min(A.x, B.x)&&lsx <= max(A.x, B.x)&&lsy >= min(A.y, B.y)&&lsy <= max(A.y, B.y))
        {
            double d = getdis(lsx, lsy, O.x, O.y);
            if(d >= R)
                printf("All out\n");
            else
            {
                double d2 = getdis(O.x, O.y, A.x, A.y);
                double d3 = getdis(O.x, O.y, B.x, B.y);
                if(d2 > R||d3 > R)  printf("Part in\n");
                else    printf("All in\n");
            }
        }
        else
        {
            double d2 = getdis(O.x, O.y, A.x, A.y);
            double d3 = getdis(O.x, O.y, B.x, B.y);
            if(min(d2, d3) >= R) printf("All out\n");
            else if(max(d2, d3) <= R)   printf("All in\n");
            else    printf("Part in\n");
        }
    }
    return 0;
}
