#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
#include <algorithm>
#include<string>
using namespace std;
const int N = 10005;
const int inf = -50000;
int cnt,n,a[N][N],d[N],v[N];
int spfa(int s,int t)
{
    if(s==t)    return 0;
    for(int i=1;i<=cnt;i++)
        d[i]=inf,v[i]=0;
    queue<int> q;
    d[s]=0,v[s]=1;
    q.push(s);
    while(!q.empty())
    {
        int c=q.front();
        q.pop();
        v[c]=0;
        for(int i=1;i<=cnt;i++)
        {
            if(d[i]>d[c]+a[c][i])
            {
                d[i]=d[c]+a[c][i];
                if(!v[i])
                    v[i]=1,q.push(i);
            }
        }
    }
    if(d[t]>=inf)   return -1;
    return d[t];
}
int main()
{
    while(scanf("%d",&n)!=EOF&&n!=-1)
    {
        int cnt=0;
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                a[i][j]=inf;
        map<string,int> MAP;
        MAP.clear();
        char s[35],e[35];
        scanf("%s %s",s,e);
        MAP[s]= ++cnt,MAP[e]= ++cnt;
        for(int i=1;i<=n;i++)
        {
            char aa[30],bb[30];
            int c;
            scanf("%s %s %d", aa,bb,&c);
            MAP[aa]=++cnt,MAP[bb]=++cnt;
            a[MAP[aa]][MAP[bb]]=min(c,a[MAP[aa]][MAP[bb]]);
        }
        printf("%d\n", spfa(MAP[s],MAP[e]));
    }
    return 0;
}

