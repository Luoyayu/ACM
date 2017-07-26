#include<cstdio>
#include<cstring>
const int maxn=32005;
int c[maxn],n,a[maxn];
int lowbit(int x)
{
    return x&(-x);
}
void add(int x,int d)
{
    while(x<=maxn)
        c[x]+=d,x+=lowbit(x);
}

int sum(int x)
{
    int ans=0;
    while(x)
        ans+=c[x],x-=lowbit(x);
    return ans;
}

int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        memset(c,0,sizeof c);
        memset(a,0,sizeof a);
        for(int i=0;i<n;i++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            x++;
           // printf("%d\n",sum(x));
            a[sum(x)]++;//x maybe 0
            add(x,1);
        }
        for(int i=0;i<n;i++)
                printf("%d\n",a[i]);
    }
    return 0;
}












