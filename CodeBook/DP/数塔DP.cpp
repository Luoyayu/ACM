#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=101;
int D[maxn][maxn],n;
int maxSum[maxn][maxn];

inline int dp(int i=1,int j=1)
{
	if(maxSum[i][j]!=-1)
		return maxSum[i][j];
	if(i==n) maxSum[i][j]=D[i][j];
	else
	{
		int x=dp(i+1,j);
		int y=dp(i+1,j+1);
		maxSum[i][j]=max(x,y)+D[i][j]; 
	}
	return maxSum[i][j];
}
int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=i;j++)
			{
				scanf("%d",&D[i][j]);
				maxSum[i][j]=-1;
			}
		printf("%d\n",dp());
	}
	return 0;
} 