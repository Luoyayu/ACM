#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=2333;
int flag;
struct point
{
    int x,y;
}M[maxn];
bool cp(point pi,point pj,point pk)
{
    return (pj.x-pi.x)*(pk.y-pi.y)-(pk.x-pi.x)*(pj.y-pi.y)>0;
}
int main()
{
    int n;
    while(scanf("%d",&n)&&n)
    {
        int flag=1;
        for(int i=0;i<n;i++)
            scanf("%d%d",&M[i].x,&M[i].y);
        M[n].x=M[0].x,M[n].y=M[0].y;
        for(int i=0;i<=n-2;i++)
            if(!cp(M[i],M[i+1],M[i+2]))
            {
                flag=0;
                break;
            }
        if(flag)
            printf("convex\n");
        else
            printf("concave\n");
    }
    return 0;
}
