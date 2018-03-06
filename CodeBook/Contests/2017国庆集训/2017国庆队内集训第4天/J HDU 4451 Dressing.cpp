#include<bits/stdc++.h>
//题意：给出N*M*K的clothes, pants, shoes
//再给出c到p或p到s的一些不能搭配的组合, 问 cps一共有多少组合
//在纸上画出点的连线, 以中间的p为分界点
using namespace std;
const int maxn =1001;
#define clr(a,b) memset(a,b,sizeof(a));
int cp[maxn],ps[maxn];
int main()
{
   int p,n,m,k;
   while(scanf("%d%d%d",&n,&m,&k)!=EOF&&(n||m))
   {
       clr(cp,0);clr(ps,0);
       scanf("%d",&p);
       int tmp=0;
        while(p--)
       {
           int a,b;char s[maxn];
           scanf("%s%d%s%d",s,&a,s,&b);
           if(s[0])=='p')
               cp[b]++,tmp+=k;
           else
               ps[a]++, tmp+=n;
       }
       for(int i=1;i<=m;i++)
           tmp-=cp[i]*ps[i]; //补上减多的情况
       printf("%d\n",n*m*k-tmp);
   }
    return 0;
}
