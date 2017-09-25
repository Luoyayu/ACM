#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//题意：N>=K 问在N中任意选K个都要满足点亮K个屏幕,求最少的线缆数;
ll n,k;
int main()
{
    while(scanf("%lld%lld",&n,&k)!=EOF)
    {
        cout<<(n-k+1)*k<<endl;//画图得每个源射向(n-k+1)个屏幕即可
    }
    return 0;
}