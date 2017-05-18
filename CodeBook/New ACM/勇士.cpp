#include<stdio.h>
char ar;
int Hp[2],Atk[2],Def[2],Hurt[2];
bool over()
{
	Hurt[0]=Atk[0]-Def[1];//��ʿ's hurt 
	Hurt[1]=Atk[1]-Def[0];//boss's hurt 
	if(Hurt[0]<0) return 0;
	if(Hurt[1]<0) return 1;
	
	int p=(ar=='W'?0:1);
	while(1)
	{
		Hp[p^1]-=Hurt[p];
		if(Hp[p^1]<=0)
		return p==0;
		p^=1;
	}	
}
int main()
{
	while(scanf("%c",&ar)!=EOF)
	{
		for(int i=0;i<2;i++)
			scanf("%d%d%d",&Hp[i],&Atk[i],&Def[i]);
		puts(over()?"Warrior wins":"Warrior loses"); 
	}
	  return 0;
}
