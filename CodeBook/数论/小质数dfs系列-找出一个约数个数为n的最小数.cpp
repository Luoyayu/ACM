///小质数的魅力系列
///给一个数n<=1000,求一个最小的正整数,使得它的因子个数为n。
///即给出约数个数求最小满足的整数
///基本原理——建立搜索树，枚举小质因子，小质因子大法好
///CF 27E/ Number With The Given Amount Of Divisors
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
const ULL INF = -1ULL;
int prime[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
int n;
ULL ans;

void dfs(int dept,ULL tmp,int num)
{
    if(num > n) return;
    if(num == n && ans > tmp) ans = tmp;
    for(int i=1;i<=63;i++)
    {
        if(ans / prime[dept] < tmp) break;
        dfs(dept+1,tmp *= prime[dept],num*(i+1));
    }
}
int main()
{
    while(cin>>n)
    {
        ans = INF;
        dfs(0,1,1);
        cout<<((long long )1<<62)+1<<endl;
        cout<<ans<<endl;
    }
    return 0;
}

