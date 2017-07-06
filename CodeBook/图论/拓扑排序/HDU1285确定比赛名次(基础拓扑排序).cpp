//优先队列实现
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int maxn=666;
int indeg[maxn];
int s[maxn][maxn];
int n,m;
void toposort()
{
    priority_queue<int ,vector<int>,greater<int> >Q;
    for(int i=1;i<=n;i++)//先筛一遍入度为0的节点入队
        if(indeg[i]==0)
            Q.push(i);
    int flag=0;//输出格式标记
    while(!Q.empty())
    {
        int now=Q.top();Q.pop();//入度为0的节点自小到大请出队
        indeg[now]=-1;//出队元素标记入度为-1，表示已访问过
        if(!flag)
            printf("%d",now);
        else
            printf(" %d",now);

        flag=1;//结束格式标记
        for(int i=1;i<=n;i++)//扫一遍与当前节点有
        {
            if(s[now][i]==1)//和now相连的边
            {
                indeg[i]--;
                if(indeg[i]==0)
                    Q.push(i);
            }
        }
    }
    printf("\n");
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(indeg,0,sizeof indeg);
        memset(s,0,sizeof s);
        for(int i=0;i<m;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            if(s[a][b]==1)//处理重边
                continue;
            s[a][b] = 1;
            indeg[b]++;
        }
        toposort();
    }
    return 0;
}
