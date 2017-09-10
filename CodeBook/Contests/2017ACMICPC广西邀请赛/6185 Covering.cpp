#include <bits/stdc++.h>
//递推式f(x)=
using namespace std;
typedef long long LL;
typedef long long ll;
const int mod = 1000000007;
struct matrix
{
    LL ma[5][5];
};
LL muti(LL a,LL b)
{
    a%=mod;a+=mod;a%=mod;
    b%=mod;b%=mod;b%=mod;
    return (a*1LL*b)%mod;
}
matrix mat1, mat2;
matrix power_mod(matrix mat1,matrix mat2)
{
    matrix T;
    memset(T.ma,0,sizeof T.ma);
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            for(int k=0;k<4;k++)
            {
                T.ma[i][j] = (T.ma[i][j] + muti(mat1.ma[i][k],mat2.ma[k][j]))%mod;
            }
    return T;
}
int main()
{
    ll n;
    while(~scanf("%lld",&n))
    {
        memset(mat1.ma,0,sizeof mat1.ma);
        memset(mat2.ma,0,sizeof mat2.ma);
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
        for(int i=0;i<4;i++) mat1.ma[i][i]=1LL;

        mat2.ma[0][0]=mat2.ma[0][2]=mat2.ma[1][0]=mat2.ma[2][1]=mat2.ma[3][2]=1;
        mat2.ma[0][1]=5;mat2.ma[0][3]=-1;

        n-=4;
        while(n)
        {
            if(n&1)
                mat1=power_mod(mat1,mat2);

            mat2=pow_mod(mat2,mat2);
            n>>=1;
        }

        ll sum=0;
        sum+=muti(mat1.ma[0][0],36LL); sum%=mod;
        sum+=muti(mat1.ma[0][1],11LL); sum%=mod;
        sum+=muti(mat1.ma[0][2],05LL); sum%=mod;
        sum+=muti(mat1.ma[0][3],01LL); sum%=mod;
        printf("%lld\n",sum);
    }
    return 0;
}