#include<bits/stdc++.h>
using namespace std;
const int P = 100+10;
bool flag[P][P];
char mp[P][P];
int dir[][2]={0,1,1,0,0,-1,-1,0};
int n,m;
int check(int x,int y)
{
    if(x<0||y<0) return -1;
    if(x>=n||y>=m) return -1;
    if(mp[x][y]=='0') return 0;
    return 1;
}

void dfs1(int x,int y)
{
    int _x,_y;
    flag[x][y]=1;
    for(int i=0;i<4;i++)
    {
        _x=x+dir[i][0];
        _y=y+dir[i][1];
        if(check(_x,_y)==1&&flag[_x][_y]==0) dfs1(_x,_y);
    }
}

int dfs2(int x,int y)
{
    int _x,_y;
    flag[x][y]=1;
    int ret=1;
    for(int i=0;i<4;i++)
    {
        _x=x+dir[i][0];
        _y=y+dir[i][1];
        if(check(_x,_y)==0&&!flag[_x][_y])
            if(dfs2(_x,_y)==0)ret=0;
        if(check(_x,_y)==-1) ret=0;
    }
    return ret;
}

int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=0;i<n;i++) scanf("%s",mp[i]);
        memset(flag,0,sizeof(flag));

        int t1=0,t2=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(!flag[i][j])
                {
                    if(mp[i][j]=='1')
                    {
                        t1++;
                        dfs1(i,j);
                    }
                    else
                    {
                        if(dfs2(i,j)) t2++;
                    }
                }

        if(t1==1)
        {
            if(t2==1)printf("0\n");
            else if(t2==0)printf("1\n");
            else printf("-1\n");
        }
        else printf("-1\n");
    }
    return 0;
}
