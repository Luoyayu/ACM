#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=1000000+10;
vector <int>V[maxn];
int value[maxn];
int main()
{
    for(int i=0;i<maxn;i++)
        V[i].clear();
    for(int i=1;i<=maxn;i++)
        for(int j=i;j<maxn;j+=i)
            V[j].push_back(i);
    int t;
    scanf("%d",&t);
    for(int kase=1;kase<=t;kase++)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++)
            scanf("%d",&value[i]);

        printf("Case %d:",kase);

        for(int i=2;i<=n;i++)
        {
            int gcd=__gcd(value[i-1],value[i]);
            int pos=V[gcd].size();
            if(pos<k)
                printf(" -1");
            else
                printf(" %d",V[gcd][pos-k]);
        }
        printf("\n");
    }
    return 0;
}
