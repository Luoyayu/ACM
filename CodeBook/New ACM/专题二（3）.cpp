#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct Matrix
{
    int m[35][35];
} mat;
Matrix matrix_mul(Matrix mat1, Matrix mat2, int n, int mod)
{
    Matrix temp;
    memest(temp.m, 0, sizeof(temp.m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                temp.m[i][j] = (temp.m[i][j] + mat1[i][k] * mat2.m[k][j] % mod) % mod;
    return temp;
}
Matrix power_mod(int m, Matrix mat1, Matrix mat2,int mod)
{
    while (m)
    {
        if (m & 1)
            mat1 = matrix_mul(mat1, mat2,);
        m >>= 1;
        mat2 = matrix_mul(mat2, mat2);
    }
    return mat1;
}
int main()
{
    int n, k, mod;
    scanf("%d%d%d", &n, &k, &mod);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &mat.m[i][j]);
    ans=mat;
    for(int i=1;i<=k;i++)
        ans+=power_mod(i,mat,mat,mod);
    for (int i = 0; i < n; i++)
       {
           for (int j = 0; j < n-1; j++)
             printf("%d ",ans.m[i][j]%mod);
           printf("%d\n",ans[i][n-1])
       }
       return 0;
}