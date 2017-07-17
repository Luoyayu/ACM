#include<bits/stdc++.h> //for G++
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
int g[maxc][maxc];
//有向图给出所有点之间的最短路要求还原图的最小边数
//通过Floyd更新去边
int _floyd(int n)
{
    int ans=0;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
        {
            if(i==j) continue;
            for(int k=1; k<=n; k++)
            {//比如 [1->3(12), 1->2(1), 1->3(2)]显然[1->3]这条边存在即不合理
                if(i==k && j==k) continue;
                if(g[i][j] > g[i][k] + g[k][j] && g[i][k] && g[k][j]) return -1;
                else if(g[i][j]==g[i][k] + g[k][j] && g[i][k] && g[k][j]) 
                    {ans++;break;}
            }
        }
    return ans;
}
int main()
{
    int t;scanf("%d",&t);
    for(int kase=1; kase<=t; kase++)
    {
        int cnt=0;
        int n;scanf("%d",&n);
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
            {
                scanf("%d",&g[i][j]);
                if(g[i][j])
                    cnt++;//记录有效总边数
            }
        printf("Case %d: ",kase);
        int deleted = _floyd(n);
        if(deleted == -1)
            printf("impossible\n");
        else
            printf("%d\n",cnt-deleted);
    }
    return 0;
}
