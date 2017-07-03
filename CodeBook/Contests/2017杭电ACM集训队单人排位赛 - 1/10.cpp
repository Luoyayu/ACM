#include<bits/stdc++.h>
using namespace std;
const int N = 1007;
bool prime[N];
int p[N], tot;
int ans[N];
void init()
{
    for(int i = 2; i < N; i ++) prime[i] = true;
    for(int i = 2; i < N; i++){
        if(prime[i]) p[tot ++] = i;
        for(int j = 0; j < tot && i * p[j] < N; j++)
        {
            prime[i * p[j]] = false;
            if(i % p[j] == 0) break;
        }
    }
    for(int num=2;num<=1007;num++)
        for(int i=2;i<=num/2;i++)
            if(  (prime[i]&&!prime[num-i]) || (prime[num-i]&&!prime[i])  )
                ans[num]++;
}
int main()
{
    int n;
    init();
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            int a;
            scanf("%d",&a);
            printf("%d\n",ans[a]);
        }

    }
    return 0;
}
