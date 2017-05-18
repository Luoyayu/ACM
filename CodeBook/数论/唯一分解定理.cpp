#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
	__int64 sum,n,i,m,ant;
	while(~scanf("%I64d",&n) && n != 0)
	{
		m=n/2;
		sum=1;
		for(i=2;i<=m;i++)
		{
			if(n%i == 0){
				ant=0;
				while(n%i == 0)
				{
					n=n/i;
					ant++;
				} 
				sum=sum*(ant+1);
				if( n == 1 ) break; 
			}
		}
		if(n>1)sum+=1;
			printf("%I64d\n",sum);
	}
	return 0;
} 