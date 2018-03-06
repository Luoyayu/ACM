//假的反素数，假的唯一分解，当我没写过
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        int MAX=0,k;
        for(int i=a;i<=b;i++)
        {
            int d=0;
            for(int j=1;j<=i;j++)
                if(!(i%j))
                    d++;
            printf("%d ",d);
            ///if(d>MAX) MAX=d,k=i;
        }
        //printf("%d\n",k);
    }
}
