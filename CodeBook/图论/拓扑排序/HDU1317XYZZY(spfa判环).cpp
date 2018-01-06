#include <stdio.h>
#include <queue>
#include <iostream>
using namespace std;
#define MIN -999999999
int map[105][105], d[105], n;
void init()
{ //初始化
    int i, j;
    for (i = 1; i <= n; i++)
    {
        d[i] = MIN;
        for (j = 1; j <= n; j++)
            map[i][j] = MIN;
    }
}
int spfa(int s)
{
    if (n == 1)
        return 1;
    queue<int> q;
    int inq[105] = {0}, vist[105] = {0};
    d[s] = 100; //题目意思是最开始能量是100
    inq[s] = 1;
    q.push(s);
    while (!q.empty())
    {
        s = q.front();
        q.pop();
        vist[s]++; //点s进队vist[s]次
        if (vist[s] == n + 2)
            continue; //如果进队大于n+1次了，说明与s点有关的点都得到了正环的利益
        inq[s] = 0;
        if (vist[s] == n + 1)
            d[s] = 100000; //说明s是在正环上，那么d[s]可以变成很大的数，根据题目两个点最小距离为-100*100,所以100000足以.

        for (int i = 1; i <= n; i++)
            if (map[s][i] != MIN)
                if (d[i] < d[s] + map[s][i] && d[s] + map[s][i] > 0) //判断大于0，就是能量不能用完才能往下走
                {
                    d[i] = d[s] + map[s][i];
                    if (d[n] > 0)
                        return 1; //走到第n点
                    if (!inq[i])
                        inq[i] = 1, q.push(i);
                }
    }
    return 0;
}
int main()
{
    int p, a, k;
    while (scanf("%d", &n) > 0 && n != -1)
    {
        init();
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d", &p, &k);
            while (k--)
            {
                scanf("%d", &a);
                map[i][a] = p;
            }
        }
        printf("%s\n", spfa(1) ? "winnable" : "hopeless");
    }
}