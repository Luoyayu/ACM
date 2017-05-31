//老队员专题5
//狼如果能走遍所有的洞输出NO。
//设总共有 n个洞, 小狼从P入洞,间隔 m, 则有 mx==P(mod n),x表示入洞的次数(x=1,2,3···),要求P不能取遍(1,2···n-1)
//对于同余式来说 P%gcd(n,m)==0,X方有解,那么可知当gcd(n,m)==1,一定有解,故gcd(n,m)不等于1时 ,同余式存在无解情况
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int p;scanf("%d",&p);
    while(p--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        if(__gcd(n,m)==1)
            cout<<"NO\n";
        else
            cout<<"YES\n";
    }
    return 0;
}
