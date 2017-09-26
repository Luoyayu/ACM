#include<bits/stdc++.h>
using namespace std;
//区间不相交取两个区间的最大值，两区间相交的话都取
//直接区间转换成点统计最大值
int se[1001];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(se,0,sizeof(se));
        if(!n)
        {
            printf("*\n");
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            int s,t,k;scanf("%d%d%d",&s,&t,&k);
            for(int j=s+1;j<=t;j++) se[j] += k;//只打上一个端点
        }
        int ans = 0;
        for(int i=1;i<=101;i++)
            ans = max(ans,se[i]);
        printf("%d\n",ans);
    }
    return 0;
}
