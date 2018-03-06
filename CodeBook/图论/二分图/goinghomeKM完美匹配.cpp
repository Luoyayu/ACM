#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn= 223;
const int inf = 0x3f3f3f3f;
int linker[maxn];
int lx[maxn],ly[maxn];
int visx[maxn],visy[maxn];
char map[maxn][maxn];
int g[maxn][maxn];
int slack[maxn];
int n,m;
void init()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
				g[i][j]=-inf;
}
bool Hungary(int u)
{
	visx[u] = true;
	for(int y = 1; y <= n; ++y)
	{
		if(visy[y])
			continue;
		else
		{
			if(lx[u] + ly[y] == g[u][y])
			{
				visy[y] = true;
				if(linker[y] == -1 || Hungary(linker[y]))
				{
					linker[y] = u;
					return true;
				}
			}
			else
				slack[y] = min(slack[y], lx[u] + ly[y] - g[u][y]);
		}
	}
	return false;
}

void KM_perfect_match()
{
	int temp;
	for(int i = 1; i <= n; ++i)
		lx[i] = -inf;
		
	memset(ly, 0, sizeof(ly));
	
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			lx[i] = max(lx[i], g[i][j]);
			
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
			slack[j] = inf;
			
		while(1)
		{
			memset(visx, false, sizeof(visx));
			memset(visy, false, sizeof(visy));
			if(Hungary(i))
				break;
			else
			{
				temp = inf;
				for(int j = 1; j <= n; ++j)
					if(!visy[j])
						temp = min(temp, slack[j]);
				for(int j = 1; j <= n; ++j)
				{
					if(visx[j])
						lx[j] -= temp;
					if(visy[j])
						ly[j] += temp;
					else
						slack[j] -= temp;
				}
			}
		}
	}
		bool flag=true;
		int ans=0;
		for(int i = 1; i <= m; ++i) 
		{
			if(linker[i] == -1 || g[ linker[i] ][i] == -inf)
			{
				flag = false;
				break;
			}
			ans += g[linker[i]][i];
		}
		if(flag)
			printf("%d\n", -ans);
		
}

int main()
{
    int n,m;
    memset(map,0,sizeof map);
    while(scanf("%d%d",&n,&m)!=EOF&&(n||m))
    {
    	memset(linker,-1,sizeof linker);
    	init();
    	for(int i=1;i<=n;i++)
    	{
    		getchar();
    		for(int j=1;j<=m;j++)
    			scanf("%c",&map[i][j]);
    	}
    	int numOfm=0,numOfH;
    	for(int i=1;i<=n;i++)
    		for(int j=1;j<=m;j++)
    		{
    			if(map[i][j]=='m')
    			{
    				numOfm++;numOfH=1;
    				for(int k=1;k<=n;k++)
    					for(int q=1;q<=m;q++)
    						if(map[k][q]=='M')
    							g[numOfm][numOfH]=-(abs(i-k)+abs(q-j)),numOfH++;
    			}
    		}
    		n=m=numOfm;
    	KM_perfect_match();
    }
    return 0;
}