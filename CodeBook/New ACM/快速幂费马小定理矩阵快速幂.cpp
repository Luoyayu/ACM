#include <cstdio>
#include <cstring>
using namespace std;
const int mod = 1000000007;
struct Matrix
{
    __int64 m[2][2];
};
//单位矩阵 
Matrix E = { 1, 0,
0, 1
};     
//推导出的目标矩阵 
Matrix P = { 0, 1,
1, 1
};         
Matrix matrix_mul(Matrix a, Matrix b)  //矩阵乘法+Mod
{
    int i, j, k;
    Matrix c;
    memset(c.m,0,sizeof c.m);
    for (i = 0; i<2; i++)
        for (j = 0; j<2; j++)
           for (k = 0; k<2; k++)
                c.m[i][j] += (a.m[i][k] * b.m[k][j]) % (mod - 1);
            c.m[i][j] %= (mod-1);

    return c;
}

Matrix quick_Mod_Matrix(__int64 m)  //矩阵快速幂
{
    Matrix mat1 = E, b = P;
    while (m)
    {
        if (m & 1)
            mat1 = matrix_mul(mat1, b);
        m >>= 1;
        b = matrix_mul(b, b);
    }
    return mat1;
}

__int64 quickmod(__int64 a, __int64 b)  //快速幂
{
    __int64 ans = 1;
    __int64 tmp = a % mod;
    while (b)
    {
        if (b & 1)  //b是奇数为真 ，先乘temp 1次
        {
            ans *= tmp;
            ans %= mod;
        }
                   //b为偶数，直接二分 
        tmp *= tmp;
        tmp %= mod;
        b >>= 1;
    }
    return ans;
}

int main()
{
    int a, b, n;
    while (scanf("%d%d%d", &a, &b, &n)==3)
    {
        Matrix p = quick_Mod_Matrix(n);
        printf("%d\n", (quickmod(a, p.m[0][0]) * quickmod(b, p.m[1][0])) % mod);
    }
    return 0;
}


//http://paste.ubuntu.com/23572147/