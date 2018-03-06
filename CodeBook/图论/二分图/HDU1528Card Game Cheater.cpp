#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=50;
int uN,vN;
int g[maxn][maxn];
int used[maxn];
char a[30][3],b[30][3];
int linker[maxn];
using namespace std;
int dfs(int u)
{
    for(int v=1;v<=vN;v++)
    {
        if(g[u][v]&&!used[v])
        {
            used[v]=true;
             if(linker[v]==-1||dfs(linker[v]))
             {
                linker[v]=u;
                 return 1;
            }
        }
    }
return 0;
}
int match()
{
     int ans=0;
     for(int i=1;i<=uN;i++)
        memset(used,0,sizeof used), ans+=dfs(i);
 return ans;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        string a[n+1],b[n+1];
        memset(linker,-1,sizeof linker);
        memset(g,0,sizeof g);
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(a[i][0]=='T')
                a[i][0]=11+'0';
            else if(a[i][0]=='J')
                a[i][0]=12+'0';
            else if(a[i][0]=='Q')
                a[i][0]=13+'0';
            else if(a[i][0]=='K')
                a[i][0]=14+'0';
            else if(a[i][0]=='A')
                a[i][0]=15+'0';
            if(a[i][1]=='H')
                a[i][1]='Z';
        }
        for(int i=1;i<=n;i++)
        {
           cin>>b[i];
            if(b[i][0]=='T')
                b[i][0]=11+'0';
            else if(b[i][0]=='J')
                b[i][0]=12+'0';
            else if(b[i][0]=='Q')
                b[i][0]=13+'0';
            else if(b[i][0]=='K')
                b[i][0]=14+'0';
            else if(b[i][0]=='A')
                b[i][0]=15+'0';
            if(b[i][1]=='H')
                b[i][1]='Z';
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(b[i][0]>a[j][0]||(b[i][0]==a[j][0]&&b[i][1]>a[j][1]))
                    g[i][j]=1;
        uN=vN=n;
        printf("%d\n",match());
    }
    return 0;
}
