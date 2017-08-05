//P 1000000
#include <cstdio>
#include <map>
#include <cstring>
#include <set>
using namespace std;
const int maxn = 1e6 + 7;
int a[maxn];
int main()
{
    set<int> all;
    int p;scanf("%d",&p);
    int tot = 0;
    for(int i=0;i<p;i++)
    {
        scanf("%d",&a[i]);
        all.insert(a[i]);
    }
    int n = all.size();
    map<int,int> cnt;//知识点->出现次数 cnt[知识点]=次数
    int sum = 0,s = 0, t = 0;
    int res = p;
    while(1)
    {
        while(sum < n && t < p)
            if(cnt[a[t++]]++ == 0) sum++;
        if(sum<n) break;
        res = min(res, t-s);//t 潜在++
        if(--cnt[a[s++]]==0)  sum--;
    }
    printf("%d\n",res);
    return 0;
}