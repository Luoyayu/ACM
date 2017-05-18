#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
using namespace std;
const int N = 1000005;
int vis[N] = {0};
int ans[N]={0};
int sum1(int i)
{
	int sum=0;
	while (i>0)
    {
        sum += i % 10;
        i /= 10;
    }
    return sum;
}
void setans()  //note answers!
{  
    int i;  
    ans[0] = ans[1] = 0;  
    for(i = 2; i<=N; i++)  
    {  
        if(vis[i]==0 && vis[sum1(i)]==0)  
            ans[i] = ans[i-1]+1;  
        else  
            ans[i] = ans[i-1];  
    }  
}  
int main()
{
    int n, a, b,count,k,i;
    memset(vis,0,sizeof(vis));
        int m=sqrt(N+0.5);
        for(int i=2;i<=m;i++)
            if(!vis[i])
                for(int j=i*i;j<=N;j+=i)
                    vis[j]=1;
    scanf("%d",&n);
    setans();
    for(k=1;k<=n;k++)
    {
        scanf("%d%d", &a,&b);
	    printf("Case #%d: %d\n", k,ans[b]-ans[a-1]);
    }
    return 0;
}