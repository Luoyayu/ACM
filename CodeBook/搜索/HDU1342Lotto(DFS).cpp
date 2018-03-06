//从n个数中选出6个按照递增顺序
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
const int maxn=22;
int a[maxn],b[maxn],n;
void dfs(int num,int pos)
{
    if(num==7)
    {
        for(int i=1;i<num;i++)
        {
            if(i==1)
                printf("%d",b[i]);
            else
                printf(" %d",b[i]);
        }
        printf("\n");return ;
    }
    if(pos>n) return ;
    b[num]=a[pos];
    dfs(num+1,pos+1);//选当前的
    dfs(num,pos+1);//不选当前的
}
int main()
{
    int ok=0;
    while(scanf("%d",&n)!=EOF&&n)
    {
        if(ok)
            printf("\n");
        ok=1;
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        dfs(1,1);
    }
    return 0;
}
