//DFS 求石油快区域，深搜 
#include<cstdio>
int n,m;
char map[105][105];
void dfs(int a,int b)
{
	if(map[a][b]=='@')
	{
		map[a][b]='*';//八方向递归 
		dfs(a,b+1);  
        dfs(a+1,b+1);  
        dfs(a+1,b);  
        dfs(a+1,b-1);  
        dfs(a,b-1);  
        dfs(a-1,b-1);  
        dfs(a-1,b);  
        dfs(a-1,b+1);  
	}
	else 
		return;
}
int main()
{
	
	while(scanf("%d%d",&n,&m)!=EOF&&(n||m))
	{
		int cnt=0;
		scanf("%d%d",&n,&m);
		for(int i=0;i<=n;i++)
			for(int j=0;j<=m;j++)
				map[i][j]='*';
				
		for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=m;j++)
					scanf("%c",&map[i][j]);
				getchar();
			}
		
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(map[i][j]=='@')
					dfs(i,j),cnt++;
		printf("%d\n",cnt);
	}
}