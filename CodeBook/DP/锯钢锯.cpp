#include <cstdio>
#include <algorithm>
#include <time.h>
const int inf = 999999999;
using namespace std;
int p[100]={0,1,5,8,9,10,17,17,20,24,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,56,44,432,4234};
int r[100];
int dp(int n)
{
	int q;
	if(r[n]>0) return r[n];
	if(n==0)
		return 0;
	else
	{
		q=-inf;
		for(int i=1;i<=n;i++)
			q=max(q,dp(n-i)+p[i]);
	}
	r[n]=q;
	return q;
}
int dp2(int n)
{
	int j,i,q;
	r[0]=0;
	for(j=1;j<=n;j++)
	{
		q=-inf;
		for(i=1;i<=j;j++)
			q=max(q,p[i]+r[i-j]);
	}
	r[j]=q;
return r[n];
}
int main()
{
	int n;
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
			r[i]=-inf;
		printf("%d\n",dp2(n));
		printf("Time used =%.2lf\n",(double)clock()/CLOCKS_PER_SEC);
	}	
		
	return 0;
}