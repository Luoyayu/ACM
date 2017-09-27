#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//sb树
//法里数列是0到1之间的最简分数的数列每个分数的分母不大于n。
//法里数列从0(写作0/1)到1为止(1/1)
//F_5 = ( 0/1, 1/5, 1/4, 1/3, 2/5, 1/2, 3/5, 2/3, 3/4, 4/5, 1/1)
//法里数列的长度具有递推性比如F6 包含了F5和与6互质的数组成的( 1/6, 5/6)
//所以得出F(n) = F(n-1) + phi(m)
//F(n) = 1+ \sum phi(n)
// 易得 ans = (1 + \sum phi(m))*2 +1
//本题把树从中间剖开可得前半部分就是法里数列
const int maxn = 1000001;
ll phi[maxn];
void phi_table(int n)
{
    phi[1]=1;
    for(int i=2;i<=n;i++) if(!phi[i])
            for(int j=i;j<=n;j+=i)
            {
                if(!phi[j]) phi[j] = j;
                phi[j]=phi[j]/i*(i-1);
            }
}

int main()
{
    int n;
    phi_table(maxn);
    for(int i=2;i<=maxn;i++)
        phi[i]+=phi[i-1];

    while(scanf("%d",&n)!=EOF)
    {
        printf("%lld\n",(phi[n]-1)*2+3);
    }
}