#include<bits/stdc++.h>
//比较丑的姿势
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

/*优先队列
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int ans = 0;
        priority_queue<int>pq;
        int s;scanf("%d",&s);
        for( int i = 1; i < n; i++ )
        {
            int x;
            scanf("%d",&x);
            pq.push(x);
        }
        while(s <= pq.top())
        {
            int t = pq.top();pq.pop();
            t--;
            ans++,s++;
            pq.push(t);
        }
        printf("%d\n",ans);
    }
  return 0;
}

*/
