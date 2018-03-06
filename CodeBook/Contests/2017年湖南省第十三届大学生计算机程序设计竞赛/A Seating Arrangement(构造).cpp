#include <cstdio>
//题意：给出1~n的排列和d,找出一种排列满足任意两个数差的绝对值大于d
//显然合理的答案与d无关 if n>=d/2则是无解的,否则对于奇偶n都可以构造出形式固定的排列
//蛮水的,前期瞎构造, 组合方式是没问题的
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