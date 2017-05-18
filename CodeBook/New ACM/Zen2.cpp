//Euler function
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
__int64 Euler(int x)
{
    __int64 temp=x,index=x;
    for(__int64 i=2;i*i<=index;i++)
    {
        if(!(x%i))
        	temp-=temp/i;
        while(!(x%i)) 
			x/=i;
    }
    if(x>1) 
    	temp-=temp/x;
    return temp;
}
int main()
{
    __int64 m,n;
    while(scanf("%I64d",&n)!=EOF,n)
        printf("%I64d\n",n-1-Euler(n));
}

