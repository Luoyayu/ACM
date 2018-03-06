#include<stdio.h>  
#include<cstring>
#define M 2002  
int bin[M], MARK[M], LOVE[M];
int find(int x)
{
    if (bin[x] != x)
    return find(bin[x]);
}
void merge(int x, int y)
{
    x = find(x);
    y = find(y);
    if (MARK[x]>MARK[y])
        bin[y] = x;
    else
    {
        if (MARK[x] == MARK[y])
            MARK[y]++;
        bin[x] = y;
    }
}
int main()
{
    int flag, T, k, i, n, x, y, m;
    scanf("%d", &T);
    for (k = 1; k <= T; k++)
    {
        flag = 0;
        scanf("%d%d", &n, &m);
        memset(LOVE,0,sizeof (LOVE));
        memset(MARK,0,sizeof (MARK));
         for (int i = 1; i <= n; i++)
            bin[i] = i;

        while (m--)
        {
            scanf("%d%d", &x, &y);
            if (flag) continue;
            if (find(x) == find(y))  flag = 1;
            else
            {
                if (LOVE[x] != 0)
                    merge(LOVE[x], y);
                    else LOVE[x] = y;
                if (LOVE[y] != 0)
                    merge(LOVE[y], x);
                else
                    LOVE[y] = x;
            }
        }
        printf("Scenario #%d:\n", k);
        if (flag)
            printf("Suspicious bugs found!\n\n");//sex
        else printf("No suspicious bugs found!\n\n");
    }
    return 0;
}