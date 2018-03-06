#include <bits/stdc++.h>
//题意给出N个灯笼 m个开关,q次对于末状态的询问，问有几种开关灯的方式，每盏灯可能被多个开关控制，同时每个开关可能控制多盏灯
//思路，n个灯笼就对应着n个方程，m个开关对应着m个未知数，方程得系数就是对于第i盏灯，能否被第j个开关控制，能的话系数为1否则为0
//令做一个数组存下初始状态，每次询问时补上最后一列，求出得未知变元得个数ans 即为不清状况的数量那么答案为 2*ans 
using namespace std;
const int maxn=55;
int a[maxn][maxn],b[maxn][maxn];
int x[maxn];
bool free_x[maxn];
int equ, var;
inline int lcm(int a,int b){return a/__gcd(a,b)*b;}

int Gauss()
{
    int k, MaxRow,col = 0, Lcm, ta, tb, temp;
    int FreeXNum, FreeIndex;

    for(int i = 0; i < var; ++i)
    {
        x[i] = 0;
        free_x[i] = true;
    }

    for(k = 0; k < equ && col < var; ++k,++col)
    {
        MaxRow = k;
        for(i = k+1; i < equ; ++i)
        {
            if(abs(a[i][col]) > abs(a[MaxRow][col]))
                MaxRow = i;
        }
        if(MaxRow != k)
        {
            for(int j = k; j < var+1; ++j)
                swap(a[k][j],a[MaxRow][j]);
        }
        if(a[k][col] == 0)
        {
            k--;
            continue;
        }
        for(int i = k+1; i < equ; ++i)
        {
            if(a[i][col])
            {
                Lcm = lcm(abs(a[i][col]),abs(a[k][col]));
                ta = Lcm / abs(a[i][col]);
                tb = Lcm / abs(a[k][col]);
                if(a[i][col] * a[k][col] < 0)
                    tb = -tb;
                for(int j = col; j < var+1; ++j)
                {
                    a[i][j] = (a[i][j]*ta%2 - a[k][j]*tb%2 + 2) % 2;
                }
            }
        }
    }

    for(int i = k; i < equ; ++i)
        if(a[i][col]) return -1;

    if(k < var)
        return var - k;
    return 0;
}
int main(void)
{
    int t;scanf("%d",&t);
    for(int kase = 1;kase <= t; kase ++)
    {
        scanf("%d %d", &equ, &var);
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(x, 0, sizeof(x));
        for(int i=0;i<var;i++)
        {
            int l;scanf("%d",&l);
            while(l--)
            {
                int d;scanf("%d",&d);
                b[d-1][i]=1;
            }
        }
        printf("Case %d:\n",kase);
        int q;scanf("%d",&q);

        while(q--)
        {
            memcpy(a,b,sizeof(b));
            for(int i=0;i<equ;i++) scanf("%d",&a[i][var]);
            int ans = Gauss();
            if(ans <0) printf("0\n");
            else printf("%lld\n",1LL<<(ans));
        }
    }
    return 0;
}