
//题意：给出格点,求出这些格点可以构成的正多边形
//分析显然只能构成正方形，观察N只有500
//暴力枚举两点判断另外两点是否是已有的
//复杂度 n*n*logn = 500*500*9 =2.25e6
#include<bits/stdc++.h>
using namespace std;
const int maxn = 666+7;
int g[maxn][maxn];
struct node
{
    int x,y;
}p[maxn];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(g, 0, sizeof(g));
        for(int i=0;i<n;i++)
        {
            int x,y;scanf("%d %d",&x,&y);
            x+=300, y+=300;
            p[i].x=x,p[i].y=y;
            g[p[i].x][p[i].y]=1;
        }
        int cnt = 0;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
            {
                int dx=p[i].x-p[j].x;
                int dy=p[i].y-p[j].y;
                if(g[p[i].x+dy][p[i].y-dx] && g[p[j].x+dy][p[j].y-dx]) cnt++;
                if(g[p[i].x-dy][p[i].y+dx] && g[p[j].x-dy][p[j].y+dx]) cnt++;
            }
        printf("%d\n",cnt/4);
    }
    return 0;
}