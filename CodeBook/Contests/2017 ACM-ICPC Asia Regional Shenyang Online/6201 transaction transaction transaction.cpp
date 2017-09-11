#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 100004;
const int INF = 0x3f3f3f3f;
int head[maxn];
int d[maxn];
int visit[maxn];
int n;
struct Edge
{
    int to,w,next;
}E[maxn<<4];
int sizee;
void init()
{
    memset(head,-1,sizeof(head));
    memset(d, INF, sizeof(d));
    memset(visit, 0, sizeof(visit));
    sizee = 0;
}

void addedge(int u,int v,int x)
{
    E[sizee].to = v;
    E[sizee].w = x;
    E[sizee].next = head[u];
    head[u] = sizee++;
}

void SPFA(int s)
{
    queue<int> q;
    visit[s] = 1;
    d[s]=0;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        visit[u] = 0;
        for(int i=head[u]; i!=-1; i=E[i].next)
        {
            if(d[E[i].to] > d[u] + E[i].w)
            {
                d[E[i].to] = d[u]+E[i].w;
                if(!visit[E[i].to]){
                    visit[E[i].to] = 1;
                    q.push(E[i].to);
                }
            }
        }
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        init();
        for(int i = 1;i <= n;i++)
        {
            int ls;
            scanf("%d", &ls);
            addedge(0, i, ls);
            addedge(i, n + 1, -ls);
        }
        for(int i = 1;i <= n - 1;i++)
        {
            int a, b, c;
            scanf("%d%d%d",&a, &b, &c);
            addedge(a, b, c);
            addedge(b, a, c);
        }
        SPFA(0);
        if(d[n + 1] >= 0)
            printf("0\n");
        else
            printf("%d\n", -d[n + 1]);
    }
    return 0;
}