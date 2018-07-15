// Catalan number
#include <cstdio>
using namespace std;
typedef long long ll;
ll cat[40] = {1, 1};
int main() {
    int k = 0, n;
    for (int i = 2; i < 36; i++)
        for (int j = 0; j < i; j++) cat[i] += cat[j] * cat[i - j - 1];
    while (scanf("%d", &n) != EOF && n != -1)
        printf("%d %d %I64d\n", ++k, n, 2 * cat[n]);
    return 0;
}
