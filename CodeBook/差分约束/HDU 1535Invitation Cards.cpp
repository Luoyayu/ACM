#include<bits/stdc++.h>
#define INF 1000000000
#define maxn 1000000+10
using namespace std;
struct Edge
{
    int to;
    int w;
    int next;
}edge1[maxn],edge2[maxn];
int head1[maxn],dis1[maxn],inque[maxn],tot1;
int head2[maxn],dis2[maxn],tot2;
void ADD(int u,int v,int w)
{
    edge1[++tot1].to=v;
    edge1[tot1].w=w;
    edge1[tot1].next=head1[u];
    head1[u]=tot1;
}
void add(int u,int v,int w)
{
    edge2[++tot2].to=v;
    edge2[tot2].w=w;
    edge2[tot2].next=head2[u];
    head2[u]=tot1;
}
void spfa(int s,int t)
{
    queue<int>Q;
    for(int i=0;i<maxn;i++)
        dis1[i]=INF;
    memset(inque,0,sizeof(inque));
    dis1[s]=0;
    Q.push(s);
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        inque[u]=0;
        for(int i=head1[u];i;i=edge1[i].next)
        {
            int v=edge1[i].to;
            int w=edge1[i].w;
            if(dis1[u]+w<dis1[v])
            {
                dis1[v]=dis1[u]+w;
                if(!inque[v])
                {
                    inque[v]=1;
                    Q.push(v);
                }
            }
        }
    }
}
void SPFA(int s,int t)
{
    for(int i=0;i<maxn;i++)
        dis2[i]=INF;
    memset(inque,0,sizeof(inque));
    dis2[s]=0;
    queue<int>Q;
    Q.push(s);
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        inque[u]=0;
        for(int i=head2[u];i;i=edge2[i].next)
        {
            int v=edge2[i].to;
            int w=edge2[i].w;
            if(dis2[u]+w<dis2[v])
            {
                dis2[v]=dis2[u]+w;
                if(!inque[v])
                {
                    inque[v]=1;
                    Q.push(v);
                }
            }
        }
    }
}
int main()
{
    int T;
    int n,m;
    int a,b,c;
    int sum;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        memset(head1,0,sizeof(head1));
        memset(head2,0,sizeof(head2));
        tot1=1;tot2=1;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            ADD(a,b,c);
            add(b,a,c);
        }
        spfa(1,n);
        SPFA(1,n);
        sum=0;
        for(int i=2;i<=n;i++)
            sum+=dis1[i];
        for(int i=2;i<=n;i++)
            sum+=dis2[i];
        printf("%d\n",sum);
    }
    return 0;
}
