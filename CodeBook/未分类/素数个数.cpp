#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
const int maxn=20000000+5;
bool isprime[maxn];
int p[maxn],tot=0;
void init()
{
    memset(isprime,1,sizeof isprime);
    for(int i=2;i<maxn;i++)
    {
        if(isprime[i]) p[tot++]=i;
        for(int j=0;j<tot && i*p[j]<maxn;j++)
        {
            isprime[i*p[j]]=false;
            if(i % p[j] ==0) break;
        }
    }
}
int main()
{
    init();
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        int cnt=0;
        for(int i=0;i<tot;i++)
        {
            if(p[i]>=a&&p[i]<=b)
                cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
