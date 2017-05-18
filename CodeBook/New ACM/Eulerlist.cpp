#include <cstdio>
using namespace std;
const int N = 3000005;
__int64 Euler[N];
void euler() //super Euler list
{
    Euler[1] = 0;
    for (int i = 2; i < N; i++)
        Euler[i] = i;
    for (int i = 2; i < N; i++)
        if (Euler[i] == i)
            for (int j = i; j < N; j += i)
                Euler[j] = Euler[j] / i * (i - 1);
    for (int i = 2; i < N; ++i)
        Euler[i] += Euler[i - 1];
}
int main()
{
    euler();
    int a, b;
    while (scanf("%d%d", &a, &b) != EOF)
    {
        printf("%d %d\n" ,Euler[b],Euler[a-1]);
        printf("%I64d\n", Euler[b] - Euler[a - 1]);
    }
    return 0;
}