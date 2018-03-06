#include<cstdio>
#include<cmath>
#include<algorithm>
//super Euler 
using namespace std;
__int64 ans[3000005]={0};
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
    for(int i=1;i<3000005;i++)
        ans[i]=Euler(i);
    while(scanf("%I64d%I64d",&n,&m)!=EOF)
    {
    	__int64 sum=0;
   	for(__int64 i=n;i<=m;i++)
            sum+=ans[i];
        printf("%I64d\n",sum);
    }
    return 0;
}

