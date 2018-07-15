#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int dp[505][505];
int f[505];
int p[505];
int cnt = 0;
int main()
{
    memset(f, 0, sizeof(f));
    for(int i = 2;i <= 500;i++)
    {
        if(f[i] == 0)
            p[cnt++] = i;
        for(int j = 0;j < cnt;j++)
        {
            if(p[j] * i > 500)
                break;
            f[p[j] * i] = 1;
            if(i % p[j] == 0)
                break;
        }
    }
    memset(dp, 0, sizeof(dp));
    for(int i = 500;i >= 1;i--)
    {
        for(int j = 500;j >= 1;j--)
        {
            for(int k = 0;k < cnt;k++)
            {
                if(i + p[k] > 500 && j + p[k] > 500)
                    break;
                if(i + p[k] <= 500)
                {
                    if(dp[i + p[k]][j] == 0)
                    {
                        dp[i][j] = 1;
                        break;
                    }
                }
                if(j + p[k] <= 500)
                {
                    if(dp[i][j + p[k]] == 0)
                    {
                        dp[i][j] = 1;
                        break;
                    }
                }
                if(i + p[k] <= 500&&j + p[k] <= 500)
                {
                    if(dp[i + p[k]][j + p[k]] == 0)
                    {
                        dp[i][j] = 1;
                        break;
                    }
                }
            }
        }
    }
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        if(dp[500 - n + 1][500 - m +1] == 1)
            printf("Sora\n");
        else
            printf("Shiro\n");
    }
    return 0;
}
