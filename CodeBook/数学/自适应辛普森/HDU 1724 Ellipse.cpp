#include<bits/stdc++.h>
//数学问题——Simpson's rule
using namespace std;
double l, r, A, B;
const double esp = 1e-10;
inline double f(double t)
{
   return sqrt(A*A-t*t);
}
inline double Simpson(double a, double b)
{
    double mid = a+(b-a)/2;
    return ( f(a) + 4 * f(mid) + f(b) ) * (b-a) / 6;
}
double ASR(double a, double b)
{
    double sum = Simpson(a,b);
    double mid = a+(b-a)/2;
    double suma = Simpson(a,mid);
    double sumb = Simpson(mid,b);
    return (fabs(sum-suma-sumb)<esp?sum:ASR(a,mid)+ASR(mid,b));
}
int main(int argc, char const *argv[])
{
    int t;scanf("%d", &t);
    while (t--)
    {
        scanf("%lf%lf%lf%lf",&A,&B,&l,&r);
        printf("%.3f\n", 2*B/A*ASR(l, r));
    }
    return 0;
}