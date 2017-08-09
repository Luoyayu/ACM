#include <bits/stdc++.h>
/*
题目所求实则是找寻一段连续区间使得区间长度∗∗区间最小值最大，我们可以利用笛卡尔树以读入顺序为第一关键词，
读入的高为第二关键词且生成最小堆，这样建的树因为总是从最下右链插入数字，
因此对于笛卡尔树的每个节点它总是小于其孩子结点且其和左右子树一并构成连续的区间，
这样只要我们按照二叉树的后续遍历，
达每个结点时更新最大值=左右子树子树规模∗该结点对应的高(该连续区间最小的高)即可。总复杂度O(n)O(n).

*/
using namespace std;
typedef  long long LL;
const int maxn = 100007;
struct node
{
    LL value;
    int index;
    int pre, l, r;
    void clear() {
        l = r = pre = index =-1;
    }
}T[maxn];
#define stack STACK
int stack[maxn];
int build(int n)
{
    int top = -1;
    for (int i = 1; i <= n; i++)
    {
        int k = top;
        while (k>=0 && T[stack[k]].value > T[i].value) k--;
        if (k != -1)
            T[i].pre = stack[k], T[stack[k]].r = i;
        if (k < top)
            T[stack[k + 1]].pre = i, T[i].l = stack[k + 1];
        stack[++k] = i, top = k;
    }
    T[stack[0]].pre = -1;
    return stack[0];
}
LL ans;
LL dfs(int node)
{
    if(node ==-1) return 0;
    LL sz = dfs(T[node].l)+dfs(T[node].r)+1;
    ans = max(ans,sz*T[node].value);
    return sz;
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF,n)
    {
        for(int i = 1;i<=n;i++)
            scanf("%lld",&T[i].value),T[i].index = i,T[i].clear();
        ans = 0;
        dfs(build(n));printf("%lld\n",ans);
    }
    return 0;
}
