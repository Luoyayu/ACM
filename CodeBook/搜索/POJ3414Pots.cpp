//#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<stack>
using namespace std;
//经典bfs问题好久不写手生了多练
//考虑最少步骤6个入口的bfs,注意记录前驱,用stack还原操作步骤
#define Debug(x) cout<<#x<<"="<<x<<endl;
const int maxc=105;
const int maxn=10000+100;
int A,B,C,cnt;
int vis[maxc][maxc],pre[maxc][maxc];//pre[][]指示node中的节点
//bfs A,B op1:fill(i); op2:drop(i); op3 pour(i,j) pour from i to j
struct Cell
{
    int a,b;
    Cell(){}
    Cell(int a,int b):a(a),b(b){}
};
struct Node//记录到达(i,j)时的状态,前状态node.i,node.j
{
    int a,b,t;//t 记录操作类型
    Node(){}
    Node(int a,int b,int t):a(a),b(b),t(t){}
}node[maxn];
queue<Cell>q;
Cell bfs()
{
    cnt = 0;//记录node节点数(0~cnt-1)
    memset(vis,0,sizeof vis);
    vis[0][0]=1;
    q.push(Cell(0,0));
    while(!q.empty())
    {
        Cell cell = q.front();q.pop();
        int a = cell.a, b= cell.b;//从(a,b)到状态(na,nb)
        for(int i=0;i<6;i++)
        {
            int na,nb;//定义新状态
            if(i==0) na=A,nb=b;//fill(a)
            else if(i==1) na=a,nb=B;//fill(b)
            else if(i==2) na=0,nb=b;//drop(a)
            else if(i==3) na=a,nb=0;//drop(b)
            else if(i==4)//drop(b,a)
            {
                int tot=a+b;
                nb=tot>=B?B:tot;
                na=tot>=B?tot-B:0;
            }
            else if(i==5)//drop(a,b)
            {
                int tot=a+b;
                na=tot>=A?A:tot;
                nb=tot>=A?tot-A:0;
            }

            if(vis[na][nb]==0)//新状态还没有遍历到
            {
                vis[na][nb]=1;
                node[cnt++]=Node(a,b,i); //将该(na,nb)装载进node节点
                pre[na][nb]=cnt-1;//记录前驱结点
                if(na==C||nb==C)//以(na,nb)结束的状态
                    return Cell(na,nb);
                q.push(Cell(na,nb));//新节点入队
            }
        }
    }
    return Cell(-1,-1);
}
int main()
{
    while(scanf("%d%d%d",&A,&B,&C)!=EOF)
    {
        Cell cell = bfs();//拿回状态(na,nb);
        if(cell.a==-1) printf("impossible\n");
        else
        {
            stack<int>S;int a = cell.a, b =cell.b;
            while(a||b)//记录操作步骤
            {
                int PRE=pre[a][b];
                S.push(node[PRE].t);
                a=node[PRE].a, b=node[PRE].b;//回到前驱状态
            }
            printf("%d\n",S.size());
            while(!S.empty())
            {
                int t=S.top();S.pop();
                if(t==0||t==1) printf("FILL(%d)\n",t+1);
                else if(t==2||t==3) printf("DROP(%d)\n",t-1);
                else if(t==4) printf("POUR(1,2)\n");
                else if(t==5) printf("DROP(2,1)\n");
            }
        }
    }
    return 0;
}
