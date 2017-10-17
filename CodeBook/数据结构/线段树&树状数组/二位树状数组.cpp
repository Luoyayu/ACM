//需求 对例如矩阵内数字的更新，和子矩阵和的查询
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1010;
int C[maxn][maxn];
int n;
int lowbit(int x)
{
    return x&(-x);
}
void add(int x,int y,int v)
{
    for(int i=x;i<=n;i+=lowbit(i))
        for(int j=y;j<=n;j+=lowbit(j))
            C[i][j]+=v;
}
int sum(int x,int y)
{
    int ret=0;
    for(int i=x;i>0;i-=lowbit(i))
        for(int j=y;j>0;j-=lowbit(j))
            ret+=C[i][j];
    return ret;
}
int main()
{
    int T,kase;
    scanf("%d",&kase);
    while(kase--)
    {
        scanf("%d%d",&n,&T);
        memset(C,0,sizeof C);
        char tmp[5];
        while(T--)
        {
            scanf("%s",tmp);
            if(tmp[0]=='C')
            {
                int x1,x2,y1,y2;
                scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
                add(x2+1,y2+1,1);  add(x2+1,y1,1);
                add(x1,y2+1,1);  add(x1,y1,1);
            }
            else
            {
                int tmp2,tmp1;
                scanf("%d %d",&tmp1,&tmp2);
                printf("%d\n",sum(tmp1,tmp2)%2);
            }
        }
        if(kase!=0) printf("\n");
    }
    return 0;
}
