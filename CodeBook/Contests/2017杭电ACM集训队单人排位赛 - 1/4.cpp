#include<bits/stdc++.h>
using namespace std;
const int maxr=100+5;
const int maxc=100+5;
const int maxn=10000+100;
int A,B,C;
int vis[maxr][maxc],dist[maxr][maxc],pre[maxr][maxc];
struct Cell
{
    int a,b;
    Cell(int a,int b):a(a),b(b){}
};

int cnt;
struct Node
{
    int a,b,t;
    Node(){}
    Node(int a,int b,int t):a(a),b(b),t(t){}
}nodes[maxn];

Cell BFS()
{
    queue<Cell> Q;
    Q.push(Cell(0,0));
    memset(vis,0,sizeof(vis));
    vis[0][0]=1;
    dist[0][0]=0;
    cnt=0;
    while(!Q.empty())
    {
        Cell cell=Q.front();Q.pop();
        int a=cell.a,b=cell.b;
        for(int d=0;d<6;d++)
        {
            int na,nb;
            if(d==0) na=A,nb=b;
            else if(d==1) na=a,nb=B;
            else if(d==2) na=0,nb=b;
            else if(d==3) na=a,nb=0;
            else if(d==4)
            {
                int all=a+b;
                na= all>=B?all-B:0;
                nb= all>=B? B:all;
            }
            else if(d==5)
            {
                int all=a+b;
                na= all>=A? A:all;
                nb= all>=A? all-A:0;
            }
            if(vis[na][nb]==0)
            {
                vis[na][nb]=1;
                dist[na][nb]=dist[a][b]+1;
                nodes[cnt++]=Node(a,b,d);
                pre[na][nb]=cnt-1;
                Q.push(Cell(na,nb));
                if(nb==C) return Cell(na,nb);
            }
        }
    }
    return Cell(-1,-1);
}
int main()
{
    while(scanf("%d%d%d",&A,&B,&C)!=EOF)
    {
        if(A>B) swap(A,B);
        Cell cell=BFS();
        stack<int> S;
        int a=cell.a, b=cell.b;
        while(true)
        {
            int tmp=pre[a][b];
            S.push(nodes[tmp].t);
            a=nodes[tmp].a,b=nodes[tmp].b;
            if(a==0&&b==0) break;
        }
        if(S.size()==1 && A!=C && B!=C)
            printf("impossible\n");
        else
            printf("%d\n",S.size());
    }
    return 0;
}
