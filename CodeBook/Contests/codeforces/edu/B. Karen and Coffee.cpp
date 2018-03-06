#include<bits/stdc++.h>
#define lowbit(x) x&(-x)
using namespace std;
int c[200005],n;
int mark[200005];
int k;
void add(int x,int d)
{
    while(x<=200000)
        c[x]+=d,x+=lowbit(x);
}
int sum(int x)
{
    int ans=0;
    while(x)
    {
        ans+=c[x],x-=lowbit(x);
        if(ans>=k)
            return 1;
    }
    return 0;
}
int main()
{
    int n,q;
    while(scanf("%d %d %d",&n,&k,&q)!=EOF)
    {
        memset(mark,0,sizeof mark);
        while(n--)
        {
            int i,j;
            scanf("%d %d",&i,&j);
            add(i,1),add(j+1,-1);
        }
        while(q--)
        {
            int ans=0;
            int i,j;
            scanf("%d %d",&i,&j);
            for(int QQ=i;QQ<=j;QQ++)
            {
                if(mark[QQ])
                {
                    ans++;
                    continue;
                }
                if(sum(QQ))
                    ans++,mark[QQ]=1;
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
