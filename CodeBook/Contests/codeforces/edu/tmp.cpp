
#include<cstdio>
#include<cstring>
int c[100005],n;
int SUM[100005];
void add(int x,int d)
{
    while(x<=n)
        c[x]+=d,x+=(x&-x);
}
int sum(int x)
{
    int ans=0;
    while(x)
        ans+=c[x],x-=(x&-x);
    return ans;
}
int main()
{
    while(scanf("%d",&n)!=EOF,n)
    {
        memset(c,0,sizeof c);
        while(n--)
        {
            int i,j;
            scanf("%d %d",&i,&j);
            add(i,1),add(j+1,-1);
        }
        for(int i=90;i<=100;i++)
            printf("%d ",sum(i));
        //printf("%d\n",sum(n));
    }
    return 0;
}
