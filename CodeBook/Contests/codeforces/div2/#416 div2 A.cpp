#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b;
    while (scanf("%d %d", &a, &b) != EOF)
    {
        int cnt = 1;
        int turn = 0;
        while (a >= 0 && b >= 0)
        {
            if (turn)
                a -= cnt;
            else
                b -= cnt;
            turn ^= 1;
            cnt++;
        }
        if (a >= 0)
            printf("Vladik\n");
        else
            printf("Valera\n");
    }
    return 0;
}
