#include <cstdio>
#include <cctype>
#include <cstring>
using namespace std;
const int mod = 3;
struct matrix
{
    int a[15][15];
};
matrix mat1;
matrix mat2;
matrix multi(matrix mat1, matrix mat2)
{
    matrix temp;
    memset(temp.a, 0, sizeof(temp.a));
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                temp.a[i][j] = (temp.a[i][j] + mat1.a[i][k] * mat2.a[k][j] % mod) % mod;
            }
        }
    }
    return temp;
    memset(temp.a, 0, sizeof temp.a);
}
int main()
{
    __int64 n;
    while (scanf("%I64d", &n) == 1)
    {
        if (n == 0 || n == 1)
        {
            printf("no\n");
            continue;
        }
        mat1.a[0][0] = 1; mat2.a[0][0] = 1;
        mat1.a[0][1] = 1; mat2.a[0][1] = 1;
        mat1.a[1][0] = 1; mat2.a[1][0] = 1;
        mat1.a[1][1] = 0; mat2.a[1][1] = 0;

        n = n - 2;
        while (n != 0)
        {
            if (n & 1)
                mat1 = multi(mat1, mat2);
            mat2 = multi(mat2, mat2);
            n >>= 1;
        }
        int c = (11 * mat1.a[0][0] + 7 * mat1.a[0][1]) % mod;

        if (c)
            printf("no\n");
        else printf("yes\n");
    }
    return 0;
}