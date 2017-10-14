#include<bits/stdc++.h>
typedef long long ll;
//题意：给出两两数字 a,b N组，试使用(+,-,*)组合出结果不同的运算，并且输出一种可行的方式
//数据范围n<=2500
/*
input1:
4
1 5
3 3
4 5
-1 -6

output1:
1 + 5 = 6
3 * 3 = 9
4 - 5 = -1
-1 - -6 = 5

input2:
4
-4 2
-4 2
-4 2
-4 2
output2:
impossible

*/
//trick：二分匹配，将<a,b>看成左集合，他们的运算结果看成右集合，问题变成二分图求解一组匹配且没一对<a,b>都对应一个结果
//使用set保存结果去重
using namespace std;
const int maxn = 2500+5;
#define clr(a,b) memset(a,b,sizeof(a));
struct node{
    ll x,y,ans;
}x[maxn];
map<int,string> ANS[maxn]; 
bool vised[maxn];
void init()
{
    clr(ANS,0);
    clr(linker,-1);
}
bool dfs(int u)
{
    for(int i=1;i<=cnt;i++)
    {
        
    }
}
int solve()
{
    int cnt = 0;
}
int main()
{
    int n,tot;
    while(scanf("%d",&n)!=EOF)
    {
        init();
        st.clear();
        tot = 0;
        for(int i=1;i<=n;i++)
        {
            int a,b;scanf("%d%d",&a,&b);
            ll tmp = a+b
            st.insert(tmp);
            ANS[i][tmp]=1;
            tmp = a * b;
            ANS[i][tmp]=1;
            tmp = a-b;
            ANS[i][a-b]=1;
        }
        
    }
}