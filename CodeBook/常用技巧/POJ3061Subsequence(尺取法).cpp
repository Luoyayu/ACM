#include<bits/stdc++.h>
using namespace std;
#define clr(a,b) memset(a,b,sizeof(b))
const int maxn = 1e5+7;
//二分尺取法
//打前缀和sum(i) =Σ[1~i) ai 
int sum[maxn];
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        clr(sum,0);
        int n;scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            int x;scanf("%d",&x);
            sum[i]+=sum[i-1] + x;
        }




    }
}