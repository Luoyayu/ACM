#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,k,mod;
struct Matrix{int m[35][35];};
Matrix E,mat;
Matrix operator	* (Matrix a,Matrix b)
{
    Matrix c;
    memset(c.m,0,sizeof c.m);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++)
                c.m[i][j]=(c.m[i][j]+a.m[i][k]*b.m[k][j]%mod)%mod;
    return c;
}
Matrix power_mod(Matrix a,Matrix b,int x){
    while(x)
	{
        if(x&1)
            b = b*a;
        x >>= 1;
        a = a*a;
    }
    return b;
}
Matrix operator	+ (Matrix a,Matrix b){
    Matrix c;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            c.m[i][j]=(a.m[i][j]+b.m[i][j])%mod;
    return c;
}
Matrix solve(int x)
{
    if(x==1)
        return mat;
    Matrix res=solve(x/2),cur;
    if(x&1)
	{
        cur=power_mod(mat,E,x/2+1);
        res=res+cur*res;
        res=res+cur;
    }
	else
    {
        cur=power_mod(mat,E,x/2);
        res=res+cur*res;
    }	
    return res;
}

int main()
	{
    while(~scanf("%d%d%d",&n,&k,&mod))
	{
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
			{
                scanf("%d",&mat.m[i][j]);
                E.m[i][j]=(i==j?1:0);
            }
        Matrix res=solve(k);
        for(int i=0;i<n;i++)
		{
            for(int j=0;j<n-1;j++)
                printf("%d ",res.m[i][j]);
            printf("%d\n",res.m[i][n-1]);
        }
    }
    return 0;
}