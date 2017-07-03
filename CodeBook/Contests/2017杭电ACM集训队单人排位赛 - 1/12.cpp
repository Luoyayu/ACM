#include<bits/stdc++.h>
using namespace std;
const int maxn=25;
int p1[maxn],p2[maxn];
int main()
{
    int n,m;
    freopen("C:\\Users\\gavin\\Desktop\\input.txt","r",stdin);
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int ans=0;
        for(int i=0;i<n;i++) scanf("%d",&p1[i]),ans+=p1[i];
        for(int i=0;i<m;i++) scanf("%d",&p2[i]);

        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(p2[i]<p1[j])
                    ans+=p2[i];
            }
        for(int i=0;i<m;i++)
        {
            int cnt=0;
            for(int j=0;j<n;j++)
            {

            }

        }

        printf("%d\n",ans);
    }
    return 0;

}
