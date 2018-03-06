//HDU 3357
//DAG图，求造成环的边数
//二维数组模拟关系
//a->b 能到达a,就能到达b,
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int mark[250][250];
int N,T;
void add_edge(int a,int b)
{
    mark[a][b]=1;//a可到b
    //1、所有能够到达a点的节点都能够到达b点
    for(int i=1;i<=N;i++)
    if(mark[i][a])mark[i][b]=1;
    //2、所有b点能够到达的点，a节点都能够到达
    for(int i=1;i<=N;i++)
        if(mark[b][i])
        {
            mark[a][i]=1;
            //所有能够到达b点的节点都能够到达b所能够到达的点
            for(int j=1;j<=N;j++)
            if(mark[j][b])
                mark[j][i]=1;
        }
}

int main()
{
    int a,b,ans,index=0;
    while(scanf("%d%d",&N,&T)!=EOF&&(N||T))
    {
        ans = 0;
        memset(mark,0,sizeof(mark));
        for(int i=0;i<T;i++)
        {
            scanf("%d%d",&a,&b);
            if(mark[b][a]||a==b)ans++;
            else if(mark[a][b]==0)add_edge(a,b);
        }
       // if(ans!=0)
        printf("%d. %d\n",++index,ans);
    }
    return 0;
}
