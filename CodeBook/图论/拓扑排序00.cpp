// 拓扑排序(Topological Sorting)是一个DAG图的所有定顶点的线性序列，
// x->y
//全序
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=500+5;
int a[maxn][maxn];
int degree[maxn];
int output[maxn];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(a,0,sizeof a);
        memset(degree,0,sizeof degree);
        memset(output,0,sizeof output);
        for(int i=0;i<m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            if(a[x][y]==0)//去重边
                a[x][y]++,//表示x,y有全序关系
                degree[y]++;//x赢y,即y的入度++
        }
        int cnt=0;
        while(1)    //可用队列优化
        {
            int j=1;//每次从一号点找起
            if(degree[j]!=0)//如果j的入度!=0
                while(1)
                {
                    j++;
                    if(degree[j]==0) break;//找到入度为0的点，表示从未被打败
                    if(j>n) break;
                }
            degree[j]=-1;//标记下，划去该点
            if(cnt==n) break; 
            output[cnt++]=j; //表示进入答案序列
            for(int i=1;i<=n;i++)
                if(a[j][i]>0)//找到和入度为0的相关的边
                {
                    degree[i]--;//减少度
                    a[j][i]=-1;//去掉该边
                }
        }
        for(int i=0;i<cnt-1;i++)
                printf("%d ",output[i]);      
        printf("%d\n",output[n-1]);
    }
    return 0;
}


