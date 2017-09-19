//题意:给出一棵树,\sum n<=5e4 ,\sum q<=5e4次询问每次询问query(a,b,k)
//求从a到b的唯一路径上取在路径上次序(from 0)为k的倍数的连续异或值
//思想：分块降复杂度，暴力O(qn)=5e8 
//方法 ：对于询问的k如果大于sqrt(n) 直接暴力跳小于sqrt(n)次
//否则预处理到根的前缀异或和 
#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 5e4 + 7;
int head[maxn];
void init()
{

}
int main()
{
    int n,q;
    while(scanf("%d%d",&n,&q)!=EOF)
    {
        int sz = round(sqrt(n));
        init();
        
}