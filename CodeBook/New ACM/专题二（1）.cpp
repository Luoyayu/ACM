//矩阵快速幂
#include <cstdio>
#include <cstring>
#include <cstdlib>
#define mod 1000
using namespace std;
struct Matrix
{
    __int64 m[2][2]
};
Matrix E = {1, 0, 0, 1};
Matrix p = {1, 1, 1, 0};
Matrix operator * (Matrix mat1, Matrix mat2)
{
    Matrix temp;
    memset(c.m, 0, sizeof(c.m));
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                trmp.m[i][j] += (  mat1.m[i][k] * mat2.m[k][j] ) % mod;
    return temp;
}
Matrix quick_Mod_Matrix(__int64 m)
{
    Matrix mat1 = E;
    Matrix mat2 = p;
    while (m)
    {
        if (m & 1)
            mat1 = mat1 * mat2;
        m >>= 1;
        mat2=mat2 * mat2;
    }
    return mat1;
}
int main()
{
    __int64 n;
    while (scanf("%I64d", &n) != EOF && n != -1)
    {
        if (n == 0 || n == 1)
            printf("%d\n", n);
        else
            {
                Matrix p=quick_Mod_Matrix(n);
                printf("%d\n",p.m[1][0]%mad);
            }
    }
    return 0;
}