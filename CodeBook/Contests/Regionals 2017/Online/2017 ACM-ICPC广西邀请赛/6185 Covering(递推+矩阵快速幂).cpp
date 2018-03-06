#include <bits/stdc++.h>
//递推式f(x)=f(x-1)+5f(x-2)+f(x-3)-f(x-4)
using namespace std;
typedef long long LL;
typedef long long ll;
const int mod = 1000000007;
#define clr(x) memset(x,0,sizeof(x));
struct matrix
{
    LL ma[5][5];
};
LL muti(LL a,LL b)
{
    a%=mod;a+=mod;a%=mod;
    b%=mod;b%=mod;b%=mod;
    return (a*b)%mod;
}
matrix e, mat2;
matrix power_mod(matrix mat1,matrix mat2,int n=4)
{
    matrix T;
    memset(T.ma,0,sizeof T.ma);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++)
                T.ma[i][j] = (T.ma[i][j] + muti(mat1.ma[i][k], mat2.ma[k][j]))%mod;
    return T;
}
int main()
{
    ll n;
    while(~scanf("%lld",&n))
    {

        clr(e);clr(mat2);
        if(n==0)
        {
            printf("1\n");continue;
        }
        if(n==1)
        {
            printf("1\n"); continue;
        }
        if(n==2)
        {
            printf("5\n"); continue;
        }
        if(n==3)
        {
            printf("11\n"); continue;
        }
        if(n==4)
        {
            printf("36\n"); continue;
        }
        for(int i=0;i<4;i++) e.ma[i][i]=1LL;

        mat2.ma[0][0]=mat2.ma[0][2]=mat2.ma[1][0]=mat2.ma[2][1]=mat2.ma[3][2]=1;
        mat2.ma[0][1]=5;mat2.ma[0][3]=-1;

        n-=4;
        while(n)
        {
            if(n&1)
                e=power_mod(e,mat2);
            mat2=power_mod(mat2,mat2);
            n>>=1;
        }

        ll sum=0;
        sum+=muti(e.ma[0][0],36LL); sum%=mod;
        sum+=muti(e.ma[0][1],11LL); sum%=mod;
        sum+=muti(e.ma[0][2],05LL); sum%=mod;
        sum+=muti(e.ma[0][3],01LL); sum%=mod;
        printf("%lld\n",sum);
    }
    return 0;
}