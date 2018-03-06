### #是时候学习一波笛卡尔树了
启示于2017 Multi—Contes Team 1 1012
笛卡尔树 一种特定的二叉搜索树 适用于一般数列的RMQ,RtopkQ(区间第k大/小查询)
其中 中序(in-order)遍历可以输出原序列
笛卡尔树的O(n)建树方法 以最小堆为例
有序列$latex A[1...n]$, 树根为A中最小的数的下标i,左子树为$latex A[1...i-1]$, 右子树为A[i+1...n]的笛卡尔树
### #建立方法
>遍历数组 把第一个值作为最初的根节点
（每个值从根节点出发一直向右走直到找到第一个比该值大的节点(或者走到无右子节点为止) 把该值放在找到的节点位置,原先位置的节点作为该值的左子节点）
或者从最右链由下往上出发找到第一个比该值小的数 p,将待插入的值作为p的右子节点,将p的原先的节点作为待插入值的左子节点
由于每个数最多进入一次最右链,最多一次退出最右链,因此均摊复杂度$latex O(n)$


### #Cartesian_Tree (C++)
```cpp
#include <bits/stdc++.h>
using namespace std;
typedef  long long LL;
const int maxn = 10007;
const int inf = 0x3f3f3f3f;
const LL INF = (LL) 1<<62;
int a[] = {0,9,3,7,1,8,12,10,20,15,18,5};
// int a[] = {0,4,7,9,2,1,3};
struct node
{
    int value, index; //二叉堆第一关键词index, 第二关键词value
    int pre, l, r;
    void clear() {
        l = r = pre = index =-1;
    }
}T[maxn];
#define stack STACK
int stack[maxn];
pair<int,int> build(int n) //建立笛卡尔树
{
    int top = -1;
    for (int i = 1; i <= n; i++)//依次遍历数组元素
    {
        int k = top;
        //while (k>=0 && a[stack[k]] > a[i]) k--;//栈中比当前元素大的都出栈也就是找到第一个比待插元素小的数p
        while (k>=0 && T[stack[k]].value > T[i].value) k--;//栈中比当前元素大的都出栈也就是找到第一个比待插元素小的数p
        if (k != -1) // 找到啦&&不是树根位置,此时这个a[i]成为栈顶元素的右孩子
            T[i].pre = stack[k], T[stack[k]].r = i;
        //这个值是树根位置或者要操作一般位置(栈内还有元素)
        if (k < top) //将stack[k]位置往下的节点变为a[i]的左孩子
            T[stack[k + 1]].pre = i, T[i].l = stack[k + 1];
        stack[++k] = i, top = k;//当前节点序号入栈,top指向栈顶序号
    }
    T[stack[0]].pre = -1;
    return make_pair(stack[0],T[stack[0]].value); //返回根节点的序号和根节点的值
}

   /*int build2(int n) //from @ACdreamers fail in Test
   {
       for(int i = 1; i <= n; i++)
       {
           int j = i-1;
           while(T[j].value > T[i].value)
               j = T[j].pre;
           T[i].l=T[j].r;
           T[j].r=i;
           T[i].pre=j;
       }
       return T[0].r; //返回根节点序号
   }*/
   // Update from @霜刃未曾试
   //另外一种O(n)构建笛卡尔树的方式，特点是代码很短
   /*
    int cartesian_build(int n)
    {
        for(int i = 1; i <= n; i++)
        {
            int k = i - 1;
            while(tr[k].pri > tr[i].pri) k = tr[k].fat;
            tr[i].son[0] = tr[k].son[1];
            tr[k].son[1] = i;
            tr[i].fat = k;
            tr[tr[i].son[0]].fat = i;//很多人没加这句，父节点关系就会乱掉，
        }//但到目前为止交到OJ上不会发生错误，因为此时这个点已不在最右链上，
        return tr[0].son[1];不会用到其父节点了。
    }
    */
    void inorder(int node) //中序遍历可以还原序列
    {
         if(node==-1) return;
         in_order(T[node].l);
         printf("%d ".T[node].value);
         in_order(T[node].r);
    }
    void level_order(int node)//层次遍历
    {
        queue<int> q;
        q.push(node);
        while (!q.empty())
        {
            int k = q.front();
            q.pop();
            printf("%d ",T[k].value);
            if (T[k].l != -1) q.push(T[k].l);
            if (T[k].r != -1) q.push(T[k].r);
        }
    }
    void LRD(int node)
    {
        if(node == -1) return ;
        dfs(T[node].l);dfs(T[node].r);
        printf("%d ",T[node].value);
    }
int main()
{

    int n;
    while(scanf("%d",&n)!=EOF,n)
    {
        for(int i = 1;i<=n;i++)
            scanf("%lld",&T[i].value),T[i].index = i,T[i].clear();
        //int root2 = ct.build2(n); cout<<"root2's value = "<<root2<<endl;
        pair<int,int> root = ct.build(n);
        int root_value = root.second, root_index = root.first;
        cout<<"root's value = "<<root_value<<endl<<"root's index = "<<root_index<<endl;
        ct.in_order(root_value);
    }
    return 0;
}
```

### #笛卡尔树(lca)与RMQ的关系  RMQ -> LCA
#### [参见2007国家队论文Day2 郭华阳《RMQ与LCA问题》点击查看](http://123.206.188.201/wp-content/uploads/2017/08/3.郭华阳《RMQ与LCA问题》.ppt)
LCA->RMQ（算是改进普通ST+dfs求解lca）有没有人能把我打醒  :confounded:   (Update:已醒,看了论文百科瞎讲不对是我太弱)
[这个$latex O(n)-O(1)$的RMQ就是个分块,懂啦下一篇准备写个求LCA的大杂烩解法包括Tarjan离线,树链剖分,平凡ST+dfs,线性ST+dfs,倍增算法]
区间RMQ即为他们在笛卡尔树上的LCA (此处建议学习$latex O(n)$的±1RMQ而非Sparse Table常见的$latex nlog(n)$)
我好菜 ±1-RMQ(约束RMQ)的$latex <O(n)-O(1)>$算法
求在线ＲＭＱ,根据原数列,建立笛卡尔树,线性规约成LCA问题,LCA再线性规约成约束RMQ,而约束RMQ通过线性在线解法,故整体复杂度$latex O(n)-O(1) $
流程：1.建立笛卡尔树 数组A在$latex [l,r]$ 上的最值等同于在笛卡尔最堆上下标为l,r的节点的LCA的值。
2.LCA转换为规约RMQ
对于规约RMQ采用dfs欧拉序+时间戳+深度数组(Eulur Tour欧拉环游)
规约RMQ的解法分块+每块ST预处理$latex O(n)$ 对于查询分为块内查询+块间查询
对于块内查询由ST可$latex O(1)$得 对于块间类似$latex sqrt(n)$得分块查最值分为三块操作
