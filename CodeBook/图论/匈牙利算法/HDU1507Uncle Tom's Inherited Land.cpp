//匈牙利
//增广路径算法：从未匹配的点出发，交替通过未匹配边和已匹配边，最后到达另一个未匹配点的路径
//复杂度O(v*e)
//黑白棋的最大匹配，奇偶集合，找出i+j为奇数的且能买的点作为左集合，相邻的能买的点作为右集合
#include<bits/stdc++.h>
using namespace std;
const int maxn=550;
int g[maxn][maxn];
int ori[maxn][maxn];
bool used[maxn];
int uN,vN;
int linker[maxn];
bool dfs(int u)
{
    for(int v=0;v<vN;v++)
    {
        if(g[u][v]&&!used[v])
        {
            used[v]=1;
            if(linker[v]==-1||dfs(linker[v]))
            {
                linker[v]=u;
                return true;
            }
        }
    }
    return false;
}
int hungary()
{
    int res=0;
    memset(linker,-1,sizeof linker);
    for(int u=0;u<uN;u++)
    {
        memset(used,0,sizeof used);
        res+=dfs(u);
    }
    return res;
}
int b[maxn];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0&&m==0)break;
        memset(ori,0,sizeof ori);

        int p;scanf("%d",&p);
        while(p--)
        {
            int px,py;
            scanf("%d%d",&px,&py);
            px--,py--;
            ori[px][py]=-1;
        }

        int index=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(ori[i][j]!=-1)
                {
                    b[index]=i*m+j;//记录可拍卖点在原图的位置
                    ori[i][j]=index++;//记录原图中可行点的序号便于建图
                }
        uN=vN=index;
        memset(g,0,sizeof g);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(ori[i][j]!=-1&&(i+j)%2==1)//奇数
                {
                    int u=ori[i][j];
                    if(i>0&&ori[i-1][j]!=-1)//左边可行
                        g[u][ori[i-1][j]]=1;
                    if(i<n-1&&ori[i+1][j]!=-1)
                        g[u][ori[i+1][j]]=1;
                    if(j>0&&ori[i][j-1]!=-1)
                        g[u][ori[i][j-1]]=1;
                    if(j<m-1&&ori[i][j+1]!=-1)
                        g[u][ori[i][j+1]]=1;
                }

        int ans=hungary();
        printf("%d\n",ans);

        for(int i=0;i<index;i++)
            if(linker[i]!=-1)
            {
                int x1=b[i]/m;
                int y1=b[i]%m;
                int x2=b[linker[i]]/m;
                int y2=b[linker[i]]%m;
                printf("(%d,%d)--(%d,%d)\n",++x1,++y1,++x2,++y2);
            }
        printf("\n");
    }
    return 0;
}
