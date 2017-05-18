#include<stdio.h>
#include<math.h>
int vis[100000];
void era(int n)
{
    int m=sqrt(n+0.5);
    memset(vis,0,sizeof vis);
    for(int i=2;i<=m;i++) if(vis[i]==0)
    for(int j=i*i;j<=n;j+=i) vis[j]=1;
}
int main()
{
    int n;
    scanf("%d",&n);
    era(n);
    for(int i=0;i<n;i++)
  { if(vis[i]==0)
    printf("%d",i);
  }
  return 0;
}