#include <bits/stdc++.h>

using namespace std;
const int MAXN=100005;
int a[MAXN],dp[MAXN];
struct node
{
    int first,last,maxn;
    node(int first,int last,int maxn):first(first),last(last),maxn(maxn){}
    friend bool operator <(const node& a,const node& b)
    {
        return a.maxn > b.maxn;
    }
};
vector<node> G;
int main()
{
    int t;
    ios::sync_with_stdio(false);
    cin>>t;
    for(int j=1;j<=t;j++ )
    {

        int n,first=1,last=1;
        G.clear();
        cin>>n;
        for(int i=1;i<=n;i++ )
            scanf("%d",&a[i]);
        dp[1]=a[1];
        G.push_back(node(first,last,dp[1]));
        for(int i=2;i<=n;i++)
        {
            if(dp[i-1]+a[i]<a[i])
            {
                dp[i]=a[i];
                first=last=i;

            }
            else if(dp[i-1]+a[i]>=a[i])
            {
                dp[i]=dp[i-1]+a[i];
                last++;
            }
            G.push_back(node(first,last,dp[i]));
        }
        sort(G.begin(),G.end());
        printf("Case %d:\n%d %d %d\n",j,G[0].maxn,G[0].first,G[0].last);
        if(j!=t)
            printf("\n");
    }
    return 0;
}
