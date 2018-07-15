#include<bits/stdc++.h>
//数学问题——Simpson's rule
using namespace std;
double v1, v2, x, k;
const double esp = 1e-6;
inline double f(double t)
{
    return k / (pow ( hypot(v1*t, x-v2*t), 2) );
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
    int t;scanf("%d\n", &t);
    while (t--)
    {
        scanf("%lf%lf%lf%lf", &v1, &v2, &x, &k);
        printf("%.2f\n", ASR(0, 20000));
    }

    return 0;
}
