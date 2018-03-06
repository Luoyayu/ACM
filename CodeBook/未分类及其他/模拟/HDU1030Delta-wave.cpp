//斜坐标模拟
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
inline int cal(int n,int &x,int &y,int &z)
{
    x=sqrt(1.0*(n-1))+1;
    int thR=x==1?1:x*x-n;
    z=thR/2+1;
    int thL=x==1?1:n-((x-1)*(x-1)+1);
    y=thL/2+1;
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int x1,y1,z1,x2,y2,z2;
        cal(n,x1,y1,z1);cal(m,x2,y2,z2);
        //printf("%d %d %d\n",x1,y1,z1);
        //printf("%d %d %d\n",x2,y2,z2);
        printf("%d\n",abs(x1-x2)+abs(y1-y2)+abs(z1-z2));
    }
    return 0;
}
