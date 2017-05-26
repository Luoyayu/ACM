//素数环dfs
#include <cstdio>
#include<cmath>
#include<cstring>
int vis[25];
int num[25];
int n,kase=0;
int jud(int x)//这里可以打表优化 
{
	for(int i=2;i<=sqrt(x);i++)
		if(x%i==0) return 0;
	return 1;
} 
int DFS(int x=1)
{
	if(x==n&&jud(num[n-1]+1))//搜到n时，并且与1的和为奇数输出 
	{
		for(int i=0;i<n-1;i++)
			printf("%d ",num[i]);
		printf("%d\n",num[n-1]); 
		return 0;
	}
	for(int i=2;i<=n;i++)//2 -> n 
	{
		if(!vis[i])//没有被标记过 
		{
			if(jud(num[x-1]+i))//和前一个和为奇数 
			{
				vis[i]=1;//标记 
				num[x]=i;//
				DFS(x+1);//dfs 
				vis[i]=0;//标记为0便于回溯 
			}
		}
	}
}
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		num[0]=1;
		memset(vis,0,sizeof vis); 
		printf("Case %d:\n",++kase);//注意格式 
		DFS();
		printf("\n");
	}
	return 0;
} 