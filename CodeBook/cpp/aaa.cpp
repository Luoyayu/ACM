#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <string>
#include <cmath>
#include <cctype>
using namespace std;
const double PI=acos(double(-1));
int main()
{
  int t;
  double L, D, S,  a0, a1, a2, ans;
  scanf("%d", &t);
  while (t--) 
{
    scanf("%lf%lf%lf", &L, &D, &S);
    double j1 = atan(L/2/D);
    double j2 = PI - j1;
    double j3 = PI/2 - j1;
    double j4 = PI - j3;
    double s1 = sqrt(L/2*L/2 + D*D);
    double s0 = S - s1;

    if (S <= D) 
      ans = PI*S*S;
	else if (S > D && S <= s1)
      ans = PI*S*S - (PI*S*S*acos(D/S)*2/(2*PI) - sqrt(S*S - D*D)*D);
    else if (s0 > L) 
    {
		a0 = PI*s0*s0*j4*2/(2*PI);
		a2 = PI*S*S*2*j2/(2*PI);
		double h = sqrt(s0*s0 - L/2*L/2);
		a1 = L/2*h;
		ans = a0+a1+a2;
    }
     else if (s0 > L/2) 
     {
      a2 = PI*S*S*2*j2/(2*PI);
      a0 = 2*PI*s0*s0*j4/(2*PI);
      a1 = L*D/2;
      double h = sqrt(s0*s0 - L/2*L/2);
      double aa = L/2*h/2;
      double j6 = acos(L/2/s0);
      double ab = PI*s0*s0*j6/(2*PI);
      ab -= aa;
      ans = a0+a1+a2-2*ab;
    } 
    else 
    {
      a2 = PI*S*S*2*j2/(2*PI);
      a0 = 2*PI*s0*s0*j4/(2*PI);
      a1 = L*D/2;
      ans = a0+a1+a2;
    }

 	printf("%.2f\n", ans);
  }
    return 0;
}