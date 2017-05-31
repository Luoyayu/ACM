#include<bits/stdc++.h>
//就这样F过了？？？
using namespace std;
bool g[150][150];
int main()
{
    int a,b,c,d;
    ios::sync_with_stdio(false);
    while(1)
    {
     	int sum=0;
     	memset(g,0,sizeof(g));
	    while(cin>>a>>b>>c>>d&&a!=-1&&a!=-2)
	    	for(int i=min(a,c);i<max(a,c);i++)
            {
	    		for(int j=min(b,d);j<max(b,d);j++)
                    if(!g[i][j])
                        g[i][j]=1,sum++;
			}
		printf("%d\n",sum);
		if(a==-2) break;
	 }
    return 0;
}
