#include <cstdio>
double E[1002],F[1002];
int main()
{
	int n;
	double p;
	while(scanf("%d",&n)&&n!=0)
	{
		scanf("%lf",&p);
		E[0] = 0;
		F[0] = 0;
		for(int i=1; i<=n; i++)//F(x)=p(F(x-1)+E(x-1)*2+1)+(1-p)(F(x)+E(x)*2+1)
		{
			E[i] = i/p;
			F[i] = F[i-1]+2*E[i-1]-2.0*E[i]+(1+2.0*E[i])/p;
		}
		printf("%.3lf %.3lf\n",E[n],F[n]);
	}
	return 0;
}
