#include <cstdio>
#include <queue>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
//题意:给出n支队伍的比分,win+3, tie各+1, lose+0;
//问两两比赛进行的最少场数和最多场数
//
const int inf =0x3f3f3f3f;
priority_queue <int> q;
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        while (!q.empty()) q.pop();
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            int score; scanf("%d", &score);
            sum += score;q.push(score);
        }
        int min_ans = inf ,max_ans = 0, tot = 0;
        while (1)
        {
            int x = q.top();q.pop();
            // debug(x);
            if (sum % 2 == 0 && (x<<1)<=sum)
            {
                max_ans = max(max_ans,tot+sum/2);
                min_ans = min(min_ans,tot+sum/2);
            }
            if(x<3) break;
            q.push(x-3);
            tot++;sum-=3;
        }
        printf("%d %d\n", min_ans, max_ans);
    }
    return 0;
}