#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 20000 + 5;
int dra[N], war[N];
int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) == 2 && n && m)
    {
        for (int i = 0; i < n; i++)
            scanf("%d", &dra[i]);
        for (int i = 0; i < m; i++)
            scanf("%d", &war[i]);
        sort(dra, dra + n);
        sort(war, war + m);
        int cur = 0;
        int cost = 0;
        for (int i = 0; i < m; i++)
            if (war[i] >= dra[cur])
            {
                cost += war[i];
                if (++cur == n)
                    break;
            }
        if (m < n)
            printf("Loowater is doomed!\n");
        else
            printf("%d\n", cost);
    }
    return 0;
}
