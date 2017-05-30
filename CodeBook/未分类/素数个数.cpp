#include<bits/stdc++.h>
using namespace std;
const int maxn=20000000+5;
int p[maxn],tot=0;
int isprime[maxn];
void init()
{
    fill(isprime,isprime+maxn,1);
    for(int i=2;i<maxn;i++)
    {
        if(isprime[i]) p[tot++]=i;
        for(int j=0;j<tot && i*p[j]<maxn;j++)
        {
            isprime[i*p[j]]=false;
            if(i % p[j] ==0) break;
        }

        if(isprime[i])
            isprime[i]+=isprime[i-1];
        else
            isprime[i]=isprime[i-1];
    }
}


int main()
{
    init();
    int a,b;
    while(scanf("%d %d",&a,&b)!=EOF)
    {
        int ans=isprime[b]-isprime[a-1];
        printf("%d\n",ans);
    }
    return 0;
}
