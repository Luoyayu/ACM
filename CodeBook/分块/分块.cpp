#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
#include <cmath>
using namespace std;
int n,m;
int arr[100005];
int num[500][11][10];
int big=0;
void init()
{
    int x,index;
    for(int i=0;i<n;i++)
    {
        index=i/big;
        x=arr[i];
        for(int j=0;j<=10;j++)
        {
            num[index][j][x%10]++;
            x/=10;
        }
    }
}
inline int ans(int x,int y,int z)
{
    int cnt=0;
    for(int i=0;i<=10;++i)
    {
        if(i==z)return x%10==y;
        x/=10;
    }
}
void query(int l,int r,int d,int p)
{
    int ret=0;
    int x1=l/big,x2=r/big;
    if(x1==x2){
        for(int i=l;i<=r;++i)
        {
            ret+=ans(arr[i],p,d);
        }
        printf("%d\n",ret);
        return;
    }

    for(int i=x1;i<=x2;++i)
    {
        if(i==x1&&l%big!=0)
        {
            for(int j=l;j<big*(x1+1);++j)
                ret+=ans(arr[j],p,d);
        }
        else if(i==x2&&r%big!=big-1)
        {
            for(int j=r;j>=big*x2;--j)
                ret+=ans(arr[j],p,d);
        }
        else
            ret+=num[i][d][p];
    }
    printf("%d\n",ret);
    return;
}

void update(int x,int y)
{
    int index=x/big;
    for(int i=0;i<=10;++i)
    {
        --num[index][i][arr[x]%10];
        arr[x]/=10;
    }
    arr[x]=y;
    int ac=arr[x];
    for(int i=0;i<=10;++i)
    {
        ++num[index][i][ac%10];
        ac/=10;
    }
    return;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        big=sqrt(n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
        memset(num,0,sizeof(num));
        init();
        char s[2];
        int x,y,d,p;
        for(int i=0;i<m;i++)
        {
            scanf("%s",s);
            if(s[0]=='Q')
            {
                scanf("%d%d%d%d",&x,&y,&d,&p);
                query(x-1,y-1,d-1,p);
            }
            else
            {
                scanf("%d%d",&x,&y);
                update(x-1,y);
            }
        }
    }
    return 0;
}
