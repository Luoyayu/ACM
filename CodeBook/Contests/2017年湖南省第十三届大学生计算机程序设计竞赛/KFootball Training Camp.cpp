#include <cstdio>
#include <queue>
using namespace std;
const int inf =0x3f3f3f3f;
priority_queue <int> q;
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        while (!q.empty()) q.pop();
        int tot = 0 , sum = 0;
        for(int i=0;i<n;i++)
        {
            int score; scanf("%d", &score);
            q.push(score);
            sum += score;
        }
        int min_ans = inf ,max_ans = 0;
        tot = 0;
        while (1)
        {
            int x = q.top();q.pop();
            //printf("top= %d\n",x);
            if (sum % 2 == 0 && (x<<1)<=sum)
            {
                max_ans = max(max_ans,tot+sum/2);
                min_ans = min(min_ans,tot+sum/2);
            }
            if(x<3) break;q.push(x-3);
            tot++;sum-=3;
        }
        printf("%d %d\n", min_ans, max_ans);
    }
    return 0;
}