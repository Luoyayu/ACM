#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int  M =105;
const int inf= 0x3fffffff;
bool sx[M], sy[M];
int match[M], g[M][M];
int n, m;
int lx[M], ly[M];
void init ()
{
    //memset (g, 0, sizeof(g));
       for(int i=1;i<=n;i++)
           for(int j=1;j<=m;j++)
               g[i][j]=-inf;
}
bool dfs (int u)
{
    sx[u] = true;
    for (int v = 1; v <= m; v++)
        if (!sy[v] && lx[u]+ly[v]==g[u][v])
        {
            sy[v] = true;
            if (match[v] == -1 || dfs (match[v]))
            {
                match[v] = u;
                return true;
            }
        }
    return false;
}

int KM ()
{
    memset (ly, 0, sizeof(ly));
    for (int i = 1; i <= n; i++)
    {
        lx[i] = -inf;
        for (int j = 1; j <= m; j++)
            lx[i] = max(g[i][j],lx[i]);
    }
    memset (match, -1, sizeof(match));
    for (int i = 1; i <= n; i++)
    {
        while (1)
        {
            memset (sx, false, sizeof(sx));
            memset (sy, false, sizeof(sy));
            if (dfs(i))
                break;
            int d = inf;
            for (int j = 1; j <= n; j++)
                if (sx[j])
                    for (int k = 1; k <= m; k++)
                        if (!sy[k])
                            d = min (d, lx[j]+ly[k]-g[j][k]);                
            //if (d == inf) return -1;
            for (int j = 1; j <= n; j++)
                if (sx[j]) lx[j] -= d;
            for (int j = 1; j <= m; j++)
                if (sy[j]) ly[j] += d;
        }
    }
    int  sum = 0;
    for (int i = 1; i <= m; i++)
        if (match[i] != -1)
            sum += g[match[i]][i];
    return sum;
}
int main()
{
    int nn,mm;
    char map[105][105];
    memset(map,0,sizeof map);
    while(scanf("%d %d",&nn,&mm)!=EOF)
    {
        if(nn==0&&mm==0) break;
        init();
        for(int i=1;i<=nn;i++)
        {
            getchar();
            for(int j=1;j<=mm;j++)
            scanf("%c",&map[i][j]);

            }
        int numm=0,numH=1;
        for(int i=1;i<=nn;i++)
            for(int j=1;j<=mm;j++)
                if(map[i][j]=='m')
                {
                    numm++;numH=1;
                    for(int k=1;k<=nn;k++)
                        for(int q=1;q<=mm;q++)
                            if(map[k][q]=='H')
                            {
                                g[numm][numH] = -(abs(i-k)+abs(j-q));
                                numH++;
                            }
                }    
        n=m=numm;    
        //printf("%d\n",n);
        
        printf("%d\n",-KM());
    }    
    return 0;
}

2 2
.m
H.
5 5
HH..m
.....
.....
.....
mm..H
7 8
...H....
...H....
...H....
mmmHmmmm
...H....
...H....
...H....
0 0
