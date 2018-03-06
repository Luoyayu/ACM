//STL Stack
#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
const int maxn=1000+50;
const int maxm=2000+80;
const int INF=0x3f3f3f3f;
struct Edge
{
    int to,next;
} edge[maxm];

int head[maxn],Belong[maxn],Low[maxn],DFN[maxn],sc[maxn],deg[maxn];
bool instack[maxn];
int tot,cnt,scnt,va[maxn];
stack<int> S;
void init()
{
    tot=cnt=scnt=0;
    memset(head,-1,sizeof(head));
    memset(DFN,0,sizeof(DFN));
    memset(deg,0,sizeof(deg));
    memset(Low,0,sizeof(Low));
    memset(instack,0,sizeof(instack));
}
void addedge(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}
void Tajan(int i)
{
    S.push(i);
    instack[i]=1;
    DFN[i]=Low[i]=++cnt;
    for(int e=head[i]; e+1; e=edge[e].next)
    {
        int v=edge[e].to;
        if(!DFN[v])
        {
            Tajan(v);
            if(Low[v]<Low[i])
                Low[i]=Low[v];
        }
        else if(instack[v]&&DFN[v]<Low[i])
            Low[i]=DFN[v];
    }
    if(Low[i]==DFN[i])
    {
        scnt++;
        int t;
        do
        {
            t=S.top();
            S.pop();
            instack[t]=0;
            Belong[t]=scnt;//scnt是缩点之后的点
        }while(t!=i);
    }
}
int main()
{
    int a,b,n,pairs;
    while(scanf("%d %d",&n,&pairs)!=EOF)
    {
        init();
        for(int i=1; i<=n; i++)
            scanf("%d",&va[i]);

        while(pairs--)
            scanf("%d%d",&a,&b),addedge(a,b);

        for(int i=1; i<=n; i++)
            if(!DFN[i])
                Tajan(i);

        int ans=0,cont=0;
        for(int i=1; i<=n; i++)
            for(int e=head[i]; e+1; e=edge[e].next)
            {
                int Next=edge[e].to;
                if(Belong[i]!=Belong[Next])
                    deg[Belong[Next]]++; //缩点的度++
            }

        for(int i=1; i<=scnt; i++) //scnt 缩点的个数
            if(!deg[i])//缩点是独立点
            {
                cont++;  //点数+1
                int MIN=INF;
                for(int j=1; j<=n; j++)
                    if(Belong[j]==i)//在属于这个独立”点“的点里面找花费最小的
                        MIN=min(va[j],MIN);
                ans+=MIN;
            }
        printf("%d %d\n",scnt,cont,ans);
    }
}
