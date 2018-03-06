#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 1e5+7;
int n,m;
///题意：给出N天的预算，安排一个包含M个元素的集合,每个元素是连续的几天,
//定义最大预算为 每个元素和 的最大值
//输入最小的最大预算
/*
7 5
100
400
300
100
500
101
400

exp : [100,400],[300,100],[500],[101],[400]
ans = 500;
*/
//分析：ans 范围在[max,tot]之间 采用二分的思想判断对于mid = (lf+rg)/2是否符合题意,
//如果不合题意的话ans一定在[mid+1,high],否则ans再[low,mid]之间
//二分check 复杂度O(n*logn)
int sp[maxn];
bool judge(int limit)
{
    int num = 1;
    int cur = 0;
    for(int i=0;i<n;i++)
    {
        if(cur + sp[i]<=limit)
            cur+=sp[i];
        else
        {
            num++;
            cur = sp[i];
        }
    }
    return num<=m;
}
int main()
{
    scanf("%d%d",&n,&m);
    int MAX = 0, tot = 0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&sp[i]);
        MAX = max(MAX , sp[i]);
        tot += sp[i];
    }
    int low = MAX, high = tot,mid;
    while(low!=high)
    {
        int mid = (low + high)>>1;
        if(judge(mid))
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    printf("%d\n",low);
}
