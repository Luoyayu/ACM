#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1000;
int c1[maxn],c2[maxn],n;
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<=n;i++)
            c1[i]=1,c2[i]=0;

        for(int i=2;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
                for(int k=0;k+j<=n;k+=i)
                    c2[j+k]+=c1[j];
                for(int j=0;j<=n;j++)
                    c1[j]=c2[j],c2[j]=0;
        }
        printf("%d\n",c1[n]);
    }
    return 0;
}
