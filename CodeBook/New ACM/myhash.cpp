//哈希表
//HDOJ 1280
#include<cstdio>
#include<cstring>
using namespace std;
int a[3003],hash[10010]={0};
int main(int argc, char const *argv[])
{
	int m,n,i,j;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);

		for(i=0;i<n;i++)
			for (j=i+1; j < n; ++j)
				hash[a[i]+a[j]]++;  //打哈希表

		int first = 1;   //标记
		for (i = 10000; i >=0; i--)
		{
			if (hash[i]>0)
			{
				if(m>=hash[i]) 
				{	for (j = 1; j <=hash[i]; j++)
					{
						if (first)
							first=0;
						else 
							printf(" ");
						printf("%d",i);
					}
					m -= hash[i]; //打完了i个
				}
				else 
				{
					for (j = 1; j <=m; j++)//打完
					{
						if(first)
							first=0;
						else printf(" ");
						printf("%d",i);
					}
					printf("\n");
					break;
				}
			}
		}
	}	
	return 0;
}