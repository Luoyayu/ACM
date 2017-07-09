#include<bits/stdc++.h>
using namespace std;
#define y2 Y2
#define next Next;
#define lowbit(x) x&(-x)
#define IOS std::ios::stdio(flase)
#define clr(x,num) memset(x,num,sizeof(x));
#define Debug(x) cout<<#x<<" = "<<x<<endl;
typedef long long ll;
const int maxn = 1e5 + 7;
const int maxc = 1e3 + 5;
const int maxr = 1e5 + 5;
const int MOD  = 1e9 + 7;
const int inf  = 0x3f3f3f3f;
const double esp = 1e-6;
const double pi = acos(-1);
int g[105][105];
int ans[105];
int main()
{
     int n,m;
     while(scanf("%d%d",&n,&m)!=EOF)
     {
        memset(ans,0,sizeof ans);
        memset(g,0,sizeof g);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                scanf("%d",&g[i][j]);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
                ans[i]+=g[j][i];
        }
        for(int i=0;i<m-1;i++)
            printf("%d ",ans[i]);
        printf("%d\n",ans[m-1]);


     }return 0;
}
