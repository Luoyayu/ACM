#include<bits/stdc++.h>
using namespace std;
const int maxn = int(2e5+7);
int a[maxn],b[maxn];
#define clr(a,b) memset(a,b,sizeof(a))
//求两个数串的最长的公共包含的连续自然数的子序列的最大长度
//dp[i]表示以i 结尾的连续自然数的子序列
//转移方程dp[a[i]]=dp[a[i]-1]+1
const int maxm = int (1e6+7);
int dpa[maxm],dpb[maxm];
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        //clr(dpa,0);clr(dpb,0);
        int n,m;scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]),dpa[a[i]]=dpa[a[i]-1]+1;

        for(int i=1;i<=m;i++)
            scanf("%d",&b[i]),dpb[b[i]]=dpb[b[i]-1]+1;

        int sum = 0;
        for(int i=0;i<=maxn;i++)
            sum = max(min(dpa[i],dpb[i]),sum);

        for(int i=1;i<=n;i++)//不能直接memset
            dpa[a[i]] = 0;
        for(int i=1;i<=m;i++)
            dpb[b[i]] = 0;
        printf("%d\n",sum);
    }
    return 0;
}
