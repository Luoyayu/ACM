//������dfs
#include <cstdio>
#include<cmath>
#include<cstring>
int vis[25];
int num[25];
int n,kase=0;
int jud(int x)//������Դ���Ż� 
{
	for(int i=2;i<=sqrt(x);i++)
		if(x%i==0) return 0;
	return 1;
} 
int DFS(int x=1)
{
	if(x==n&&jud(num[n-1]+1))//�ѵ�nʱ��������1�ĺ�Ϊ������� 
	{
		for(int i=0;i<n-1;i++)
			printf("%d ",num[i]);
		printf("%d\n",num[n-1]); 
		return 0;
	}
	for(int i=2;i<=n;i++)//2 -> n 
	{
		if(!vis[i])//û�б���ǹ� 
		{
			if(jud(num[x-1]+i))//��ǰһ����Ϊ���� 
			{
				vis[i]=1;//��� 
				num[x]=i;//
				DFS(x+1);//dfs 
				vis[i]=0;//���Ϊ0���ڻ��� 
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
		printf("Case %d:\n",++kase);//ע���ʽ 
		DFS();
		printf("\n");
	}
	return 0;
} 