#include<bits/stdc++.h>
using namespace std;
const int maxn=1000055;
char p[maxn];
int Next[maxn];
int len;
int t=0;
void getnext()
{
	int i=0,j=Next[0]=-1;
	while(i<len)
	{
		if(j==-1||p[i]==p[j])
			i++,j++,Next[i] = j;
		else
			j = Next[j];
	}
}
int period()
{
    getnext();
    printf("Test case #%d\n",++t);
    for(int i=0;i<=len;i++)
    {
        if(Next[i]==-1||Next[i]==0)
            continue;
        int j=i-Next[i];
        if(i%j==0)
            printf("%d %d\n",i,i/j);
    }
    printf("\n");
}
int main()
{
    while(scanf("%d",&len),len)
    {
        scanf("%s",p);
        period();

    }
    return 0;
}
