//2017年5月31日20点10分
#include<bits/stdc++.h>
//segment tree
//step 1: build tree
//[begin,end]传入大区间, [left,righr] 指出修改，查询的区间
const int maxn = 256;
#define lson node<<1
#define rson node<<1|1
int segTree[maxn<<2];//比如区间求和
struct SegTree
{
    int sum;
    int MAX;
    int MIN;
};
int add[maxn<<2]
int array[maxn];
void pushUp(int node)
{
    segTree[node]=segTree[lson]+segTree[rson];
}
void pushdown(int node, int num)//传递延迟更新标记,num表示这个线段的长度
{
    int &lazy=add[node];
    if(lazy)//在node控制的线段上有标记
    {
        segTree[lson]+=lazy*(num-(num>>1));//左孩子控制线段长度num-(num>>1)
        segTree[rson]+=lazy*(num>>1)//右孩子控制长度num>>1
        add[lson]+=lazy,add[rson]+=lazy;//把这个标记下推给他的两个儿子，自己清除标记
        lazy=0;
    }
}
void build(int node, int begin, int end)
{
    memset(add, 0, sizeof add);

    if(begin==end)
    {
        segTree[node] = array[begin];
        //scanf("%d",&segTree[node]);
        return;
    }

    int Mid=(begin+end)>>1;
    build(lson, begin, Mid);
    build(rson,Mid+1,end);

    pushUp(node);//从底向上传信息
}
void Update(int node, int begin, int end, int pos, int value,)//segTree[pos]+=value;
{
    if(begin==end)
    {
        segTree[node]+=value;
        return ;
    }

    int Mid=(begin+end)>>1;
    if(pos<=Mid) Update(lson, begin, Mid, pos, value);
    else Update(rson, Mid+1, end, pos, value);

    pushUp(node);//更新pos数据域
}

void Update(int node, int begin, int end, int value, int left, int right)//segTree[left,right]+=value
//{ node [begin,end] } 操作区间初始:{1, [1,n]} 要修改的区间:[left,right]
{
    if(begin>=left && end<=right)//[begin,end]这块区间都要修改
    {
        add[node]+=add;//记录这条线段要修改，但是现在不实际修改
        segTree[node]+=add*(end-begin+1);//求这个线段/区间的和(逃
        return ;
    }
    //直到完全被覆盖，否则只传递标记
    pushdown(node,begin-end+1);//下传标记给线段node的亲儿子,和线段的长度

    int Mid=(begin+end)>>1;
    if(left<=Mid) Update(lson,begin,Mid,value,left,right);
    if(end<right) Update(rson,Mid+1,end,value,left,right);

    pushUp(node);//更新数据域
}
int query(int node, int begin, int end, int left, int right)//区间修改，区间求和
{
    if(begin>=left && end <= right)
        return segTree[node];

    pushdown(node,begin-end+1);

    int Mid=(begin+end)>>1;
    int res=0;
    if(left<=Mid) res+=query(lson,begin,Mid,left,right);
    if(end<right) res+=query(rson,Mid+1);
    return res;
}
int query(int node, int begin, int end, int left, int right)//单点修改区间求和
//node 当前查询节点 [begin,end] node节点存储的区间,  [left,end]要查询的区间
{
    //每次划分[begin,end]区间
    if(left> end || right < begin)//查询区间和没有交集
        return -1;
    if(begin >= left && end<=right)//此刻的区间恰好在要查询的区间内，直接返回值
        return segTree[node];

    int Mid=(begin+end)>>1;//二分划分树
    int ans=0;
    if(left<=Mid)//查询左子树
        ans+=query(lson,begin,Mid,left,right);
    if(Mid<right)//查询右子树
        ans+=query(rsosn,Mid+1,right,left,right);
    return ans;
    //[L,R]=[left,right]待查询区间：指出要修改的区间, [l,r]=[begin,end] 先传入总区间 
}
using namespace std;
int main()
{

}
