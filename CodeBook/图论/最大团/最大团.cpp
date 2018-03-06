#include<cstdio>
const int MAXN=55;
int n,g[MAXN][MAXN],best,num[MAXN];
bool dfs(int tmp[],int total,int cnt)
{
	int j,k,a[MAXN];
	if(!total)
    {
		if(best<cnt)
        {
			best=cnt;
			return 1;
		}
		return 0;
	}
	for(int i=0;i<total;i++)
    {
		if(cnt+(total-i)<=best)return 0;
		if(cnt+num[tmp[i]]<=best)return 0;
		for(k=0,j=i+1;j<total;j++)
			if(g[tmp[i]][tmp[j]])
                a[k++]=tmp[j];
		if(dfs(a,k,cnt+1)) return 1;

	}
	return 0;
}
int MaxNumClique()
{
	int j,k,tmp[MAXN];
	best=0;
	for(int i=n-1;i>=0;i--)
    {
		for(k=0,j=i+1;j<n;j++)
			if(g[i][j])
				tmp[k++]=j;
		dfs(tmp,k,1);
		num[i]=best;
	}
	return best;
}

int main()
{
	while(scanf("%d",&n)!=EOF,n)
    {
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				scanf("%d",&g[i][j]);
		printf("%d\n",MaxNumClique());
	}
	return 0;
}
