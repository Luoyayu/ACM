#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int N = 2;
struct Matrix
{
    __int64 v[N][N];
    Matrix()
    {
        memset(v,0,sizeof(v));
    }
};
Matrix multi(Matrix p1,Matrix p2)
{
    Matrix res;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            if(p1.v[i][j])
                for(int k=0;k<N;k++)
                    res.v[i][k]=(res.v[i][k]+(p1.v[i][j]*p2.v[j][k]))%mod;
    return res;
}
Matrix pow(Matrix p, __int64 k)
{
    Matrix t;
    for(int i=0;i<N;i++) t.v[i][i]=1;
    while(k)
    {
        if(k&1)
            t=multi(t, p);
        p = multi(p, p);
        k>>=1;
    }
    return t;
}
int main()
{
    __int64 k;
    while(scanf("%I64d",&k)!=EOF)
    {
        __int64 n = 3+2*k;//规律
        Matrix e,ans;
        e.v[0][0]=e.v[0][1]=e.v[1][0]=1;
        e.v[1][1]=0;
        ans = pow(e,n);
        printf("%I64d\n",(ans.v[0][1]+mod-1)%mod);
    }
    return 0;
}
