///С����������ϵ��
///��һ����n<=1000,��һ����С��������,ʹ���������Ӹ���Ϊn��
///������Լ����������С���������
///����ԭ����������������ö��С�����ӣ�С�����Ӵ󷨺�
///CF 27E/ Number With The Given Amount Of Divisors
#include <iostream>
#include <string.h>
#include <stdio.h>

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

