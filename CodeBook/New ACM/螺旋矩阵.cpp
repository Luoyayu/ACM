#include<cstdio>
#include<cstring>
const int MAXN=34000;
int list[MAXN/2];
 void init()
{
     for(int i=0; i<MAXN/2; ++i)
         if(!i) list[i] = 1;
         else list[i] = 8*i-2+list[i-1];
 }
int main()
{
	init();
	int T,r,c;
	scanf("%d",&T);
	while(T--)
	{
		long n,m;
		scanf("%ld%ld",&n,&m);
		
		int circle=-1,dis;
		while(list[++circle]<=m)
			c=r=n/2+1-circle;
		if(list[circle]==m)
		{
			printf("%d %d\n",r,c);
			continue;
		}	
		dis=list[circle]-m;
		if(dis<=circle*4)
		{
			if(dis<=circle*2)
				r+=dis;
			else 
				r+=circle*2,c+=dis-circle*2;
		}
		else 
		{
			int tmp=dis-circle*4;
			if(tmp<=circle*2-1)
				r+=circle*2-tmp,c+=circle*2;
			else 
			{
				tmp-=circle*2-1;
				r++;
				c+=circle*2-tmp;
			}	
		}
		printf("%d %d\n",r-1,c-1);
	}
	return 0;
}