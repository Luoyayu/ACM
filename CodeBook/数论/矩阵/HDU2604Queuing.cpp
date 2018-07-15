#include <cstdio>
#include <cstring>
using namespace std;
struct Matrix {
    long a[5][5];
} mat1, mat2;
Matrix mqm(Matrix mat1, Matrix mat2, int mod) {
    Matrix temp;
    memset(temp.a, 0, sizeof temp.a);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                temp.a[i][j] =
                    (temp.a[i][j] + mat1.a[i][k] * mat2.a[k][j] % mod) % mod;
            }
        }
    }
    return temp;
}
int main() {
    __int64 L;
    int mod;
    while (scanf("%I64d%d", &L, &mod) == 2) {
        if (L <= 3)
            printf("%d\n", 2 * L % mod);
        else if (L == 4)
            printf("%d\n", 9 % mod);
        else if (L >= 5) {
            mat1.a[0][0] = 1;
            mat2.a[0][0] = 1;
            mat1.a[0][1] = 0;
            mat2.a[0][1] = 0;
            mat1.a[0][2] = 1;
            mat2.a[0][2] = 1;
            mat1.a[0][3] = 1;
            mat2.a[0][3] = 1;
            mat1.a[1][0] = 1;
            mat2.a[1][0] = 1;
            mat1.a[1][1] = 0;
            mat2.a[1][1] = 0;
            mat1.a[1][2] = 0;
            mat2.a[1][2] = 0;
            mat1.a[1][3] = 0;
            mat2.a[1][3] = 0;
            mat1.a[2][0] = 0;
            mat2.a[2][0] = 0;
            mat1.a[2][1] = 1;
            mat2.a[2][1] = 1;
            mat1.a[2][2] = 0;
            mat2.a[2][2] = 0;
            mat1.a[2][3] = 0;
            mat2.a[2][3] = 0;
            mat1.a[3][0] = 0;
            mat2.a[3][0] = 0;
            mat1.a[3][1] = 0;
            mat2.a[3][1] = 0;
            mat1.a[3][2] = 1;
            mat2.a[3][2] = 1;
            mat1.a[3][3] = 0;
            mat2.a[3][3] = 0;

            L = L - 5;
            while (L != 0) {
                if (L & 1) mat1 = mqm(mat1, mat2, mod);
                mat2 = mqm(mat2, mat2, mod);
                L >>= 1;
            }
            printf("%d\n", (9 * mat1.a[0][0] + 6 * mat1.a[0][1] +
                            4 * mat1.a[0][2] + 2 * mat1.a[0][3]) %
                               mod);
        }
    }
    return 0;
}