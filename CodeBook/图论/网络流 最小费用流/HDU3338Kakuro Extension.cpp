int ss,tt,n,m;
struct cell         //方块
{
     int clour;
     int x,y;
}ces[102][102];
void read_build()
{
    string ts;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            cin>>ts;
            if(ts=="XXXXXXX")      //黑色
              {
                  ces[i][j].clour=0;
                  ces[i][j].x=ces[i][j].y=-1;
              }
            else if(ts==".......")   //白色
            {
                 ces[i][j].clour=5;
                 ces[i][j].x=ces[i][j].y=0;
            }
            else if(ts[0]=='X'&&ts[4]!='X')    //横向要填
            {
                 ces[i][j].clour=2;
                 ces[i][j].x=((ts[4]-'0')*10+(ts[5]-'0'))*10+(ts[6]-'0');
                 ces[i][j].y=-1;
            }
             else if(ts[0]!='X'&&ts[4]=='X')   //纵向要填
            {
                 ces[i][j].clour=3;
                 ces[i][j].y=((ts[0]-'0')*10+(ts[1]-'0'))*10+(ts[2]-'0');
                 ces[i][j].x=-1;
            }
            else                          //都要
            {
                 ces[i][j].clour=4;
                 ces[i][j].y=((ts[0]-'0')*10+(ts[1]-'0'))*10+(ts[2]-'0');
                 ces[i][j].x=((ts[4]-'0')*10+(ts[5]-'0'))*10+(ts[6]-'0');
            }
        }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            int counts=0;
            if(ces[i][j].clour==2) //横向的
            {
                for(int k=j+1;k<m;k++)
                {
                    if(ces[i][k].clour!=5)break;
                    adde(i*m+j,i*m+k,8);
                    counts++;
                }
                adde(ss,i*m+j,ces[i][j].x-counts);
            }
            else if(ces[i][j].clour==3)   //纵向的
            {
                for(int k=i+1;k<n;k++)
                {
                    if(ces[k][j].clour!=5)break;
                    adde(k*m+j,i*m+j,8);
                    counts++;
                }
                adde(i*m+j,tt,ces[i][j].y-counts);
            }

            else if(ces[i][j].clour==4)    //都要填的，一个格子要2个编号，注意。
            {
                for(int k=j+1;k<m;k++)
                {
                    if(ces[i][k].clour!=5)break;
                    adde(i*m+j,i*m+k,8);
                    counts++;
                }
                adde(ss,i*m+j,ces[i][j].x-counts);
                counts=0;
                for(int k=i+1;k<n;k++)
                {
                    if(ces[k][j].clour!=5)break;
                    adde(k*m+j,i*m+j+n*m+2,8);
                    counts++;
                }
                adde(i*m+j+n*m+2,tt,ces[i][j].y-counts);
            }
        }
}
void out()
{
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
      {
          if(ces[i][j].clour!=5) printf("_");
          else
          {
              int sflow=0;
              for(int k=head[i*m+j];k!=-1;k=edge[k][1])      //统计的时候只要正向边（这里注意！），其实每个点也就一条出的正向边
              {
                  if(k%2==0)
                   sflow+=8-e[k][2];
              }
              printf("%d",sflow+1);
          }
          if(j==m-1)printf("\n");
          else printf(" ");
      }
}




#include<bits/stdc++.h>
const int maxn = 100+7;
const int inf = 0x3fffffff;
#define Debug(x) cout<<#x<<"="<<x;
using namespace std;
template <class T>
struct Dinic
{
    struct point
    {
        int from,to;
        T cap,flow;
        point(int from,int to,T cap,T flow):
                from(from),to(to),cap(cap),flow(flow){}
    };
    vector<point>edges;
    vector<int>G[maxn];
    int mark[maxn],cur[maxn];
    T d[maxn];
    int start,ending;
    void addedge(int from,int to,T cap)
    {
        edges.push_back(point(from,to,cap,0));
        edges.push_back(point(to,from, 0, 0));
        int m=edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }
    int bfs(int start,int ending)
    {
        memset(mark,0,sizeof(mark));
        memset(d,-1,sizeof d);
        queue<int> q;
        q.push(start);
        d[start]=0;
        mark[start]=1;
        while(!q.empty())
        {
            int u=q.front();q.pop();
            for(int i=0;i<G[u].size();i++)
            {
                point e=edges[G[u][i]];//
                if(!mark[e.to]&&e.cap>e.flow)
                {
                    mark[e.to]=1;
                    d[e.to]=d[u]+1;
                    q.push(e.to);
                }
            }
        }
        return mark[ending];
    }
    T dfs(int x,T a)
    {
        if(x==ending||a==0) return a;
        T flow=0,f;
        for(int &i=cur[x];i<G[x].size();i++)
        {
            point &e=edges[G[x][i]];
            if(d[x]+1==d[e.to]&&(f=dfs(e.to,min(a,e.cap-e.flow)))>0)
            {
                e.flow+=f;
                edges[G[x][i]^1].flow-=f;
                flow+=f;a-=f;
                if(a==0) break;
            }
        }
        return flow;
    }
    T dinic(int start, int ending)
    {
        this->start = start;
        this->ending = ending;
        T flow=0;
        while(bfs(this->start,this->ending))
        {
            memset(cur,0,sizeof cur);
            flow+=dfs(start,inf);
        }
        return flow;
    }
    void init()
    {
        for(int i=0;i<maxn;i++) G[i].clear();
        edges.clear();
        memset(mark,0,sizeof mark);
        memset(d,0,sizeof d);
    }
};

