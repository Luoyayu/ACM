#include <cstdio>
#include <cstring>
using namespace std;
#define mod 9973
struct matrix {
    int a[10][10];
};
matrix mat1, mat2, ans;
matrix multi(matrix mat1, matrix mat2, int n) {
    matrix temp;
    memset(temp.a, 0, sizeof(temp.a));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                temp.a[i][j] =
                    (temp.a[i][j] + mat1.a[i][k] * mat2.a[k][j] % mod) % mod;
    return temp;
}
matrix quick_mod(__int64 k, int n, matrix mat1, matrix mat2) {
    while (k) {
        if (k & 1) mat1 = multi(mat1, mat2, n);
        mat2 = multi(mat2, mat2, n);
        k >>= 1;
    }
    return mat1;
}
int main(void) {
    int T, n;
    __int64 k;
    scanf("%d", &T);
    while (T--) {
        int sum = 0;
        scanf("%d%I64d", &n, &k);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                scanf("%d", &mat1.a[i][j]);
                mat2.a[i][j] = mat1.a[i][j];
            }
        ans = quick_mod(k - 1, n, mat1, mat2);
        for (int i = 0; i < n; i++) sum += ans.a[i][i] % mod;
        printf("%d\n", sum % mod);
    }
    return 0;
}