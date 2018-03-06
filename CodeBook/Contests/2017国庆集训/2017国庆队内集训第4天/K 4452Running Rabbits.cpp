#include <bits/stdc++.h>
using namespace std;
int n;

int dir[4][2] = {0,-1, 1, 0, 0, 1, -1, 0};
void changed(int &x, int &y, int &dirr, int v)
{
    int lsx = x + v * dir[dirr][0];
    int lsy = y + v * dir[dirr][1];
    if(lsx < 1)
    {
        x = v - (x - 1) + 1;
        dirr = (dirr + 2) % 4;
    }
    else if(lsx > n)
    {
        x = n - (v - (n - x));
        dirr = (dirr + 2) % 4;
    }
    else if(lsy < 1)
    {
        y = v - (y - 1) + 1;
        dirr = (dirr + 2) % 4;
    }
    else if(lsy > n)
    {
        y = n - (v - (n - y));
        dirr = (dirr + 2) % 4;
    }
    else
    {
        x = lsx; y = lsy;
    }
}
int main()
{
    while(scanf("%d", &n), n)
    {
        map<char, int>M;
        M['W'] = 0;
        M['S'] = 1;
        M['E'] = 2;
        M['N'] = 3;
        getchar();
        int t1, s1, t2, s2;
        char ch1, ch2;
        int cch1, cch2;
        scanf("%c%d%d", &ch1, &s1, &t1);
        cch1 = M[ch1];
        getchar();
        scanf("%c%d%d", &ch2, &s2, &t2);
        cch2 = M[ch2];
        int k;
        scanf("%d", &k);
        int g1x, g1y, g2x, g2y;
        g1x = 1, g1y = 1, g2x = n, g2y = n;
        for(int i = 0;i < k;i++)
        {
            if(i % t1 == 0&&i != 0&&(g1x != g2x||g1y != g2y))
                cch1 = (cch1 + 1) % 4;
            if(i % t2 == 0&&i != 0&&(g1x != g2x||g1y != g2y))
                cch2 = (cch2 + 1) % 4;
            if(g1x == g2x&&g1y == g2y)
                swap(cch1, cch2);
            changed(g1x, g1y, cch1, s1);
            changed(g2x, g2y, cch2, s2);

//            printf("%d %d\n", g1x, g1y);
//            printf("%d %d\n", g2x, g2y);
        }
        printf("%d %d\n", g1x, g1y);
        printf("%d %d\n", g2x, g2y);
    }
    return 0;
}
