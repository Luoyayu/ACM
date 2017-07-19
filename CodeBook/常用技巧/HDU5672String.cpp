#include<bits/stdc++.h>
using namespace std;
#define clr(a,b) memset(a,b,sizeof(a))
//题意：给出string len<=1e6
//问有多少子串中至少有k个不同字母
//思路:尺取法：对于以满足的串[l,r]，其后面的 len-r+1串以满足，故O(n)枚举起点
const int maxn = int(1e6+7);
typedef long long ll;
char str[maxn];
int vis[27];
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int k;scanf("%s %d",str,&k);
        clr(vis,0);
        ll ans = 0;
        int s = 0, t = 0, len = strlen(str);
        int sum = 0;
        while(1)
        {
            while(t<len && sum < k)
            {
                int tmp = str[t++]-'a';//移动右标
                if(!vis[tmp])
                    sum++;
                vis[tmp]++;
            }
            if(sum<k) break;
            ans += len - t + 1;
            int tmp = str[s++]-'a';//移动左标
            vis[tmp]--;
            if(vis[tmp]==0)//会对sum造成影响的自减
                sum--;
        }
        printf("%lld\n",ans);
    }
    return 0;
}