#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
const double PI=acos(double(-1));
int main()
{
  int t;
  double L, D, S;
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
		printf("%.2lf\n",PI*S*S);
	else if (S > D && S <= s1) 
		printf("%.2lf\n",PI*S*S-PI*S*S*acos(1.0*D/S)*2/(2*PI) + (1.0*L/2)*D); 
	else if (s0 > L)  
		printf("%.2lf\n",PI*s0*s0*j4*2/(2*PI) + 1.0*L/2*sqrt(s0*s0 - 1.0*L/2*L/2)+ PI*S*S*2*j2/(2*PI));
	else if (s0 > L/2) 
		printf("%.2lf\n",2*PI*s0*s0*j4/(2*PI)+L*D/2+PI*S*S*2*j2/(2*PI)-2*(PI*s0*s0*acos(1.0*L/2/s0)/(2*PI)-(1.0*L/2*sqrt(s0*s0 - 1.0*L/2*1.0*L/2)/2)));
	else      
		printf("%.2lf\n",2*PI*s0*s0*j4/(2*PI)+1.0*L*D/2+PI*S*S*2*j2/(2*PI));
	}
	return 0;
}