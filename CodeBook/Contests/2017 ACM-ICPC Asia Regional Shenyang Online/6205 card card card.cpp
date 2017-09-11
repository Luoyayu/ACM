//队友
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int stand[2000010];
int value[2000010];
int n;
int main()
{
    while(~scanf("%d", &n))
    {
        for(int i = 1;i <= n;i++)
            scanf("%d", &stand[i]), value[i] = stand[i];
        for(int i = 1;i <= n;i++)
        {
            int ls;scanf("%d", &ls);
            stand[i] -= ls;
        }
        int ans = 0;
        int dq = 0;
        int dqval = 0;
        int cnt = 0;
        int bj = 0;
        int ks = 1;
        for(int i = 1;i <= 2 * n - 1;i++)
        {
            int ls = i % n;
            if(ls == 0)
                ls = n;
            if(dq + stand[ls] < 0)
            {
                dq = 0;
                cnt = 0;
                dqval += value[ls];
                if(dqval > ans)
                {
                    bj = ks;
                    ans = dqval;
                }
                dqval = 0;
                ks = i + 1;
            }
            else
            {
                dq += stand[ls];
                cnt++;
                dqval += value[ls];
                if(dqval > ans)
                {
                    bj = ks;
                    ans = dqval;
                }
                if(cnt == n)
                {
                    cnt = 0;
                    dq = 0;
                    dqval = 0;
                    ks = i + 1;
                }
            }
        }
        printf("%d\n", bj - 1);
    }
    return 0;
}

//尺取法
#include<bits/stdc++.h>
uisng namespace std;
typedef long long ll;
const int maxn = 1e6 + 7;

int main()
{

}