struct node
{
    int color;
    int x,y;
}mm[maxn][maxn];

inline int turn(char a,char b,char c)
{
    return (a-'0')*100+(b-'0')*10+(c-'0');
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        Dinic<int> __dinic;
        __dinic.init();

        int S=n*m,T=n*m+1;
        string input;//1 XXX X XXX 7

        for(int i=0;i<n;i++)//read
            for(int j=0;j<m;j++)
            {
                scanf("%s",input.c_str());
                if(input=="XXXXXXX")//黑色
                {
                    mm[i][j].color=0;
                    mm[i][j].x=mm[i][j].y=-1;
                }
                else if(input==".......")//白色 B
                {
                    mm[i][j].color=5;
                    mm[i][j].x=mm[i][j].y=0;
                }
                else if(input[4]!='X')//有和
                {
                    if(input[1]!='X'&&input[5]=='X')//仅有纵和 C
                    {
                        mm[i][j].color=3;
                        mm[i][j].x=-1;
                        mm[i][j].y=turn(input[1],input[2],input[3]);
                    }
                    else if(input[1]=='X'&&input[5]!='X')//仅有横和 A
                    {
                        mm[i][j].color=2;
                        mm[i][j].x=turn(input[5],input[6],input[7]);
                        mm[i][j].y=-1;
                    }
                    else//都要 AC
                    {
                        mm[i][j].color=4;
                        mm[i][j].x=turn(input[5],input[6],input[7]);
                        mm[i][j].y=turn(input[1],input[2],input[3]);
                    }
                }
            }

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                int cnt=0;
                if(mm[i][j].color==2)//仅有横向的
                {
                    for(int k=j+1;k<m;k++)//扫描向右的blank
                    {
                        if(mm[i][k].color!=5) break;
                        __dinic.addedge(i*m+j,i*m+k,8);//连<A B> 8
                        cnt++;
                    }
                    __dinic.addedge(S,i*m+j,mm[i][j].x-cnt);//<S,A>
                }
                else if(mm[i][j].color==3) //仅有纵向的
                {
                    for(int k=i+1;k<n;k++)
                    {
                        if(mm[k][j].color!=5) break;
                        __dinic.addedge(k*m+j,i*m+j,8);//<B C>8
                        cnt++;
                    }
                    __dinic.addedge(i*m+j,T,mm[i][j].y-cnt);
                }
                else if(mm[i][j].color==4)//都要填的,注意使用两个index
                {
                    for(int k=j+1;k<m;k++)//先看横向的
                    {
                        if(mm[i][k].color!=5) break;
                        __dinic.addedge(i*m+j,i*m+k,8);//连<A B> 8
                        cnt++;
                    }
                    __dinic.addedge(S,i*m+j,mm[i][j].x-cnt);//<S,A>

                    cnt=0;
                    for(int k=i+1;k<n;k++)//再看纵向的
                    {
                        if(mm[k][j].color!=5) break;
                        __dinic.addedge(k*m+j,i*m+n*m+2,8);//<B C>8
                        cnt++;
                    }
                    __dinic.addedge(i*m+j+n*m+2,T,mm[i][j].y-cnt);
                }
            }

        int ans=__dinic.dinic(S,T);

        for(int i=0;i<n;i++)//out
            for(int j=0;j<m;j++)
            {
                if(mm[i][j].color!=5) printf("_");
                else
                {
                    int flow=0;
                    for(int k=i*m+j;k<__dinic.G[k].size();k++)
                    {
                        if(k%2==0)
                            flow=8-
                    }
                }
            }




    }
    return 0;
}