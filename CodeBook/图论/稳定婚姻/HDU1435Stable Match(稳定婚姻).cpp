#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<iostream>
#include<queue>
using namespace std;
const int maxn=255;
int engage[maxn],n;
int boy[maxn][maxn],girl[maxn][maxn];
struct dis
{
    double  s,c;
    int id;
};
struct type
{
    double c;
    double x,y,z;
    dis D[maxn];
}O[maxn],I[maxn];
void cal_dis(int x)
{
    for(int i=1;i<=n;i++)
    {
        double d=0;
        d += sqrt(    (O[x].x-I[i].x) * (O[x].x-I[i].x) + (O[x].y-I[i].y) * (O[x].y-I[i].y) + (O[x].z-I[i].z) * (O[x].z-I[i].z));
        O[x].D[i].s=d;
        O[x].D[i].id=i;
        O[x].D[i].c=I[i].c;
        I[i].D[x].s=d;
        I[i].D[x].id=x;
        I[i].D[x].c=O[x].c;
    }
}
bool cmp(dis a,dis b)
{
    if(a.s==b.s)
        return a.c > b.c;
    return a.s < b.s;
}
void gale_shapley()
{
    queue<int> q;
    int boyid,girlid;
    for(int i=1;i<=n;i++)
    {
        engage[i]=0;
        boy[i][0]=1;
        q.push(i);
    }
    while(!q.empty())
    {
        boyid = q.front();
        girlid=boy[boyid][boy[boyid][0]++];
        if(!engage[girlid])
        {
            engage[girlid]=boyid;
            q.pop();
        }
        else
        {
            int i;
            for(i=1;i<=n;i++)
                if(girl[girlid][i]==boyid || girl[girlid][i]==engage[girlid])
                    break;
            if(girl[girlid][i]==boyid)
            {
                q.push(engage[girlid]);
                engage[girlid]=boyid;
                q.pop();
            }
        }
    }
}
int main()
{
    int T;scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            int id;
            scanf("%d",&id);
            scanf("%lf%lf%lf%lf",&O[id].c,&O[id].x,&O[id].y,&O[id].z);
        }
        for(int i=1;i<=n;i++)
        {
            int id;
            scanf("%d",&id);
            scanf("%lf%lf%lf%lf",&I[id].c,&I[id].x,&I[id].y,&I[id].z);
        }

        for(int i=1;i<=n;i++)
            cal_dis(i);
        for(int i=1;i<=n;i++)
        {
            sort(O[i].D+1,O[i].D+n+1,cmp);
            for(int j=1;j<=n;j++)
                boy[i][j]=O[i].D[j].id;
        }
        for(int i=1;i<=n;i++)
        {
            sort(I[i].D+1,I[i].D+n+1,cmp);
            for(int j=1;j<=n;j++)
                girl[i][j]=I[i].D[j].id;
        }
        gale_shapley();
        int X[maxn],Y[maxn];
        for(int i=1;i<=n;i++)
        {
            X[i]=i;
            Y[i]=engage[i];
        }
        for(int i=1;i<=n;i++)
            printf("%d %d\n",Y[i],X[i]);
        //printf("\n");
    }
    return 0;
}
