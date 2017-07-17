#include<bits/stdc++.h>
using namespace std;
//不好意思题又读错啦@_@
int t,n,m;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        int x,y,z,a,b;//(0,0,1)->(x,y,z);
        scanf("%d%d%d%d%d%d",&n,&x,&y,&z,&a,&b);
        int ans1 = n+n+(z-1)*b+(n-x)+(n-y);//全电梯
        int ans2 = a*(z-1)+x+y;//全楼梯

        /*无效判断
        int ans3 = n+n+b*(z-2)+n+n+a+x+y;//z-1电梯+楼梯
        int ans4 = a*(z-2)+n+n+b+(n-x)+(n-y);//z-1楼梯+电梯
        */
        
        //printf("%d\n",min(ans1,min(ans2,min(ans3,ans4))));
        printf("%d\n",min(ans1,ans2));
    }
    return 0;
}