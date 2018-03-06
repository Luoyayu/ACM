#include<cstdio>
#include<cstring>
using namespace std;
struct Matrix
{
    int m[10][10];
}mat1,ans,E;
long k,mod,sum;
Matrix operator *(Matrix a,Matrix b)
{
    Matrix c;
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
        {
            c.m[i][j]=0;
            for(int k=0;k<10;k++)
                c.m[i][j]=(c.m[i][j]+a.m[i][k]*b.m[k][j]%mod)%mod;
        }
    return c;
}
Matrix operator +(Matrix a,Matrix b)
{
    Matrix c;
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            c.m[i][j]=(a.m[i][j]+b.m[i][j])%mod;
    return c;
}
Matrix power_mod(Matrix a,int x)
{
    Matrix b=E;
    while(x)
    {
        if(x&1)
            b = b*a;
        x >>= 1;
        a = a*a;
    }
    return b;
}
int main()
{
    while(scanf("%ld%ld",&k,&mod)!=EOF)
    {
        sum=0;
        memset(E.m,0,sizeof E.m);
        for(int i=0;i<10;i++)
            E.m[i][i]=1;
        for(int i=0;i<10;i++)
            scanf("%d",&mat1.m[0][i]);
        if(k<10) 
        {
            printf("%d\n",mat1.m[0][k]%mod);
            continue;
        }
        for(int i=1;i<10;i++)
            for(int j=0;j<10;j++)
                if(i==j+1)
                    mat1.m[i][j]=1;
                else
                     mat1.m[i][j]=0;
                     ans=power_mod(mat1,k-9);
        for( int i=0; i<=9; i++ )
        {
            sum += ans.m[0][i] * ( 9 - i );
            sum %= mod;
        }             
        printf("%ld\n",sum); 
    }
    return 0;
}