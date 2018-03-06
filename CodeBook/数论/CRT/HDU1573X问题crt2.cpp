//CRT 不互质的合并上升法
#include <cstdio>
using namespace std;
int ex_gcd(int a,int b,int &x,int &y)
{
    if(!b)
    {
        x=1,y=0;
        return a;
    }
    int ans=ex_gcd(b,a%b,y,x);
    y-=a/b*x;
    return ans;
}
int main()
{
    int a[11],b[11];
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++)
            scanf("%d",&a[i]);
        for(int i=0;i<m;i++)
            scanf("%d",&b[i]);
        
        int flag=0,m1=a[0],r1=b[0];
        for(int i=1;i<m;i++)
        {
            int x,y;
            int m2=a[i],r2=b[i];
            int d=ex_gcd(m1,m2,x,y);
            int c=r2-r1;
            if(c % d) //推出矛盾
            {
                flag=1;
                break;
            }
            int tmp=m2/d;
            x=(c/d*x%tmp+tmp)%tmp;
            r1=x*m1+r1;//r1 最小解
            m1=m1/d*m2;//m1=lcm(m1,m2～～～)
        }
        //printf("%d %d\n",r1,m1);
        if(flag||n<r1)//！！！！！！！！！！注意细节
            printf("0\n");
        else
        {
            int ans=(n-r1)/m1+1;
            if(r1==0) ans--;//注意细节
            printf("%d\n",ans);
        }
    }
    return 0;
}