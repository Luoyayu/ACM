//TODO:POJ3253
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <iostream>
//题意:给出木板长度和切割后的每块的长度,切割的花费为操作块的总长
//思考:对于一种切割方式我们发现切割后的每块板子产生的耗费等于该板的长度*该板所在的深度;贪心来看深度最大的应该是最短板,假设其余的板都在上一层被切割好,那么如果不这样放,一定会导致花费增加,再看且它只能是有一个兄弟的(如果没有兄弟不能保证处于深度最大的层除非只用切成2或1块).
//如此将两块板合并成一块，在同上处理N-1块板子。
using namespace std;
const int maxn =  20000+7;
typedef long long ll;
int L[maxn],n;
ll solve()
{
    ll ans = 0;
    priority_queue<int,vector<int>,greater<int> > q;
    for(int i=1;i<=n;i++) q.push(L[i]);
    while(q.size()>=2)
    {
        int l1,l2;
        l1 = q.top();q.pop();
        l2 = q.top();q.pop();

        ans += l1+l2;
        q.push(l1+l2);
    }
    return ans;
}
int main()
{

    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
            scanf("%d",&L[i]);
        printf("%lld\n",solve());
    }
    return 0;
}
