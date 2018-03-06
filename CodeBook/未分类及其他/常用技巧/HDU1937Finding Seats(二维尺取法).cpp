#include<bits/stdc++.h>
//题意给出平面图R*C 选择一个面积最小的子矩阵使得内部点的个数大于等于k个
//考虑打前缀和sum[i][j] 表示从(1,1) 到(i,j)的矩形有多少点
//化为经典的尺取法模型,找到一个满足的后根据图形不断更新最小值,递进枚举的起点O(n)大法好
//本题复杂度O(n^3) 10^6可过
const int maxn = 333;
#define  map MAP
int map[maxn][maxn],sum[maxn][maxn];
char str[maxn];
using namespace std;
const int inf = 0x3f3f3f3f;
int main()
{
    int k,r,c;
    while(scanf("%d%d%d",&r,&c,&k)!=EOF&& r+c+k)
    {
        memset(sum,0, sizeof(sum));
        for(int i=1;i<=r;i++)
        {
            scanf("%s",str+1);
            for(int j=1;j<=c;j++)
            {
                if(str[j]=='.')map[i][j] = 1;
                else map[i][j] = 0;
                sum[i][j] += sum[i][j-1] + map[i][j];//先加上本行的前缀和
            }
        }
        for(int i=2;i<=r;i++)
            for(int j=1;j<=c;j++)
                sum[i][j] += sum[i-1][j];//再加上正上方点的前缀和

        int ans = inf;
        for(int i=1;i<=c;i++)
            for(int j=i;j<=c;j++)//枚举到第i列到第j列之间
            {
                int p = 1;//列开始游标
                for(int t = p;t<=r;t++)//行枚举
                {
                    while(sum[t][j]-sum[t][i-1]-sum[p-1][j]+sum[p-1][i-1]>=k)//如果改点的前缀和-行前点的前缀和-
                        ans = min(ans,(j-i+1)*(t-p+1)), p++;//列*行
                }
            }
        printf("%d\n",ans);
    }
    return 0;
}
