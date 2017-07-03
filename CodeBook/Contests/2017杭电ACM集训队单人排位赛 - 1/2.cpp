#include<bits/stdc++.h>
const int maxn=1e6+7;
using namespace std;
int p[1007];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
            scanf("%d",&p[i]);
        sort(p+1,p+n);
        int cnt=0;
        while(p[n-1]>=p[0])
        {
            p[0]++;
            p[n-1]--;
            sort(p+1,p+n);
            cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
