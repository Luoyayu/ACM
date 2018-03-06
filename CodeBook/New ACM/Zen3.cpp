#include<cstdio>
#include<cstring>
#include<cmath>
#include<cctype>
#include<cstdlib>
#include<set>
#include<string>
#include<algorithm>
using namespace std;
#if 0 //校检整除
int n;
int judge(int *x)
{
    for (int i = 1; i < n; i++)
        x[n] /= __gcd(x[i], x[n]);
    return x[n] == 1;
}
int main()
{
    int ar[15];
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &ar[i]);
    if (judge(ar))
        printf("YES\n");
    else
        printf("NO\n");
}
#endif
#if 0 //筛法素数表
bool vis[10005]={0};
int  main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		memset(vis,0,sizeof(vis));
        int m=sqrt(n+0.5);
        for(int i=2;i<=m;i++)
            if(!vis[i])
                for(int j=i*i;j<=n;j+=i)
                    vis[j]=1;
        for(int i=0;i<n;i++)
            if(vis[i]==0)
            printf("%d ",i);
	}
    return 0;
}
#endif

