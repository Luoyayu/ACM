#include <cstdio>
int n,d;
int main()
{
   while(scanf("%d%d",&n,&d)!=EOF)
   {
       if(d>=n/2)
       {
           printf("-1\n");continue;
       }
       if(n%2)
       {
           for(int i=1;i<=n/2;i++)
               printf("%d %d ",i,i+n/2+1);
           printf("%d\n",n/2+1);
       }
       else
           for(int i=1;i<=n/2;i++)
             printf("%d %d%c",n/2+i,i,i==n/2?'\n':' ');
   }
   return 0;
}