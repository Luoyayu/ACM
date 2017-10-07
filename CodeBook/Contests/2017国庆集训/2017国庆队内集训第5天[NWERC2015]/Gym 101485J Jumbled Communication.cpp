#include<bits/stdc++.h>
using namespace std;
//题意：给出最大为255的N 求x ^ (x<<1) =N 的x
// 思路打表或者直接按位处理

//A.cpp 打表
const int maxn = 1e5 + 7;
int ans[maxn],ans[maxn];
int main()
{
    int n;scanf("%d",&n);
    for(int i=0;i<=255;i++)
    {
        a[i] = (i ^(i<<1) %256);
        ans[a[i]] = i;
    }

    while(scanf("%d",&n)!=EOF)
    {
        int x;
        scanf("%d",&x);
        printf("%d%c",ans[x],i==n?'\n':' ');
    }
    return 0;
}



//b.cpp 按位运算
int main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int ans[9]={0};
        int x;scanf("%d",&x);
        int now = 0;
        for(int j=0;j<=7;j++)
        {
            int c = (x>>j) & 1;
            ans[j] = c ^ now;
            now = ans[j];
        }
        int p = 0;
        for(int k=7;k>=0;k--)
        {
            p = (p<<1)+ans[k];
        }
        printf("%d%c",p,i==n?'\n':' ');
    }
    return 0;
}
